#include "common.h"
#include "Game.h"

void Game::Run() {
	while (true) {
		ProcesInputs();
		UpdateState();
		Render();
	}
}

void Game::ProcesInputs() {
}

void Game::UpdateState() {
}

void Game::Render() {
}
