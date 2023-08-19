#version 330 core
out vec4 FragColor;
in vec2 _tx;
uniform sampler2D text;
void main(){
	FragColor = texture(text, vec2((_tx.x+2.0)/3.0, _tx.y));
}