#pragma once

#include "Board.h"
#include <vector>

class Snake
{
private:
	class Segment
	{
	public:
		/* For Head */
		Segment(const Location& loc);
		/* For Body */
		Segment(const Color& col);
		void Death();
		void Follow(const Segment& next);
		void MoveBy(const Location& dloc);
		void Draw(bool bevel, Board& brd) const;
		const Location& GetLoc() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Settings& gameSettings, const Location& loc);
	void ReInit(const Location& loc);
	void SetMoveBuffer(const Location& newdloc);
	void Update();
	void MoveBy(const Location& dloc);
	void DeadHead();
	Location GetNextHead() const;
	void Grow();
	void Draw(Board& brd) const;
	bool InTile(const Location& targ) const;
	bool InTileExcEnd(const Location& targ) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr Color natbodyColor1 = {0,150,0};
	static constexpr Color natbodyColor2 = {30,80,0};
	static constexpr Color natbodyColor3 = {50,70,0};
	static constexpr Color natbodyColor4 = {30,80,0};
	static constexpr Color natbodyColor5 = {0,150,0};

	Location dLoc = { 0,0 };
	Location dLocBuff = { 0,0 };
	
	std::vector<Segment> segment;
	bool rainbowSnake = false;
	bool bevelSnake = false;
};