#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Rendering/Sprite.h"

class Shader {
public:
	Shader(std::string vtxpath, std::string frgpath);
	Shader(Shader& shader) = delete;
	void Use();
	~Shader();
	void Reload();
	inline void SetAttributes(auto& function) { function(_VAO); }

private:
	void SetAttributes();
	void CompileAndLink();

	UINT _programID;
	UINT _VAO, _VBO, _EBO;

	UINT _indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	std::string _vtxPath, _frgPath;

};