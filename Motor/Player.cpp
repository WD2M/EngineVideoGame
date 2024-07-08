#include "Player.h"
#include <SDL/SDL.h>
#include <algorithm> 
#include <iostream>

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(float speed, glm::vec2 position, InputManager* inputManager, float shotColdown)
{
	this->speed = speed;
	this->position = position;
	this->inputmanager = inputManager;
	this->shotColdown = shotColdown;
	this->timeForShot = shotColdown;
	this->currentShotColdown = shotColdown;
	this->godMode = false;
	this->aux_speed_coldown = make_pair(speed, shotColdown);

	direction = TOP;

	color.set(200, 200, 200, 255);

	//Aletorizar primer frame del sprite e inicilizar variables
	srand(time(NULL));
	currentFrame = rand() % 4;
	valDirection = 1;
	animationSpeed = 0;
	animation = "Images/CaballeroIdle.png";
}

void Player::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
	if (inputmanager->isKeyDown(SDLK_w)) {
		position.y += speed;
		direction = TOP;
	}
	if (inputmanager->isKeyDown(SDLK_s)) {
		position.y -= speed;
		direction = DOWN;
	}
	if (inputmanager->isKeyDown(SDLK_a)) {
		position.x -= speed;
		valDirection = -1;
		direction = LEFT;
	}
	if (inputmanager->isKeyDown(SDLK_d)) {
		position.x += speed;
		valDirection = 1;
		direction = RIGHT;
	}

	if (inputmanager->isKeyDown(SDLK_w) || inputmanager->isKeyDown(SDLK_s)
		|| inputmanager->isKeyDown(SDLK_a) || inputmanager->isKeyDown(SDLK_d))
	{
		animation = "Images/Caballero1.png";
	}
	else
	{
		animation = "Images/CaballeroIdle.png";
	}

	collideWithLevel(levelData);
	if (timeForShot > 0) {
		timeForShot--;
	}
	GodMode();
	// cambiando el color del player como animacion
	if (godMode) {
			int r = (color.r + 100 * sin(0.3 * SDL_GetTicks()));  
			int g = (color.g + 100 * sin(0.3 * SDL_GetTicks())); // 100 es la amplitud de la onda y 0.0003 es la frecuencia
			int a = (color.a + 10 * sin(0.3 * SDL_GetTicks())); 

			r = 255;
			g = 255;
			a = glm::clamp(a, 60, 255);

			int b = 0;

			color.set(r, g, b, a);
	}
	animationSpeed++;
	if (animationSpeed == 8) {
		currentFrame = (currentFrame + 1) % 4;
		animationSpeed = 0;
	}
}


glm::vec2 Player::getDirection() {
	switch(direction) {

		case TOP:
			return glm::vec2(0, 1);
			break;
		case DOWN:
			return glm::vec2(0, -1);
			break;
		case LEFT:
			return glm::vec2(-1, 0);
			break;
		case RIGHT:
			return glm::vec2(1, 0);
			break;
	}
}

void Player::resetCDShot() {
	timeForShot = currentShotColdown;
}


void Player::updateShotColdown(float camScale) 
{
	if (camScale > 0) {
		currentShotColdown = shotColdown / camScale;
	}
	//cout << currentShotColdown << endl;
}

bool Player::shotReady() {
	if (timeForShot <= 0) {
		return true;
	}
	return false;
}

void Player::infoCD() {
	cout << shotColdown << ":" << currentShotColdown << "/" << currentShotColdown - shotColdown << endl;
}

void Player::GodMode()
{
	if (inputmanager->isKeyDown(SDLK_g)) {
		godMode = true;
		shotColdown = 1;
		speed = 15;

	}
	if (inputmanager->isKeyDown(SDLK_u)){
		godMode = false;
		shotColdown = aux_speed_coldown.second;
		speed = aux_speed_coldown.first;
		color.set(200, 200, 200, 255);
	}
}

void Player::draw()
{
	spritebatch.init();
	spritebatch.begin();

	glm::vec4 uvRect(currentFrame * (1.0f / 4), 0.0f, valDirection * (1.0f / 4), 1.0f);

	glm::vec4 destRect(position.x, position.y, AGENT_WIDTH * 0.9, AGENT_WIDTH * 0.8);
	spritebatch.draw(destRect, uvRect, ResourceManager::getTexture(animation).id, 0.0f, color);
	spritebatch.end();
	spritebatch.renderBatch();
}