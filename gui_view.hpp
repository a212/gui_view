
class Gui;

#define VIEW(id) struct View: GuiViewInst<View, id>
#define CTOR View(Gui* gui): GuiViewInst(gui)

class GuiView {
	protected:
		Gui* _gui;
	public:
		typedef int Id;
		GuiView(Gui* gui): _gui(gui) {}
		virtual ~GuiView() {}
		virtual Id getId() {
			return 0;
		}
		virtual bool init()  {
			return true;
		}
		virtual void top()   {}
		virtual void draw()  {}
		virtual void input() {}
		virtual void back()  {}
};

class GuiViewInstSt {
	public:
		using Fn = GuiView* (*)(Gui* _gui);
		GuiViewInstSt(Fn fn, GuiView::Id id);
		GuiView::Id _id;
	protected:
		friend class Gui;
		GuiViewInstSt* _next;
		Fn _fn;
};

template <typename T, GuiView::Id id>
class GuiViewInst : public GuiView {
		static GuiViewInstSt _inst;
		using GuiView::GuiView;
	public:
		GuiView::Id getId() override { return _inst._id; }
};

template <typename T, GuiView::Id id>
GuiViewInstSt GuiViewInst<T, id>::_inst = GuiViewInstSt{[](Gui* gui) -> GuiView* {
	return new T(gui);
}, id};
