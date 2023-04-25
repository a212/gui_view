#include "arch01.hpp"

#include <memory>

ScreenInst::ScreenInst(Fn fn, int id)
{
	_next = Gui::_scrFirst;
	Gui::_scrFirst = this;
	_id = id;
	_fn = fn;
}

void Gui::switchScreen(int id)
{
	auto p = _scrFirst;
	while (p) {
		if (p->_id == id) {
			std::unique_ptr<GuiScreen> t(p->_fn(this));
			t->draw();
		}
		p = p->_next;
	}
}

int main()
{
	Gui gui;
	gui.switchScreen(2);
	gui.switchScreen(3);
}
