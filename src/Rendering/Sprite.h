#pragma once
#include "common.h"
#include "SpriteSheet.h"

struct SpriteVertex {
	SpriteVertex() = default;
	SpriteVertex(float x, float y);


	float pos[2];

	float& x = pos[0];
	float& y = pos[1];
};

class Sprite {
public:
	Sprite(
		float x0, float y0, float width, float height,
		std::shared_ptr<SpriteSheet> spriteSheet, int textureID
	);
	inline std::pair<float, float> GetPos(int index) 
	{
		return std::make_pair(_vertexes[index].x, _vertexes[index].y);
	}
	inline std::pair<float, float> GetTex(int index) {

		return _spriteSheet->GetTextCoords(_textureID, index);
	}
private:
	SpriteVertex _vertexes[4];
	std::shared_ptr<SpriteSheet> _spriteSheet;
	int _textureID;
};
