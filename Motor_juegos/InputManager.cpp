#include "InputManager.h"

InputManager::InputManager() : mouseCoords(0.0f, 0.0f)
{
}

void InputManager::setMouseCoords(float x, float y)
{
	mouseCoords.x = x;
	mouseCoords.y = y;
}

void InputManager::presskey(unsigned int keyCode)
{
	keys[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode)
{
	keys[keyCode] = false;
}

bool InputManager::iskeyPressed(unsigned int keyCode)
{
	auto it = keys.find(keyCode);
	if (it != keys.end())
	{
		return it->second;
	}
	return false;
}

InputManager::~InputManager()
{
}
