#pragma once
#include <GL/glew.h>
using namespace std;
class Sprite
{
private:
	float x, y; 
	int width, height;
	float vertexData;
	GLuint vboID;

public:
	Sprite();
	~Sprite();
	void Init(float x, float y, float width, float height);
	void Draw();
};

