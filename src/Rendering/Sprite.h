#pragma once
#include "common.h"
#include "SpriteSheet.h"

struct Sprite {
public:
	std::shared_ptr<SpriteSheet> _spriteSheet;
	int _textureID;
};
