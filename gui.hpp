
#include "gui_view.hpp"
#include <vector>
#include <memory>

class Gui {
	public:
		struct Model {
			int a = 33;
			int b = 42;
		};
		const Model& getModel() {
			return _model;
		}
		void switchView3();
	protected:
		friend class GuiViewInstSt;
		inline static GuiViewInstSt* _views = nullptr;
		friend class App;
		void draw();
		void switchView(GuiView::Id id);
		Model _model;
		std::vector<std::unique_ptr<GuiView>> _stack;
		GuiView::Id _nextView = 0;
};

