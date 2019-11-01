#include "Snake.h"
#include <assert.h>

Snake::Snake(const Settings& gameSettings, const Location& loc)
{
	segment.emplace_back( loc );

	rainbowSnake = gameSettings.IsSnakeRainbow();
	bevelSnake = gameSettings.IsSnakeBeveled();
}

void Snake::ReInit(const Location& loc)
{
	segment.resize(0, Segment( headColor ));
	segment.emplace_back( loc );
	dLoc = { 0,0 };
	dLocBuff = { 0,0 };
}

void Snake::SetMoveBuffer(const Location& newdloc)
{
	//Do not let the player turn 180!
	if (newdloc.x + dLoc.x != 0 || newdloc.y + dLoc.y != 0)
	{
		dLocBuff = newdloc;
	}
}

void Snake::Update()
{
	dLoc = dLocBuff;
	for (size_t i = segment.size() - 1; i > 0; i--)
	{
		segment[i].Follow(segment[i - 1]);
	}

	segment[0].MoveBy(dLoc);
}

void Snake::MoveBy(const Location& dloc)
{
	for (size_t i = segment.size() - 1; i > 0; i--)
	{
		segment[i].Follow(segment[i - 1]);
	}

	segment.front().MoveBy(dloc);
}

void Snake::DeadHead()
{
	segment.front().Death();
}

Location Snake::GetNextHead() const
{
	Location l(segment.front().GetLoc());
	l.Add(dLocBuff);
	return l;
}

void Snake::Grow()
{
	Color c;
	int nSeg = int(segment.size()) - 1;

	/* One day, I will array this trash. */

	if (rainbowSnake)
	{
		if (nSeg % 7 == 0)
		{
			c = Colors::Red;
		}
		else if (nSeg % 7 == 1)
		{
			c = { 255, 165, 0 };
		}
		else if (nSeg % 7 == 2)
		{
			c = Colors::Yellow;
		}
		else if (nSeg % 7 == 3)
		{
			c = Colors::Green;
		}
		else if (nSeg % 7 == 4)
		{
			c = Colors::Cyan;
		}
		else if (nSeg % 7 == 5)
		{
			c = Colors::Blue;
		}
		else if (nSeg % 7 == 6)
		{
			c = { 128,0,128 };
		}
			
		segment.emplace_back( c );
	}
	else
	{
		if (nSeg % 5 == 1)
		{
			c = Snake::natbodyColor1;
		}
		if (nSeg % 5 == 2)
		{
			c = Snake::natbodyColor2;
		}
		if (nSeg % 5 == 3)
		{
			c = Snake::natbodyColor3;
		}
		if (nSeg % 5 == 4)
		{
			c = Snake::natbodyColor4;
		}
		if (nSeg % 5 == 0)
		{
			c = Snake::natbodyColor5;
		}
		segment.emplace_back( c );
	}
}

void Snake::Draw(Board& brd) const
{
	for ( const auto& s : segment )
	{
		s.Draw( bevelSnake, brd );
	}
}

bool Snake::InTile(const Location& targ) const
{
    /* Checks ALL segs */
	for (int i = 0; i < segment.size(); i++)
	{
		if (segment[i].GetLoc() == targ)
		{
			return true;
		}
	}
	return false;
}

bool Snake::InTileExcEnd(const Location& targ) const
{
	/* Checks all segs except tail */
	for (int i = 0; i < segment.size() - 1; i++)
	{
		if (segment[i].GetLoc() == targ)
		{
			return true;
		}
	}
	return false;
}

Snake::Segment::Segment(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

Snake::Segment::Segment(const Color& col)
{
	c = col;
}

void Snake::Segment::Death()
{
	c = { 120, 120, 120 };
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& dloc)
{
	loc.Add(dloc);
}

void Snake::Segment::Draw(bool bevel, Board& brd) const
{
	brd.DrawCell(loc, c, bevel);
}

const Location& Snake::Segment::GetLoc() const
{
	return loc;
}
