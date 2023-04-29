#include "gui.hpp"
#include <stdio.h>

namespace {
	struct View: GuiViewInst<View, 3> {
		View(Gui* gui): GuiViewInst(gui)
		{ printf("%02d: constructor\n", getId()); }

		int d = 33;

		bool init(InitParam) override;
		void draw() override;
	};
}

bool View::init(InitParam param)
{
	if (param.flags & InitParam::None) {
	}
	return true;
}

void View::draw()
{
	printf("%02d: draw %d\n", getId(), d);
}
