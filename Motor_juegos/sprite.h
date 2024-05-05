#pragma once
#include <GL/glew.h>
#include "GLTexture.h"
#include <string>
using namespace std;
class Sprite
{
private:
	float x, y; 
	int width, height;
	float vertexData;
	GLuint vboID;
	GLTexture texture;

public:
	Sprite();
	~Sprite();
	void Init(float x, float y, float width, float height, string texturePath);
	void Draw();
};

