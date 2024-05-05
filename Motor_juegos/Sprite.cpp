#include "Sprite.h"
#include <GL/glew.h>
#include "Vertex.h"
#include <cstddef>
#include "ResourceManager.h"

Sprite::Sprite()
{
	vboID = 0;
}

void Sprite::Init(float x, float y, float width, float height, string texturePath)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	if (vboID==0)
	{
		glGenBuffers(1, &vboID);
	}
	texture = ResourceManager::getTexture(texturePath);
	
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

<<<<<<< Updated upstream
=======
	for (int i = 0; i < 6; i++)
	{
		//	red green blue alpha
		vertexData[i].SetColor(255, 0, 0, 255);
	}
	vertexData[1].SetColor(0, 0, 255, 255);
	vertexData[4].SetColor(0, 255, 0, 255);
	
	vertexData[0].setUV(1.0f, 1.0f);
	vertexData[1].setUV(0.0f, 1.0f);
	vertexData[2].setUV(0.0f, 0.0f);
	vertexData[3].setUV(0.0f, 0.0f);
	vertexData[4].setUV(1.0f, 0.0f);
	vertexData[5].setUV(1.0f, 1.0f);

>>>>>>> Stashed changes
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);// limpia memoria

}

void Sprite::Draw()
{
	glBindTexture(GL_TEXTURE_2D, texture.id);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableVertexAttribArray(0);
	//metodo largo glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	//posicion
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)offsetof(Vertex, position)); //metodo corto
	//color
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex),
		(void*)offsetof(Vertex, color)); // envio de colores
	//UV
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)offsetof(Vertex, uv));
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