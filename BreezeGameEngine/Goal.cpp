#include "Goal.h"

Goal::Goal(std::mt19937& rng, Board& brd, const Snake& snake)
{
}

void Goal::Spawn(std::mt19937& rng, Board& brd, const Snake& snake)
{
	loc = brd.SpawnObstacle(rng, 1, snake);
	Placed = 1;
}

const Location& Goal::GetLoc() const
{
	return loc;
}

bool Goal::isPlaced() const
{
	return Placed;
}
