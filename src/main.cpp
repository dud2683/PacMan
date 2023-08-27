#include "common.h"
#include <iostream>
#include "Window.h"


int main() {
	spdlog::set_pattern(" [%^%l%$] %v --%@");
	DL_INFO("Starting Application");
	Window* window = new Window();
	window->RunGame();
	delete window;
	DL_INFO("Closing Application");
	return 0;
}