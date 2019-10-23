#include "SpriteCodex.h"

void SpriteCodex::DrawGameOver(int x0, int y0, Graphics& gfx)
{
	for (int y = 0; y < gfx.ScreenHeight; y = y + 3)
	{
		for (int x = 0; x < gfx.ScreenWidth; x++)
		{
			gfx.PutPixel(x, y, 255, 0, 0);
		}
	}
}

void SpriteCodex::DrawTitle(int x, int y, Graphics& gfx)
{
	for (y = 0; y < gfx.ScreenHeight; y++)
	{
		for (x = 0; x < gfx.ScreenWidth; x++)
		{
			if (y % 6 == x % 6)
			{
				gfx.PutPixel(x, y, 0, 200, 0);
			}
		}
	}
}
