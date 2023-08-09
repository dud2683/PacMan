#pragma once
#include "common.h"
#include<string>
class Map {
public:
	void LoadFromFile(std::string filename);
private:
	char** layout;
	int _width, _height;
};