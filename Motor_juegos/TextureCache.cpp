#include "TextureCache.h"
#include "ImageLoader.h"
TextureCache::TextureCache()
{
}

TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(string texturePath)
{
	//map<string, GLTexture>::iterator mit = textureMap.find(texturePath); // forma larga
	auto mit = textureMap.find(texturePath); // forma corta
	if (mit == textureMap.end()) {

		GLTexture texture = ImageLoader::LoadPng(texturePath);

		// forma 1
		/*pair<string, GLTexture> newPair(texturePath, texture);
		textureMap.insert(newPair);*/

		//forma 2
		textureMap[texturePath] = texture;
		
		return texture;
	}
	return mit ->second;
}
