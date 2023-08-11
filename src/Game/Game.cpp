#include "common.h"
#include "Game.h"

Game::Game() :
	_renderer(std::make_unique<Renderer>())
{

}

void Game::Update(std::chrono::nanoseconds timestep) {
	UpdateState(timestep);

}


void Game::UpdateState(std::chrono::nanoseconds timestep) {
}

void Game::Render() {
	_renderer->AddSprite(0.0f, 0.0f, 1.0f, 1.0f, 0);

	_renderer->UpdateDisplay();
}
