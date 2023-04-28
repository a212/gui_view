#include "arch01.hpp"
#include <stdio.h>

namespace {
	class Scr: GuiScreen {
		static Inst _inst;
	public:
		Scr(Gui* gui): GuiScreen(gui)
		{ printf("03: constructor\n"); }
	protected:
		int d = 33;
		bool init(InitParam) override;
		void draw() override;
	};
}

GuiScreen::Inst Scr::_inst = createInst<Scr, 3>();

bool Scr::init(InitParam param)
{
	if (param.flags & InitParam::None) {
	}
	return true;
}

void Scr::draw()
{
	printf("03: draw %d\n", d);
}

