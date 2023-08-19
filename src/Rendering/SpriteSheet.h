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
private:
	int _width = 0, _height = 0;
	unsigned char* _data = nullptr;
	UINT _texture;
	
};

