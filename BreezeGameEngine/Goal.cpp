#include "Goal.h"

Goal::Goal(std::mt19937& rng, Board& brd, const Snake& snake)
{
}

void Goal::Spawn(std::mt19937& rng, Board& brd, const Snake& snake)
{
	loc = brd.SpawnObstacle(rng, 1, snake);
}

const Location& Goal::GetLoc() const
{
	return loc;
}
