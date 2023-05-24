#include "gui.hpp"
#include <stdio.h>

namespace {
	struct View: GuiViewInst<View, 2> {
		using GuiViewInst::GuiViewInst;
		~View() { printf("%02d: destructor\n", getId()); }

		void draw() override;
	};
}

void View::draw()
{
	printf("%02d: draw %d\n", getId(), _gui->getModel().b);
	_gui->switchView3();
}
