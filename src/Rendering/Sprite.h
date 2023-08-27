#pragma once
#include "SpriteSheet.h"

struct Sprite {
public:
	inline const Pos<float> GetTex(int vertex) const { return _spriteSheet->GetTextCoords(_textureID, vertex); }

	std::shared_ptr<SpriteSheet> _spriteSheet;
	int _textureID;
};
