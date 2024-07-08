#pragma once
//#include <SDL/SDL.h>
//#include <SDL/SDL_mixer.h>

#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")
using namespace std;

class Audio
{
public:
	void initAudio(string audio);
	void stopAudio(string audio);
};

