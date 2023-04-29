
#include "gui_view.hpp"

class Gui {
	public:
		void switchView(int id, GuiView::InitParam param = 0);
	protected:
		int i = 10;

		friend class GuiViewInstSt;
		inline static GuiViewInstSt* _views = nullptr;
};

