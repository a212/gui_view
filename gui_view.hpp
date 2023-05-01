
class Gui;

class GuiView {
	protected:
		Gui* _gui;
	public:
		enum Id {
			v2 = 2,
			v3,
		};
		GuiView(Gui* gui): _gui(gui) {}
		union InitParam {
			enum Enum {
				None,
			} flags;
			int iVal;
			InitParam(int i) { iVal = i; }
			InitParam(Enum e) { flags = e; }
		};
		virtual ~GuiView() {}
		virtual int getId() { return 0; }
		virtual bool init(InitParam)  { return true; }
		virtual void top()   {}
		virtual void draw()  {}
		virtual void input() {}
		virtual void back()  {}
};

class GuiViewInstSt {
	public:
		using Fn = GuiView* (*)(Gui* _gui);
		GuiViewInstSt(Fn fn, int id);
		int _id;
	protected:
		friend class Gui;
		GuiViewInstSt* _next;
		Fn _fn;
};

template <typename T, int id>
class GuiViewInst : public GuiView {
		static GuiViewInstSt _inst;
		using GuiView::GuiView;
	public:
		int getId() override { return _inst._id; }
};

template <typename T, int id>
GuiViewInstSt GuiViewInst<T, id>::_inst = GuiViewInstSt{[](Gui* gui) -> GuiView* {
	return new T(gui);
}, id};
