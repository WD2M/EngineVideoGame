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
	window = new Window();
	window->create("Motor WD2M", width, height, 0);
	//forma sin el archivo window
	/*window = SDL_CreateWindow("Motor WD2M", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								width, height, SDL_WINDOW_OPENGL);

	// todo validar si hay un error 
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		// todo falta validar estados del glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
<<<<<<< Updated upstream
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
=======
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // color de fondo para la ventana*/
	initShaders();
>>>>>>> Stashed changes
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	sprite.Draw();
<<<<<<< Updated upstream
	SDL_GL_SwapWindow(window);
=======
	
	if (timeGame>1)
	{
		sprite1.Draw();
		program.unuse(); // desactivacion del primer shader
	}
	if (timeGame > 2)
	{
		program1.use(); // uso del segundo shader
		GLuint timeLocation = program1.getUniformLocation("time");
		glUniform1f(timeLocation, time1);
		time1 += 0.002;
		sprite2.Draw();
	}
	if (timeGame > 3)
	{
		sprite3.Draw();
		program1.unuse(); // desactivacion del segundo shader
	}	
	window->swapWindows();
	//SDL_GL_SwapWindow(window);
>>>>>>> Stashed changes
}

void MainGame::run()
{
	init();
<<<<<<< Updated upstream
	sprite.Init(-1,-1,1,1);
=======
	sprite.Init(1, 1, -1, -1,"Images/Bleach.png"); // pos de cada recuadro 
	sprite1.Init(-1, -1, 1, 1, "Images/Bleach.png");
	sprite2.Init(1, -1, 1, -1, "Images/Bleach.png");
	sprite3.Init(-1, 1, -1, 1, "Images/Bleach.png");
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
=======
void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt"); // busqueda y compilacion de cada shader
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

>>>>>>> Stashed changes
MainGame::~MainGame()
{
}


