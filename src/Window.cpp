#include "Window.h"

Window::Window() {
	if (!glfwInit())
	{
		DL_ERROR("GLFW init failed!");
	}
	_glfwWnd = glfwCreateWindow(640, 480, "PacMan", NULL, NULL);
}

Window::~Window() {

	glfwDestroyWindow(_glfwWnd);
	glfwTerminate();
}

void Window::RunGame() {
	while (true) {}
}
