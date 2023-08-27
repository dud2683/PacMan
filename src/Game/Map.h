#pragma once
#include<string>
class Map {
public:
	void LoadFromFile(std::string filename);
private:
	char** layout;
	int _width, _height;
};