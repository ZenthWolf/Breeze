#include "Settings.h"
#include <fstream>

Settings::Settings(std::string& filename)
	: initWidth(false), initHeight(false), initMinMove(false),
      initRainbow(false), initBevel(false)
{
	std::ifstream config(filename);

	while (config.good())
	{

		std::string line;
		std::getline(config, line);

		if (line == "[Board Size]")
		{
			config >> boardWidth;
			config >> boardHeight;
			initWidth = true;
			initHeight = true;
		}

		else if (line == "[Min Move Period]")
		{
			config >> minMovePeriod;
			initMinMove = true;
		}

		else if (line == "[Snake Color : 0 - Natural, 1 - Rainbow]")
		{
			config >> rainbowSnake;
			initRainbow = true;
		}

		else if (line == "[Snake Shape : 0 - Flat, 1 - 3D]")
		{
			config >> bevelSnake;
			initBevel = true;
		}
	}
	config.close();

	if ( !(initWidth || initHeight || initMinMove || initRainbow || initBevel) )
	{
		MakeConfig();
	}
}

void Settings::MakeConfig() const
{
	std::ofstream config("configs.txt");

	config << "[Board Size]\n";
	if (initWidth && initHeight)
	{
		config << boardWidth << " " << boardHeight << "\n" << "\n";
	}
	else
	{
		config << 20 << " " << 20 << "\n" << "\n";
	}

	config << "[Min Move Period]\n";
	if (initMinMove)
	{
		config << minMovePeriod << "\n\n";
	}
	else
	{
		config << 15.0f << "\n\n";
	}

	config << "[Snake Color : " << 0 << " - Natural, 1 - Rainbow]\n";
	if (initRainbow)
	{
		config << rainbowSnake << "\n\n";
	}
	else
	{
		config << 0 << "\n\n";
	}

	config << "[Snake Shape : " << 0 << " - Flat, 1 - " << 3 << "D]\n";
	if (initBevel)
	{
		config << bevelSnake;
	}
	else
	{
		config << 0 << "\n\n";
	}
}

int Settings::GetWidth() const
{
	return boardWidth;
}

int Settings::GetHeight() const
{
	return boardHeight;
}

float Settings::GetMovePeriod() const
{
	return minMovePeriod;
}

bool Settings::IsSnakeRainbow() const
{
	return rainbowSnake;
}

bool Settings::IsSnakeBeveled() const
{
	return bevelSnake;
}
