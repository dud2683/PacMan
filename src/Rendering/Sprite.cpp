#include "Sprite.h"

Vertex::Vertex(float x, float y, float z, float tx, float ty, int textID) :
	pos{ x, y, z }, tex{ tx, ty }, textureID(textID)
{
}
