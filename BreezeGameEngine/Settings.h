#pragma once

#include <string>

class Settings
{
public:
	Settings(std::string& filename);
	void MakeConfig() const;
	int GetWidth() const;
	int GetHeight() const;
	float GetMovePeriod() const;
	bool IsSnakeRainbow() const;
	bool IsSnakeBeveled() const;

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