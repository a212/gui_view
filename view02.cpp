#include "gui.hpp"
#include <stdio.h>

namespace {
	VIEW(2) {
		CTOR {}
		~View() { printf("2 destructor\n"); }

		void draw() override;
	};
}

void View::draw()
{
	printf("Hello from 2\n");
	_gui->switchView3();
}
