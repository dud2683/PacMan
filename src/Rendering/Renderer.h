#pragma once

#include "common.h"

class Renderer {
public:
	Renderer();
	Renderer(Renderer& renderer) = delete;
	~Renderer();

};