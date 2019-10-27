#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, const Snake& snake);
	void Spawn(std::mt19937& rng, Board& brd, const Snake& snake);
	const Location& GetLoc() const;

private:
	Location loc;
};