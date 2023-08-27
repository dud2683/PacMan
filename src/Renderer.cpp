#include "common.h"
#include "Renderer.h"


Renderer::Renderer() {
	Init();
	
}

Renderer::~Renderer() {
}

void Renderer::ResetDisplay() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	_numSprites=0;
	_zBuffer = 0.0f;
}

void Renderer::AddSprite(const Sprite& sprite, const Pos<float>& pos0, const Pos<float>& pos1)
{
	auto current = &(_spriteBuffer[_numSprites * 4]);
	current[0] = { {pos0.x, pos0.y, _zBuffer}, {sprite.GetTex(0)} };
	current[1] = { {pos1.x, pos0.y, _zBuffer}, {sprite.GetTex(1)} };
	current[2] = { {pos1.x, pos1.y, _zBuffer}, {sprite.GetTex(2)} };
	current[3] = { {pos0.x, pos1.y, _zBuffer}, {sprite.GetTex(3)} };
	_zBuffer += 1/8.0f;
	_numSprites++;
}

void Renderer::AddSprite(const SpritePos& s)
{
	AddSprite(s.sprite, s.pos0, s.pos1);
}

void Renderer::ReloadShaders()
{
	_spriteShader.Reload();
}

void Renderer::Draw()
{
	_spriteShader.Use();
	glBufferData(GL_ARRAY_BUFFER, sizeof(_spriteBuffer), _spriteBuffer, GL_DYNAMIC_DRAW);
	glDrawElements(GL_TRIANGLES, _numSprites * 6, GL_UNSIGNED_INT, 0);
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
