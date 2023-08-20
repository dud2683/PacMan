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
	inline std::pair<float, float> GetTextCoords(int texID, int vertex)
	{
		if (texID >= _mapping.size()) {
			DL_ERROR("Texture Not Available");
			return std::make_pair(0.0f, 0.0f);
		}
		return _mapping[texID][vertex];
	}
private:
	int _width = 0, _height = 0;
	unsigned char* _data = nullptr;
	UINT _texture;
	std::vector<std::pair<float, float>[4]> _mapping;
	
};

