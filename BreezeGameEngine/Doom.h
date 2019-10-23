#pragma once

#include "Snake.h"
#include "Goal.h"
#include "Board.h"
#include <random>

class Doom
{
public:
	void Spawn(std::mt19937& rng, const Board& brd, const Snake& snake, const Goal& goal);
	void Draw(Board& brd) const;
	bool CheckDoom() const;
private:
	static constexpr Color c = {75,75,75};
	Location loc;
};


/*

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Spawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd) const;
	const Location& GetLoc() const;

private:
	static constexpr Color c = Colors::White;
	Location loc;
};
*/