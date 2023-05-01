
#include "gui_view.hpp"

class Gui {
	public:
		void switchView(GuiView::Id id, GuiView::InitParam param = 0);
	protected:
		friend class GuiViewInstSt;
		inline static GuiViewInstSt* _views = nullptr;
};

