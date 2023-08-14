#pragma once
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "common.h"
#include "Game/Game.h"
#include "Renderer.h"

class Window {
public:
	Window();
	Window(Window& Window) = delete;
	~Window();

	void RunGame();

private:
	GLFWwindow* _glfwWnd = nullptr;
	std::shared_ptr<Game> _game = nullptr;
	static constexpr int _resolutionMultiplier = 2;
	static constexpr int _baseWidth = 224;
	static constexpr int _baseHeight = 288;
	static constexpr int _screenWidth = _baseWidth * _resolutionMultiplier;
	static constexpr int _screenHeight = _baseHeight * _resolutionMultiplier;
	static constexpr std::chrono::nanoseconds _minTimePerFrame = std::chrono::nanoseconds(16666667);
};