#pragma once
#include "Ghost.h"
#include "Renderer.h"
#include "common.h"

class Game {
public:
	Game(Renderer* renderer);
	void Update(std::chrono::nanoseconds);

private:
	void UpdateState(std::chrono::nanoseconds timestep);
	void Render();

	Ghost _ghosts;
	const Renderer* _renderer;
};
