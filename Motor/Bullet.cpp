#include "Bullet.h"
#include <xiosbase>


Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::init(glm::vec2 position, glm::vec2 direction, float speed)
{
	color.set(255, 255, 0, 255);
	this->direction = direction;
	this->speed = speed;
	this->position = position;

	srand(time(NULL));
	currentFrame = 0;
	valDirection = 1;
	animationSpeed = 0;
	timeExplo = 0;
	divisionFrame = 4;
	animation = "Images/bomba.png";
}

void Bullet::draw()
{
	spritebatch.init();
	spritebatch.begin();

	//glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f); // por defecto la textura completa
	glm::vec4 uvRect(currentFrame * (1.0f / 4), 0.0f, valDirection * (1.0f / 4), 1.0f);


	glm::vec4 destRect(position.x, position.y, AGENT_WIDTH/2, AGENT_WIDTH/2);
	spritebatch.draw(destRect, uvRect, ResourceManager::getTexture(animation).id, 0.0f, color);
	spritebatch.end();
	spritebatch.renderBatch();
}

void Bullet::update()
{
	position += direction * speed;
	animationSpeed++;
	if (animationSpeed == 8) {
		currentFrame = (currentFrame + 1) % 4;
		animationSpeed = 0;
	}

	timeExplo++;
	if (timeExplo == 54)
	{
		animation = "Images/Explosion.png";
	}

	if (timeExplo == 90)
	{
		/*for (int i = 0; i < mainGame.bullets.size(); i++)
		{
			delete this;
			mainGame.bullets[i] = mainGame.bullets.back();
			mainGame.bullets.pop_back();
		}*/
	}
}

bool Bullet::iSForDestroy(vector<string>& levelData)
{
	if (collideWithLevel(levelData))
	{
		return true;
	}
	return false;
}

int Bullet::getTimeExplo()
{
	return timeExplo;
}


