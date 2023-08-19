#pragma once
#include "common.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Rendering/Sprite.h"

class Shader {
public:
	Shader(std::string vtxpath, std::string frgpath);
	Shader(Shader& shader) = delete;
	void Use();
	~Shader();
	void SetAttributes();
	void Reload();

private:
	void CompileAndLink();

	UINT _programID;
	UINT _VAO, _VBO, _EBO;

	UINT _indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	Vertex _vertexes[4] = {
		{1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1},
		{1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1 },
		{-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1},
		{-1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1}
	};

	std::string _vtxPath, _frgPath;

};