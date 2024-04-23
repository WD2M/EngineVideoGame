#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "GLS_Program.h"
#include "sprite.h"

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	Sprite sprite;
	int width;
	int height;
	SDL_Window* window;
	void init();
	void processInput();
	GLS_Program program;
	void initShaders();
	float time = 0;
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();

};

