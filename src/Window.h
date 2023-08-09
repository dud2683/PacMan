#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include "common.h"

class Window {
public:
	Window();
	Window(Window& Window) = delete;
	~Window();

	void RunGame();

private:
	GLFWwindow* _glfwWnd = nullptr;

};