/***************************************************************************/
/***               Temper Tech DirectX Framework V 1.0.0                 ***/
/*** Game.cpp                                                            ***/
/*** Copyright for all time (if your law disagrees, it can suck it)      ***/
/***                                                                     ***/
/*** Part of the Temper DirectX Framework                                ***/
/***                                                                     ***/
/*** Proprietary Software, do not read.                                  ***/
/*** You cannot use it, look at it, or have it on your computer,         ***/
/*** unless you are a working member of Temper Tech                      ***/
/***                                                                     ***/
/*** If you need help, go fuck yourself.                                 ***/
/***************************************************************************/

#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd), gfx(wnd), ft(),
	brd(gfx), rng( std::random_device()() ),
	Snake({2,2}), goal(rng, brd, Snake)
{
}

void Game::Play()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}



void Game::UpdateModel()
{
	dt = ft.Mark();
	MoveDelay += dt;

	if (AtTitle)
	{
		if (ReInit)
		{
			Snake.ReInit({ 2,2 });
		}

		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			AtTitle = 0;
			Eats = 0;
			MoveDelay = 0;
		}
	}
	else
	{
		if (Death)
		{
			if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
			{
				AtTitle = 1;
				Death = 0;
			}
		}
		else
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				Snake.SetMoveBuffer({ 0,-1 });
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				Snake.SetMoveBuffer({ 0,1 });
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				Snake.SetMoveBuffer({ -1,0 });
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				Snake.SetMoveBuffer({ 1,0 });
			}

			if (MoveDelay >= MovePeriod)
			{
				MoveDelay -= MovePeriod - std::min(float(Eats)/120.0f, 15.0f);
				const Location Next = Snake.GetNextHead();
				if (!brd.InBoard(Next) || Snake.InTileExcEnd(Next))
				{
					Snake.DeadHead();
					Death = 1;
					ReInit = 1;
				}
				else
				{
					if (Next == goal.GetLoc())
					{
						Snake.Grow();
						Eats++;
						Snake.Update();
//						Snake.MoveBy(dLoc);
						goal.Spawn(rng, brd, Snake);
					}
					else
					{
						Snake.Update();
//						Snake.MoveBy(dLoc);
					}
				}
			}
		}
	}
}


void Game::ComposeFrame()
{
	brd.DrawBound(Colors::White);

	Snake.Draw( brd );
	if (AtTitle)
	{
		SpriteCodex::DrawTitle(200, 200, gfx);
	}
	else
	{
		goal.Draw(brd);
		if (Death)
		{
			SpriteCodex::DrawGameOver(200, 200, gfx);
		}
	}
}


