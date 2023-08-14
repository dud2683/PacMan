#pragma once


struct Vertex;
class Sprite {
	Sprite(int x0, int y0, int x1, int y1);

private:
	float Vertex[4];

};

struct Vertex {
	Vertex(float x, float y, float z, float tx, float ty, int textID);

	float pos[3];
	float tex[2];
	int textureID;


	float& x = pos[0];
	float& y = pos[1];
	float& z = pos[2];
	float& tx = tex[0];
	float& ty = tex[1];

};