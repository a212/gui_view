#include "arch01.hpp"

#include <stdio.h>

namespace {
	struct Data {
		Data() { printf("03 constructor\n"); }
		int d = 33;
	};
}

template<>
ScreenInst Screen<Data>::_inst([](auto gui) {
	return (GuiScreen*)new Screen<Data>(gui);
}, 3);
template<>
void Screen<Data>::draw() {
	printf("03: %d %d\n", _gui->i, d);
}
