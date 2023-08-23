#pragma once
#include "common.h"
#include "Entity.h"


class Player : public Entity {
	Player();
public:
	void Move();
};