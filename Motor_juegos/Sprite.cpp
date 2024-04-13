#include "Sprite.h"
#include <GL/glew.h>
#include "Vertex.h"
#include <cstddef>

Sprite::Sprite()
{
	vboID = 0;
}

void Sprite::Init(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	if (vboID==0)
	{
		glGenBuffers(1, &vboID);
	}

	
	//metodo largo de pintar datos
	/*float vertexData[12];
	vertexData[0] = x + height;
	vertexData[1] = y + width;
	vertexData[2] = x;
	vertexData[3] = y + width;
	vertexData[4] = x;
	vertexData[5] = y;

	vertexData[6] = x;
	vertexData[7] = y;
	vertexData[8] = x + height;
	vertexData[9] = y;
	vertexData[10] = x + height;
	vertexData[11] = y + width;*/

	//metodo corto
	Vertex vertexData[6];
	vertexData[0].SetPosition(x + height, y + width);
	vertexData[1].SetPosition(x, y + width);
	vertexData[2].SetPosition(x, y);
	vertexData[3].SetPosition(x, y);
	vertexData[4].SetPosition(x + height, y);
	vertexData[5].SetPosition(x + height, y + width);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);// limpia memoria

}

void Sprite::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableVertexAttribArray(0);
	//metodo largo glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)offsetof(Vertex, position)); //metodo corto
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex),
		(void*)offsetof(Vertex, color)); // envio de colores
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Sprite::~Sprite()
{
	if (vboID != 0) {
		glDeleteBuffers(1, &vboID);
	}
}