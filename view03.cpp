#include "gui.hpp"
#include <stdio.h>

namespace {
	class View: GuiView {
		static Inst _inst;
	public:
		View(Gui* gui): GuiView(gui)
		{ printf("03: constructor\n"); }
	protected:
		int d = 33;
		bool init(InitParam) override;
		void draw() override;
	};
}

GuiView::Inst View::_inst = createInst<View, 3>();

bool View::init(InitParam param)
{
	if (param.flags & InitParam::None) {
	}
	return true;
}

void View::draw()
{
	printf("03: draw %d\n", d);
}
