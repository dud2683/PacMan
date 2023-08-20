#include "Sprite.h"

Sprite::Sprite(float x0, float y0, float width, float height,
	std::shared_ptr<SpriteSheet> spriteSheet, int textureID) :
	_vertexes{
		{x0, y0},
		{x0, y0+height},
		{x0+width, y0+height},
		{x0+width, y0}
	},
	_spriteSheet(spriteSheet), _textureID(textureID)
{
}


SpriteVertex::SpriteVertex(float x, float y) :
	pos{x, y}
{
}