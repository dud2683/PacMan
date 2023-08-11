#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 tpos;
layout (location = 2) in int textID;
out vec2 _tpos;
out int _textID;

void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
	_tpos = tpos;
	_textID = textID;
}