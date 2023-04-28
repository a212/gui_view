#include "arch01.hpp"
#include <stdio.h>

namespace {
	class Scr: GuiScreen {
		static Inst _inst;
	public:
		Scr(Gui* gui): GuiScreen(gui) {}
	protected:
		~Scr() { printf("02: destructor\n"); }
		int d = 42;
		bool init(InitParam) override;
		void draw() override;
	};
}

GuiScreen::Inst Scr::_inst = createInst<Scr, 2>();

bool Scr::init(InitParam param)
{
	if (param.flags & InitParam::None) {
	}
	return true;
}

void Scr::draw()
{
	printf("02: draw %d\n", d);
}

