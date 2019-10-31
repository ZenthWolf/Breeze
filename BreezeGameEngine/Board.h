#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>
#include <random>
#include "Beveler.h"
#include "Settings.h"

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
		void unPlace();

	private:
		Location loc;
		bool Placed = 0;
	};
public:
	enum class CellObstacle
	{
	     Empty,
		 Doom,
		 Food
	};
public:
	Board(std::string filename, Graphics& gfx);
	Settings gameSettings;
	void DrawCell(const Location& loc, Color c);
	void DrawBound(Color c);
	int GetWidth() const;
	int GetHeight() const;
	bool InBoard(const Location& loc) const;
	CellObstacle CheckObstacle( const Location& loc) const;
	Location SpawnObstacle( std::mt19937& rng, const CellObstacle type, const class Snake& snake);
	void DrawBoard();
	void Consume(const Location& loc);
	void ClearObstacles();
	Goal Goal;
	
private:
	static constexpr Color obstacleColor[2] = { Colors::White, Colors::Gray };
	static constexpr int CellDim = 20;
	int width;
	int height;
	CellObstacle* Obstacle;
	Graphics& gfx;
	Beveler Bev;
};