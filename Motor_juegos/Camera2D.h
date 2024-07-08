#pragma once
<<<<<<< Updated upstream:Motor_juegos/Camera2D.h
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
=======
#include <glm\gtc\matrix_transform.hpp>
#include "InputManager.h"

>>>>>>> Stashed changes:Motor/Camera2D.h
class Camera2D
{
private:
	glm::vec2 position;
	float scale;
	int screenWidth;
	int screenHeight;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;
<<<<<<< Updated upstream:Motor_juegos/Camera2D.h
	bool needsUpdateMatrix;
=======

>>>>>>> Stashed changes:Motor/Camera2D.h
public:
	Camera2D();
	~Camera2D();
	void update();
	void init(int screenWidth, int screenHeight);
	void setPosition(const glm::vec2& newPosition) {
		position = newPosition;
		needsUpdateMatrix = true;
	}
	void setScale(float newScale) {
		scale = newScale;
		needsUpdateMatrix = true;
	}
	glm::mat4 getCameraMatrix() {
		return cameraMatrix;
	}
<<<<<<< Updated upstream:Motor_juegos/Camera2D.h
=======


	Camera2D();
	~Camera2D();
>>>>>>> Stashed changes:Motor/Camera2D.h
};

