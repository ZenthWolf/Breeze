#include "Board.h"
#include "Snake.h"

Board::Board(Graphics& gfx): gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.x * CellDim < gfx.ScreenWidth);
	assert(loc.y >= 0);
	assert(loc.y < height);
	assert(loc.y * CellDim < gfx.ScreenHeight);

	int StartingX = (gfx.ScreenWidth/2 -1) - (CellDim*width)/2;
	int StartingY = (gfx.ScreenHeight / 2 - 1) - (CellDim * height)/2;
	gfx.DrawRectDim(loc.x * CellDim + StartingX, loc.y * CellDim + StartingY, CellDim, CellDim, c);
}

void Board::DrawBound(Color c)
{
	int StartingX = (gfx.ScreenWidth / 2 - 1) - (CellDim * width) / 2 - 8;
	int StartingY = (gfx.ScreenHeight / 2 - 1) - (CellDim * height) / 2 - 8;
	int FinalX = (gfx.ScreenWidth / 2 - 1) + (CellDim * width) / 2 +8;
	int FinalY = (gfx.ScreenHeight / 2 - 1) + (CellDim * height) / 2 +8;
	assert(StartingX-2 >= 0);
	assert(FinalX < gfx.ScreenWidth);
	assert(StartingY-2 >= 0);
	assert(FinalY < gfx.ScreenHeight);

	int THICCNESS = 3;
	for (int i = 0; i < THICCNESS; i++)
	{
		for (int x = StartingX-i; x <= FinalX+i; x++)
		{
			int y = StartingY - i;
			gfx.PutPixel(x, y, c);
			y = FinalY + i;
			gfx.PutPixel(x, y, c);
		}
	}

	for (int i = 0; i < THICCNESS; i++)
	{
		for (int y = StartingY - i; y <= FinalY + i; y++)
		{
			int x = StartingX - i;
			gfx.PutPixel(x, y, c);
			x = FinalX + i;
			gfx.PutPixel(x, y, c);
		}
	}

	THICCNESS = 2;
	for (int i = 0; i < THICCNESS; i++)
	{
		for (int x = StartingX + 5 - i ; x <= FinalX - 5 + i; x++)
		{
			int y = StartingY + 5 - i;
			gfx.PutPixel(x, y, c);
			y = FinalY - 5 + i;
			gfx.PutPixel(x, y, c);
		}
	}

	for (int i = 0; i < THICCNESS; i++)
	{
		for (int y = StartingY + 5-i; y <= FinalY - 5 + i; y++)
		{
			int x = StartingX + 5 - i;
			gfx.PutPixel(x, y, c);
			x = FinalX - 5 + i;
			gfx.PutPixel(x, y, c);
		}
	}
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

bool Board::InBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
     	   loc.y >= 0 && loc.y < height;
}

int Board::CheckObstacle(const Location& loc) const
{
	return Obstacle[loc.y*width + loc.x];
}

void Board::SpawnObstacle(std::mt19937& rng, const int type, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, width - 1);
	std::uniform_int_distribution<int> yDist(0, height - 1);

	Location procLoc;

	do
	{
		procLoc.x = xDist(rng);
		procLoc.y = yDist(rng);
	} while (snake.InTile(procLoc) || !(Obstacle[procLoc.y * width + procLoc.x] ==0));
	
	Obstacle[procLoc.y * width + procLoc.x] = type;
}

void Board::DrawBoard()
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < height; i++)
		{
			if (CheckObstacle({i, j}) )
			{
				DrawCell({ i,j }, obstacleColor);
			}
		}
	}
}
