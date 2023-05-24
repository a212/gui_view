
#include "gui.hpp"

class App {
	Gui gui;
	public:
		void run() {
			gui.switchView(2);
			gui.draw();
			gui.draw();
		}
};

int main()
{
	App app;
	app.run();
}

