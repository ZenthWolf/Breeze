#pragma once

#include <string>

class Settings
{
public:
	Settings(std::string& filename);
	void MakeConfig();
	int GetWidth() const;
	int GetHeight() const;
	bool IsSnakeRainbow() const;
	bool IsSnakeBeveled() const;

private:
	int boardWidth;
	bool initWidth;
	int boardHeight;
	bool initHeight;
	bool rainbowSnake;
	bool initRainbow;
	bool bevelSnake;
	bool initBevel;
};