#pragma once

#include "common.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Rendering/Sprite.h"

class Renderer {
public:
	Renderer();
	Renderer(Renderer& renderer) = delete;
	~Renderer();

	void UpdateDisplay();

	void AddSprite(float xpos, float ypos, float width, float height, int textureID);

private:
	void Init();
	void ParseShaders();


	float _zBuffer = 0.0f;
	static constexpr UINT _eboIndexes[] = {
			0, 1, 3,
			1, 2, 3
	};

	const std::string _shaders[2] = {
		"src/Rendering/sprite.vtx.glsl",
		"src/Rendering/sprite.vtx.glsl"
	};


};