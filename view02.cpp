#include "gui.hpp"
#include <stdio.h>

namespace {
	struct View: GuiViewInst<View, GuiView::v2> {
		using GuiViewInst::GuiViewInst;
		~View() { printf("%02d: destructor\n", getId()); }

		int d = 42;

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
	_gui->switchView(v3);
}
