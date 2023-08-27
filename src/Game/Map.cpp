#include "common.h"
#include "Map.h"

void Map::LoadFromFile(std::string filename)
{
	try {
		std::ifstream map_file;
		map_file.open(filename);
		std::string line;

		std::getline(map_file, line);
		std::string number;
		for (const char c : line) {
			if (c == ',') {
				_width = std::stoi(number);
				number = std::string();
				continue;
			}

			if (std::isdigit(c))
				number.push_back(c);
			else
				throw(std::exception());
		}
		_height = std::stoi(number);

	}
	catch (std::exception e) {
	}
}
