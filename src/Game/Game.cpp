#include "common.h"
#include "Game.h"

Game::Game(Renderer* renderer) :
	_renderer(renderer)
{
}

void Game::Update(std::chrono::nanoseconds timestep) {
	UpdateState(timestep);
}


void Game::UpdateState(std::chrono::nanoseconds timestep) {
}

void Game::Render() {
}
