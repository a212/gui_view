#include "arch01.hpp"

#include <stdio.h>

namespace {
	struct Data {
		int d = 42;
		~Data() { printf("02: destructor\n"); }
	};
}

template<>
ScreenInst Screen<Data>::_inst([](auto gui) {
	return (GuiScreen*)new Screen<Data>(gui);
}, 2);

template<>
void Screen<Data>::draw() {
	printf("02: %d %d\n", _gui->i, d);
}
