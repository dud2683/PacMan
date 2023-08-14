#include "Renderer.h"


Renderer::Renderer() {
	Init();
}

Renderer::~Renderer() {
}

void Renderer::ResetDisplay() {

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	_zBuffer = 0.0f;
}

void Renderer::AddSprite(float xpos, float ypos, float width, float height, int textureID) {

}

void Renderer::AddTriangle(){
	_test.Use();
}

void Renderer::ReloadShaders()
{
	_test.Reload();
}

void Renderer::Init()
{

}

void Renderer::ParseShaders()
{
	
}
