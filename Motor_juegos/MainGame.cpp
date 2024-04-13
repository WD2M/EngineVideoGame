#include "MainGame.h"
#include "iostream"


using namespace std;

MainGame::MainGame()
{
	window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
}
void MainGame::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Motor WD2M", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								width, height, SDL_WINDOW_OPENGL);

	// todo validar si hay un error 
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		// todo falta validar estados del glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	sprite.Draw();
	SDL_GL_SwapWindow(window);
}

void MainGame::run()
{
	init();
	sprite.Init(-1,-1,1,1);
	update();
}

void MainGame::update()
{
	while (gameState != GameState::EXIT)
	{
		processInput();
		draw();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				gameState = GameState::EXIT;
			break;
			case SDL_MOUSEMOTION:
				//cout << "position en x " << event.motion.x <<
					//"position en y " << event.motion.y << endl;
			break;
		default:
			break;
		}
	}
}

MainGame::~MainGame()
{
}


