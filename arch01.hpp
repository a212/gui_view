
class Gui;

class GuiScreen {
	public:
		virtual void print() = 0;
};

struct ScreenInst {
	ScreenInst* _next;
	typedef GuiScreen* (*Fn)(Gui* _gui);
	Fn _fn;
	ScreenInst(Fn fn);
};

template <typename T>
class Screen : GuiScreen, T {
		Gui* _gui;
		static ScreenInst _inst;
	public:
		Screen(Gui* gui): _gui(gui) {}
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

