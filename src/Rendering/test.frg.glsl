#version 330 core
out vec4 FragColor;
in vec2 _tx;
void main(){
	FragColor = vec4 (_tx, 1.0, 1.0);
}