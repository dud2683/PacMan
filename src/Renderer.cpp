#include "Renderer.h"

#define GL_SHADER_CHECK(shaderID) \
	{\
	int  success;\
	char infoLog[512];\
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);\
	if (!success) {\
		int maxLength;\
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);\
		DL_ERROR("SHADER compilation failed");\
		std::vector<char> errorLog(maxLength);\
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);\
		const std::string str(errorLog.begin(), errorLog.end());\
		DL_ERROR(str);\
	}\
	}\


Renderer::Renderer() {
	Init();
}

Renderer::~Renderer() {
}

void Renderer::UpdateDisplay() {

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	_zBuffer = 0.0f;

}

void Renderer::AddSprite(float xpos, float ypos, float width, float height, int textureID) {

	UINT EBO, VAO;

	Vertex vertices[] = {
		{xpos, ypos, _zBuffer, 0.0f, 0.0f, textureID},
		{xpos + width, ypos, _zBuffer, 1.0f, 0.0f, textureID},
		{xpos, ypos + height, _zBuffer, 0.0f, 1.0f, textureID},
		{xpos + width, ypos + height, _zBuffer, 1.0f, 1.0f, textureID},
	};
	_zBuffer += 0.1;


	glGenBuffers(1, &VAO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof vertices, &vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof _eboIndexes, _eboIndexes, GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::Init()
{
	ParseShaders();
}

void Renderer::ParseShaders()
{
	auto getShaderStrings = [](const std::string path, std::string& output) {
		DL_INFO("Opening file " + path);
		std::ifstream file(path.c_str());

		std::string line;
		while (std::getline(file, line)) {
			output.append(line + '\n');
		}
	};
	auto a = glGetString(GL_VERSION);
	DL_WARN(*a);
	for (std::string path : _shaders) {
		std::string output;
		getShaderStrings(path, output);

		const char* s = output.c_str();

		DL_INFO("Compiling shader: " + path);
		UINT shaderID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(shaderID, 1, &s, NULL);
		glCompileShader(shaderID);
		GL_SHADER_CHECK(shaderID);
	}

}
