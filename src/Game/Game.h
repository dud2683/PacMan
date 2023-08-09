#pragma once
#include "Ghost.h"

class Game {
public:
	Game() = default;
	void Run();

private:
	void ProcesInputs();
	void UpdateState();
	void Render();

	Ghost _ghosts;

};
