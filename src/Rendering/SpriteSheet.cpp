#include "common.h"
#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::string path){
	int channels;
	std::string image = path + ".png";
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(image.c_str(), &_width, &_height, &channels, 4);
	if (data == nullptr) {
		DL_ERROR("No spritesheet found for " + path);
	}
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

	std::string mappings = path + ".csv";
	std::fstream file(mappings);
	if (file.fail()) {
		DL_ERROR("No mapping found for " + path);
	}
	std::string line;
	
	while (std::getline(file, line)) {
		std::string num = std::string();
		int values[5]; // texIndex, x0, y0, x1, y1
		int vIndex = 0;

		int i = 0;
		while (i < line.size()) {
			if (line[i] == ',') {
				values[vIndex++] = std::stoi(num);
				num = std::string();
			}
			else if (!std::isdigit(line[i]))
				DL_ERROR("INVALID csv");
			else
				num.push_back(line[i]);
			i++;
		}
		values[vIndex] = std::stoi(num);
		int& texIndex = values[0];
		int& x0 = values[1];
		int& y0 = values[2];
		int& x1 = values[3];
		int& y1 = values[4];

		float iWidth = 1/(static_cast<float>(_width));
		float iHeight = 1/(static_cast<float>(_height));

		
		_mapping[4*texIndex] =   {iWidth * x0, iHeight * y0};
		_mapping[4*texIndex+1] = {iWidth * x1, iHeight * y0};
		_mapping[4*texIndex+2] = {iWidth * x1, iHeight * y1};
		_mapping[4*texIndex+3] = {iWidth * x0, iHeight * y1};
		_numTextures++;
	}

}

SpriteSheet::~SpriteSheet(){

}

void SpriteSheet::Use(){
	glBindTexture(GL_TEXTURE_2D, _texture);
}

