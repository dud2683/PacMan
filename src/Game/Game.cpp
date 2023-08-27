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
	LoadSprites();
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
	for (const auto& element : _background) {
		_renderer->AddSprite(element);
	}
	_renderer->Draw();
}

void Game::LoadSprites(){
	std::shared_ptr<SpriteSheet> sheet1 = std::make_shared<SpriteSheet>("src/Rendering/Sprites/Sprite_Sheet");
	SpritePos grid = { {sheet1, 0}, {-0.8f, -0.8f}, {0.8f, 0.8f} };
	_background.push_back(grid);
}
