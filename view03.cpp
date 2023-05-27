#include "gui.hpp"
#include <stdio.h>

namespace {
	VIEW(3) {
		CTOR
		{ printf("3 constructor\n"); }

		void draw() override;
	};
}

void View::draw()
{
	printf("Hello from 3\n");
}
