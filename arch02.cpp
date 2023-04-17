#include "arch01.hpp"

namespace {
	struct Data {
		void print() {
		}
		int d;
	};
}

template<>
ScreenInst Screen<Data>::_inst([](auto gui) {
	return (GuiScreen*)new Screen<Data>(gui);
});
