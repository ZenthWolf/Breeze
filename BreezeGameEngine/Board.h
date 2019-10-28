#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>
#include <random>

struct Board
{
public:
	class Goal
	{
	public:
		Goal();
		void Spawn(std::mt19937& rng, Board& brd, const class Snake& snake);
		const Location& GetLoc() const;
		bool isPlaced() const;

	private:
		Location loc;
		bool Placed = 0;
	};

public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBound(Color c);
	int GetWidth() const;
	int GetHeight() const;
	bool InBoard(const Location& loc) const;
	int CheckObstacle( const Location& loc) const;
	Location SpawnObstacle( std::mt19937& rng, const int type, const class Snake& snake);
	void DrawBoard();
	void Consume(const Location& loc);
	void ClearObstacles();
	Goal Goal;
	
private:
	static constexpr Color obstacleColor[2] = { Colors::White, Colors::Gray };
	static constexpr int CellDim = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	int Obstacle[width * height] = { 0 };
	Graphics& gfx;
};