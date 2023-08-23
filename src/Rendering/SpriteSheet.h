#pragma once
#include "common.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
class SpriteSheet
{
public:
	SpriteSheet(std::string path);
	SpriteSheet(SpriteSheet& spriteSheet) = delete;
	~SpriteSheet();

	void Use();
	void inline SetMappings(auto function) { function(&_mapping); }
	inline Pos<float> GetTextCoords(int texID, int vertex)
	{
		if (texID >= _numTextures) {
			DL_ERROR("Texture Not Available");
			return { 0.0f, 0.0f };
		}
		return _mapping[4*texID+vertex];
	}
private:
	int _width = 0, _height = 0;
	int _numTextures = 0;
	UINT _texture;
	static constexpr int maxTexturesPerSheet = 100;
	Pos<float>_mapping[4 *maxTexturesPerSheet];
};

