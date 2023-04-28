
#include "gui_view.hpp"

class Gui {
	public:
		void switchView(int id, GuiView::InitParam param = 0);
	protected:
		int i = 10;

		friend class GuiView::Inst;
		inline static GuiView::Inst* _scrFirst = nullptr;
};

