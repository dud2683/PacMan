#pragma once

#include "common.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Rendering/Sprite.h"
#include "Rendering/Shader.h"
#include "Rendering/SpriteSheet.h"


struct glfwTexVertex {
	float pos[3];
	float tex[2];
	float& z = pos[2];
};
class Renderer {
public:
	Renderer();
	Renderer(Renderer& renderer) = delete;
	~Renderer();

	void ResetDisplay();

	void AddSprite(Sprite sprite);
	void ReloadShaders();

	void Display();
private:
	void Init();
	void ParseShaders();


	float _zBuffer = 0.0f;
	static constexpr UINT _eboIndexes[] = {
			0, 1, 3,
			1, 2, 3
	};
	
	static constexpr int _maxSprites = 100;
	
	UINT _numSprites = 0;

	glfwTexVertex _buffer[4 * _maxSprites];


	//Shader _sprite{ "src/Rendering/sprite.vtx.glsl", "src/Rendering/sprite.frg.glsl" };
	Shader _spriteShader{ "src/Rendering/test.vtx.glsl", "src/Rendering/test.frg.glsl" };
	SpriteSheet _sheet1{ "src/Rendering/Sprites/Sprite_Sheet" };
};
