#pragma once
#include"common.h"
#include "Sprite.h"
#include "SpriteSheet.h"

class SpriteFactory {

	int _width;
	int _height;
	
	static std::vector<std::shared_ptr<SpriteSheet>> _sheets;
};
