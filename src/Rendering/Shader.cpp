#include "Shader.h"

Shader::Shader(std::string vtxpath, std::string frgpath):
_vtxPath(vtxpath), _frgPath(frgpath)
{
	CompileAndLink();
	SetAttributes();

}

void Shader::Use()
{
	glUseProgram(_programID);
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Shader::~Shader(){

}

void Shader::CompileAndLink(){
	auto compileShader = [this](const std::string& path, UINT shaderType) {
		std::string output;
		DL_INFO("Opening file " + path);
		std::ifstream file(path.c_str());

		std::string line;
		while (std::getline(file, line)) {
			output.append(line + '\n');
		}

		const char* s = output.c_str();

		DL_INFO("Compiling shader:\n" + output);
		UINT shaderID = glCreateShader(shaderType);
		glShaderSource(shaderID, 1, &s, NULL);
		glCompileShader(shaderID);
		GL_SHADER_CHECK(shaderID);
		glAttachShader(_programID, shaderID);
	};

	_programID = glCreateProgram();

	compileShader(_vtxPath, GL_VERTEX_SHADER);
	compileShader(_frgPath, GL_FRAGMENT_SHADER);


	DL_INFO("Linking shaders");
	glLinkProgram(_programID);
	int success;
	glGetProgramiv(_programID, GL_LINK_STATUS, &success);

	if (!success)
		DL_ERROR("Failed to link shaders");
	else
		DL_INFO("SHADER compiled succesfully");
}

void Shader::SetAttributes(){
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glGenBuffers(1, &_EBO);

	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_DYNAMIC_DRAW);

	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertexes), _vertexes, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof Vertex, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof Vertex, (void*)offsetof(Vertex, tx));
	glEnableVertexAttribArray(1);

}

void Shader::Reload(){
	glDeleteProgram(_programID);
	CompileAndLink();
}
