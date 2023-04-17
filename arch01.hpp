
class Gui;

class GuiScreen {
	public:
	protected:
		Gui* _gui;
		GuiScreen(Gui* gui): _gui(gui) {}
};

struct ScreenInst {
	ScreenInst* _next;
	typedef GuiScreen* (*Fn)(Gui* _gui);
	Fn _fn;
	ScreenInst(Fn fn);
};

template <typename T>
class Screen : GuiScreen, T {
	public:
		Screen(Gui* gui): GuiScreen(gui) {}
	protected:
		static ScreenInst _inst;
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

