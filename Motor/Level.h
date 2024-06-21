#pragma once
#include <string>
#include <vector>
#include "SpriteBatch.h"

using namespace std;
const int TILE_WIDTH = 64;
class Level
{
private:
	vector<string> levelData;
	int numHumans;
	int numZombies = 0;
	void parseLevel();
	glm::vec2 playerPosition;
	vector<glm::vec2> zombies;
public:
	Level(const string& fileName);
	void draw();
	SpriteBatch spritebatch;
	~Level();
	int getNumHumans() {
		return numHumans;
	}
	int getNumZombies() {
		return numZombies;
	}
	glm::vec2 getPlayerPosition() const{
		return playerPosition;
	}
	glm::vec2 getZombiesPosition(int index) {
		return zombies[index];
	}
	vector<string>& getLevelData() {
		return levelData;
	}
	int getWidth()const {
		return levelData[0].size();
	}
	int getHeight()const {
		return levelData.size();
	}
};
