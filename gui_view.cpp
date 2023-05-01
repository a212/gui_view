#include "gui.hpp"

#include <memory>

GuiViewInstSt::GuiViewInstSt(Fn fn, int id)
{
	_next = Gui::_views;
	Gui::_views = this;
	_id = id;
	_fn = fn;
}

void Gui::switchView(GuiView::Id id, GuiView::InitParam param)
{
	auto p = _views;
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
	gui.switchView(GuiView::v2);
}
