#pragma once

#include "common.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Rendering/Sprite.h"
#include "Rendering/Shader.h"
#include "Rendering/SpriteSheet.h"

class Renderer {
public:
	Renderer();
	Renderer(Renderer& renderer) = delete;
	~Renderer();

	void ResetDisplay();

	void AddSprite(float xpos, float ypos, float width, float height, int textureID);
	void AddTriangle();
	void ReloadShaders();
private:
	void Init();
	void ParseShaders();


	float _zBuffer = 0.0f;
	static constexpr UINT _eboIndexes[] = {
			0, 1, 3,
			1, 2, 3
	};

	//Shader _sprite{ "src/Rendering/sprite.vtx.glsl", "src/Rendering/sprite.frg.glsl" };
	Shader _test{ "src/Rendering/test.vtx.glsl", "src/Rendering/test.frg.glsl" };
	SpriteSheet _sheet1{ "src/Rendering/Sprite_Sheet2.png" };
};