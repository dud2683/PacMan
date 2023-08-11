#pragma once


struct Vertex;
class Sprite {
	Sprite(int x0, int y0, int x1, int y1);

private:
	float Vertex[4];

};

struct Vertex {
	Vertex(float x, float y, float z, float tx, float ty, int textID);

	float x, y, z;
	float tx, ty;
	int textureID;
};