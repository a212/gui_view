#include "gui.hpp"


GuiViewInstSt::GuiViewInstSt(Fn fn, int id)
{
	_next = Gui::_views;
	Gui::_views = this;
	_id = id;
	_fn = fn;
}

void Gui::switchView3()
{
	switchView(3);
}

void Gui::switchView(GuiView::Id id)
{
	_nextView = id;
}

void Gui::draw()
{
	if (_nextView) {
		auto p = _views;
		while (p) {
			if (p->_id == _nextView) {
				std::unique_ptr<GuiView> t(p->_fn(this));
				if (t->init()) {
					_stack.emplace_back(std::move(t));
				}
				break;
			}
			p = p->_next;
		}
		_nextView = 0;
	}
	if (!_stack.empty()) {
		_stack.back()->draw();
	}
}

