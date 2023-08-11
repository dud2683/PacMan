#include "Window.h"
void GLAPIENTRY
MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	DL_ERROR(*message);
}

Window::Window() {
	if (!glfwInit()) {
		DL_ERROR("GLFW init failed!");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	_glfwWnd = glfwCreateWindow(_screenWidth, _screenHeight, "PacMan", NULL, NULL);
	glfwMakeContextCurrent(_glfwWnd);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		DL_ERROR("Failed to initialize GLAD");
	}

	_game = std::make_unique<Game>();

}

Window::~Window() {

	glfwDestroyWindow(_glfwWnd);
	glfwTerminate();
}

void Window::RunGame() {

	typedef std::chrono::high_resolution_clock Clock;
	using namespace std::chrono_literals;

	std::chrono::nanoseconds delta = 0ns;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	bool processedFrame = false;

	while (!glfwWindowShouldClose(_glfwWnd)) {
		//We only have to worry about the target computer being to fast.
		end = Clock::now();
		if (delta >= _minTimePerFrame) {
			glfwSwapBuffers(_glfwWnd);
			glfwPollEvents();
			_game->Update(delta);
			processedFrame = true;
		}
		if (processedFrame) {
			start = Clock::now();
			processedFrame = false;
		}

		delta = end - start;
	}
}
