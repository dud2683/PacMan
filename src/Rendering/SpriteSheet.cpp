#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::string path){
	int channels;
	stbi_set_flip_vertically_on_load(true);
	_data = stbi_load(path.c_str(), &_width, &_height, &channels, 4);
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(_data);
}

SpriteSheet::~SpriteSheet(){

}

void SpriteSheet::Use(){
	glBindTexture(GL_TEXTURE_2D, _texture);
}

