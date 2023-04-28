
class Gui;

class GuiView {
	protected:
		Gui* _gui;
		friend class Gui;
		class Inst {
			public:
				using Fn = GuiView* (*)(Gui* _gui);
				Inst(Fn fn, int id);
			protected:
				friend class Gui;
				Inst* _next;
				int _id;
				Fn _fn;
		};
	public:
		template <typename T, int id>
		static auto createInst() {
			return Inst([](Gui* gui) {
				return (GuiView*)new T(gui);
			}, id);
		}
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
		virtual bool init(InitParam)  { return true; }
		virtual void top()   {}
		virtual void draw()  {}
		virtual void input() {}
		virtual void back()  {}
};
