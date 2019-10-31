#pragma once

#include <string>

class Settings
{
public:
	Settings(std::string& filename);
	void MakeConfig();
	int GetWidth();
	int GetHeight();
	float GetMovePeriod();
	bool IsSnakeRainbow();
	bool IsSnakeBeveled();

private:
	int boardWidth;
	bool initWidth;
	int boardHeight;
	bool initHeight;
	float minMovePeriod;
	bool initMinMove;
	bool rainbowSnake;
	bool initRainbow;
	bool bevelSnake;
	bool initBevel;
};