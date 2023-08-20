#include "Renderer.h"


Renderer::Renderer() {
	Init();
	
}

Renderer::~Renderer() {
}

void Renderer::ResetDisplay() {

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	_numSprites=0;
	_zBuffer = 0.0f;
}


void Renderer::AddSprite(Sprite sprite)
{
	glfwTexVertex* cur = &(_buffer[_numSprites]);
	for (int i = 0; i < 4; i++) {
		cur[i].pos[0] = sprite.GetPos(i).first;
		cur[i].pos[1] = sprite.GetPos(i).second;
		cur[i].z = _zBuffer;
		std::pair<float, float> textCoords = sprite.GetTex(i);
		cur[i].tex[0] = textCoords.first;
		cur[i].tex[1] = textCoords.second;
	}
	_numSprites++;
}

void Renderer::ReloadShaders()
{
	_spriteShader.Reload();
}

void Renderer::Display()
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(_buffer), _buffer, GL_DYNAMIC_DRAW);
}

void Renderer::Init()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof glfwTexVertex, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof glfwTexVertex, (void*)(offsetof(glfwTexVertex, tex)));
	glEnableVertexAttribArray(1);
}

void Renderer::ParseShaders()
{
	
}
