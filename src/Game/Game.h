#pragma once
#include "Ghost.h"
#include "Renderer.h"
#include "common.h"

class Game {
public:
	Game(GLFWwindow* wnd);
	void Update(std::chrono::nanoseconds);
	void ReloadShaders();

private:
	void UpdateState(std::chrono::nanoseconds timestep);
	void Render();
	void LoadSprites();

	std::vector<std::unique_ptr<Entity>> _ents;
	const std::unique_ptr<Renderer> _renderer;	
};
