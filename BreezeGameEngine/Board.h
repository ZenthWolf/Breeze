#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>
#include <random>

struct Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBound(Color c);
	int GetWidth() const;
	int GetHeight() const;
	bool InBoard(const Location& loc) const;
	int CheckObstacle( const Location& loc) const;
	void SpawnObstacle( std::mt19937& rng, const int type, const class Snake& snake);
	void DrawBoard();
	
private:
	static constexpr Color obstacleColor = Colors::Magenta;
	static constexpr int CellDim = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	int Obstacle[width * height] = { 0 };
	Graphics& gfx;
};