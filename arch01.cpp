#include "arch01.hpp"

ScreenInst::ScreenInst(Fn fn)
{
	_next = Gui::_scrFirst;
	Gui::_scrFirst = this;
	_fn = fn;
}

void Gui::printScreens()
{
	auto p = _scrFirst;
	while (p) {
		auto t = p->_fn(this);
		t->print();
		p = p->_next;
	}
}

int main()
{
	Gui gui;
	gui.printScreens();
}
