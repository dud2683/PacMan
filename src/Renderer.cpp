#include "Renderer.h"

Renderer::Renderer() {
}

Renderer::~Renderer() {
}

void Renderer::UpdateDisplay() {

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

}

void Renderer::AddSprite(int xpos, int ypos, int width, int height, int textureID) {

}
