#include "Settings.h"
#include <fstream>

Settings::Settings(std::string& filename)
	: initWidth(false), initHeight(false),
      initRainbow(false), initBevel(false)
{
	std::ifstream config(filename);

	while (config.good())
	{
		std::string line;
		std::getline(config, line);

		if (line == "[Board Size]")
		{
			if ( isdigit(config.peek()) )
			{
				config >> boardWidth;
				config >> std::ws;
				if ( isdigit(config.peek()) )
				{
					config >> boardHeight;

					if (boardWidth <= 38 && boardHeight <= 26)
					{
						initWidth = true;
						initHeight = true;
					}
				}
			}

		}

		else if (line == "[Snake Color : 0 - Natural, 1 - Rainbow]")
		{
			if (isdigit(config.peek()))
			{
				config >> rainbowSnake;
				initRainbow = true;
			}
		}

		else if (line == "[Snake Shape : 0 - Flat, 1 - 3D]")
		{
			if (isdigit(config.peek()))
			{
				config >> bevelSnake;
				initBevel = true;
			}
		}
		config >> std::ws;
	}
	config.close();

	if ( !initWidth || !initHeight || !initRainbow || !initBevel )
	{
		MakeConfig();
	}
}

void Settings::MakeConfig()
{
	std::ofstream config("configs.txt");

	config << "[Board Size]\n";
	if (initWidth && initHeight)
	{
		config << boardWidth << " " << boardHeight << "\n" << "\n";
	}
	else
	{
		boardWidth = 30; boardHeight = 20;
		config << boardWidth << " " << boardHeight<< "\n" << "\n";
	}

	config << "[Snake Color : " << 0 << " - Natural, 1 - Rainbow]\n";
	if (initRainbow)
	{
		config << rainbowSnake << "\n\n";
	}
	else
	{
		rainbowSnake = 0;
		config << 0 << "\n\n";
	}

	config << "[Snake Shape : " << 0 << " - Flat, 1 - " << 3 << "D]\n";
	if (initBevel)
	{
		config << bevelSnake;
	}
	else
	{
		bevelSnake = 0;
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

bool Settings::IsSnakeRainbow() const
{
	return rainbowSnake;
}

bool Settings::IsSnakeBeveled() const
{
	return bevelSnake;
}
