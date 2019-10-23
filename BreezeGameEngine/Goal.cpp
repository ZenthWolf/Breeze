#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Spawn(rng, brd, snake);
}

void Goal::Spawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);

	Location TestLoc;
	do
	{
		TestLoc.x = xDist(rng);
		TestLoc.y = yDist(rng);
	} while (snake.InTile(TestLoc));

	loc = TestLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);

}

const Location& Goal::GetLoc() const
{
	return loc;
}
