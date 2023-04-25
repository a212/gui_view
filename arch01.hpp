
class Gui;

class GuiScreen {
	protected:
		Gui* _gui;
	public:
		GuiScreen(Gui* gui): _gui(gui) {}
		virtual ~GuiScreen() {}
		virtual void draw() = 0;
};

class ScreenInst {
	public:
		using Fn = GuiScreen* (*)(Gui* _gui);
		ScreenInst(Fn fn, int id);
	protected:
		friend class Gui;
		ScreenInst* _next;
		int _id;
		Fn _fn;
};

template <typename T>
class Screen : GuiScreen, T {
		static ScreenInst _inst;
	public:
		Screen(Gui* gui): GuiScreen(gui) {}
		void draw() override;
};

class Gui {
	public:
		void switchScreen(int id);
	protected:
		int i = 10;

		template <typename T>
		friend class Screen;
		friend class ScreenInst;
		inline static ScreenInst* _scrFirst = nullptr;
};

