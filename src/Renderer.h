#pragma once

#include "common.h"
#include "GLFW/glfw3.h"

class Renderer {
public:
	Renderer();
	Renderer(Renderer& renderer) = delete;
	~Renderer();

	void UpdateDisplay();

	void AddSprite(int xpos, int ypos, int width, int height, int textureID);

private:


};