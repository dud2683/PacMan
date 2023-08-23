#include "common.h"
#include "Game.h"

Game::Game(GLFWwindow* wnd) :
	_renderer(std::make_unique<Renderer>())
{
	glfwSetWindowUserPointer(wnd, this);
	auto callback = [](GLFWwindow* wnd, int key, int scancode, int action, int mods) {
	
		auto& self = *static_cast<Game*>(glfwGetWindowUserPointer(wnd));
		
		if (key == GLFW_KEY_R && action == GLFW_PRESS) {
			self.ReloadShaders();
		}
			
	
	};
	glfwSetKeyCallback(wnd, callback);
}

void Game::Update(std::chrono::nanoseconds timestep) {
	UpdateState(timestep);
}

void Game::ReloadShaders()
{
	_renderer->ReloadShaders();
}


void Game::UpdateState(std::chrono::nanoseconds timestep) {
	Render();

}

void Game::Render() {
	_renderer->ResetDisplay();
}

void Game::LoadSprites(){
	auto sheet1 = std::make_shared<SpriteSheet>("src/Rendering/Sprites/SpriteSheet");

}
