#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>

using namespace std;
enum WindowsFlags {
	INVISIBLE = 0x1,
	FULLSCREEN = 0x2,
	BORDERLESS = 0x3
};

class Window
{
private:
	SDL_Window* window;
	int screenWidth;
	int screenHeigth;
public:
	Window();
	~Window();
	void swapWindows();
	int create(string windowName, int screenWidth, int screenHeigth, int currentFlags);
	int getScreenWidth() {
		
		return screenWidth;
	}
	int getScreenHeigth() {

		return screenHeigth;
	}

};

