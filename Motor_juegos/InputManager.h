#pragma once
#include <glm/glm.hpp>
#include <unordered_map>
using namespace std;

class InputManager
{
private:
	unordered_map<unsigned int, bool> keys;
	glm::vec2 mouseCoords;
public:
	InputManager();
	glm::vec2 getMouseCoords() const {
		return mouseCoords;
	}
	void setMouseCoords(float x, float y);
	void presskey(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	bool iskeyPressed(unsigned int keyCode);
	~InputManager();
};

