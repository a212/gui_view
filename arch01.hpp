
class Gui;

class GuiScreen {
	public:
		Gui* _gui;
		GuiScreen(Gui* gui) { _gui = gui; }
		virtual ~GuiScreen() {}
		virtual void print() {}
};

class ScreenInst {
	public:
	ScreenInst* _next;
	typedef GuiScreen* (*Fn)(Gui* _gui);
	Fn _fn;
	ScreenInst(Fn fn);
};

template <typename T>
class Screen : GuiScreen, T {
		static ScreenInst _inst;
	public:
		Screen(Gui* gui): GuiScreen(gui) {}
		void print() override;
};

class Gui {
	public:
		void printScreens();
	protected:
		int i = 10;

		template <typename T>
		friend class Screen;

		friend class ScreenInst;

		inline static ScreenInst* _scrFirst = nullptr;
};

