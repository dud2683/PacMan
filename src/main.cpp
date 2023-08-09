#include <iostream>
#include "Window.h"
#include "common.h"


int main() {
	spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
	DL_INFO("Starting Application");
	Window* window = new Window();
	window->RunGame();
	delete window;
	DL_WARN("Closing Application");
	return 0;
}