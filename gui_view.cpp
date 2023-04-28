#include "gui.hpp"

#include <memory>

GuiView::Inst::Inst(Fn fn, int id)
{
	_next = Gui::_scrFirst;
	Gui::_scrFirst = this;
	_id = id;
	_fn = fn;
}

void Gui::switchView(int id, GuiView::InitParam param)
{
	auto p = _scrFirst;
	while (p) {
		if (p->_id == id) {
			std::unique_ptr<GuiView> t(p->_fn(this));
			t->init(param);
			t->draw();
			break;
		}
		p = p->_next;
	}
}

int main()
{
	Gui gui;
	gui.switchView(2);
	gui.switchView(3);
}
