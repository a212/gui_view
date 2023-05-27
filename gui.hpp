
#include "gui_view.hpp"
#include <vector>
#include <memory>

class Gui {
	public:
		void switchView3();
	protected:
		friend class GuiViewInstSt;
		inline static GuiViewInstSt* _views = nullptr;
		friend class App;
		void draw();
		void switchView(GuiView::Id id);
		std::vector<std::unique_ptr<GuiView>> _stack;
		GuiView::Id _nextView = 0;
};

