#pragma once
#include "GLTexture.h"
#include <string>
using namespace std;
class ImageLoader
{
public:
	static GLTexture LoadPng(string filePath); 
};

