#include "gui.hpp"
#include <stdio.h>

namespace {
	struct View: GuiViewInst<View, 3> {
		View(Gui* gui): GuiViewInst(gui)
		{ printf("%02d: constructor\n", getId()); }

		void draw() override;
	};
}

void View::draw()
{
	printf("%02d: draw %d\n", getId(), _gui->getModel().a);
}
