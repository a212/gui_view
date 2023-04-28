#include "gui.hpp"
#include <stdio.h>

namespace {
	class View: GuiView {
		static Inst _inst;
	public:
		View(Gui* gui): GuiView(gui) {}
	protected:
		~View() { printf("02: destructor\n"); }
		int d = 42;
		bool init(InitParam) override;
		void draw() override;
	};
}

GuiView::Inst View::_inst = createInst<View, 2>();

bool View::init(InitParam param)
{
	if (param.flags & InitParam::None) {
	}
	return true;
}

void View::draw()
{
	printf("02: draw %d\n", d);
}
