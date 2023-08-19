#version 330 core
in vec2 texPos;
in int textID;
out vec4 FragColor;

uniform sampler2D ourTexture;

void main(){
	FragColor = texture(ourTexture, texPos);
}