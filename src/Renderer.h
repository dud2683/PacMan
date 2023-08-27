#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Rendering/Sprite.h"
#include "Rendering/Shader.h"
#include "Rendering/SpriteSheet.h"


struct glfwTexVertex {
	glfwTexVertex& operator= (const glfwTexVertex& other) {
		pos[0] = other.pos[0];
		pos[1] = other.pos[1];
		pos[2] = other.pos[2];
		tex = other.tex;
		return *this;
	}
	float pos[3];
	Pos<float> tex;
	float& z = pos[2];
};

struct SpritePos {
	Sprite sprite;
	Pos<float> pos0;
	Pos<float> pos1;
};

class Renderer {
public:
	Renderer();
	Renderer(Renderer& renderer) = delete;
	~Renderer();

	void ResetDisplay();

	void AddSprite(const Sprite& sprite, const Pos<float>& pos0, const Pos<float>& pos1);
	void AddSprite(const SpritePos& s);
	void ReloadShaders();

	void Draw();
private:
	void Init();
	void ParseShaders();


	float _zBuffer = 0.0f;
	static constexpr UINT _eboIndexes[] = {
			0, 1, 2,
			1, 2, 3
	};
	
	static constexpr int _maxSprites = 100;
	
	UINT _numSprites = 0;

	glfwTexVertex _spriteBuffer[4 * _maxSprites];
	Shader _spriteShader{ "src/Rendering/test.vtx.glsl", "src/Rendering/test.frg.glsl" };
};
