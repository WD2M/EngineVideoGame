#include "MainGame.h"
#include "Sprite.h"

MainGame::MainGame()
{
	window = NULL;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;

}

void MainGame::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = new Window();
	window->create("Motor WD2M", width, height, 0);

	initShaders();

}

MainGame::~MainGame()
{


}

void MainGame::run()
{
	init();
	sprite.init(-1, -1, 1, 1, "images/Bleach.png");
	sprite1.init(-1, 1, 1, -1, "images/Bleach1.png");
	sprite2.init(1, 1, -1, -1, "images/Bleach.png");
	sprite3.init(1, -1, -1, 1, "images/Bleach1.png");
	update();
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	program.use(); // uso del primer shader
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.002;
	timeGame += 0.0005;
	sprite.draw();
	
	if (timeGame > 1)
	{
		sprite1.draw();
		program.unuse(); // desactivacion del primer shader
	}
	if (timeGame > 2)
	{
		program1.use(); // uso del segundo shader
		GLuint timeLocation = program1.getUniformLocation("time");
		glUniform1f(timeLocation, time1);
		time1 += 0.002;
		sprite2.draw();
	}
	if (timeGame > 3)
	{
		sprite3.draw();
		program1.unuse(); // desactivacion del segundo shader
	}
	window->swapWindows();
	//SDL_GL_SwapWindow(window);
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		draw();
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)){
		switch (event.type) {
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			//cout << " Posicion en X " << event.motion.x 
			//<< " Posicion en Y " << event.motion.y << endl;
			break;
		}
	}
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPoistion");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();

	program1.compileShaders("Shaders/colorShaderVertC.txt", "Shaders/colorShaderFragC.txt");
	program1.addAtribute("vertexPoistion");
	program1.addAtribute("vertexColor");
	program1.addAtribute("vertexUV");
	program1.linkShader();
}
