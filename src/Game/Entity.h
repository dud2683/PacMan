#pragma once
#include "common.h"
#include "Rendering/Sprite.h"

class Entity{
public:


private:
	Pos<int> _mapPosition;
	std::vector<Sprite> _sprites;
	std::vector<std::vector<int>> _animations;
	int _animationState;
};

