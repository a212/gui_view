
class Gui;

class GuiScreen {
	protected:
		Gui* _gui;
		friend class Gui;
		class Inst {
			public:
				using Fn = GuiScreen* (*)(Gui* _gui);
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
				return (GuiScreen*)new T(gui);
			}, id);
		}
		GuiScreen(Gui* gui): _gui(gui) {}
		union InitParam {
			enum Enum {
				None,
			} flags;
			int iVal;
			InitParam(int i) { iVal = i; }
			InitParam(Enum e) { flags = e; }
		};
		virtual ~GuiScreen() {}
		virtual bool init(InitParam)  { return true; }
		virtual void top()   {}
		virtual void draw()  {}
		virtual void input() {}
		virtual void back()  {}
};

class Gui {
	public:
		void switchScreen(int id, GuiScreen::InitParam param = 0);
	protected:
		int i = 10;

		friend class GuiScreen::Inst;
		inline static GuiScreen::Inst* _scrFirst = nullptr;
};
