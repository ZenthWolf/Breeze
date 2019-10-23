#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>

struct Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBound(Color c);
	int GetWidth() const;
	int GetHeight() const;
	bool InBoard(const Location& loc) const;
	
private:
	static constexpr int CellDim = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	Graphics& gfx;
};