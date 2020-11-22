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
#include <string>
#include "Settings.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd), gfx(wnd), ft(), rng(std::random_device()()),
	gameSettings(std::string("configs.txt")), brd(gameSettings, gfx), 
	Snake(gameSettings, {2,2})
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

		if (inhibitMenu && !wnd.kbd.KeyIsPressed(VK_RETURN)
			&& !wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			inhibitMenu = 0;
		}

		if ( (wnd.kbd.KeyIsPressed(VK_RETURN) || wnd.kbd.KeyIsPressed(VK_SPACE)) 
			 && !inhibitMenu)
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
			if (wnd.kbd.KeyIsPressed(VK_RETURN) || wnd.kbd.KeyIsPressed(VK_SPACE))
			{
				AtTitle = 1;
				Death = 0;
				brd.ClearObstacles();
				inhibitMenu = 1;
			}
		}
		else
		{
			if ((wnd.kbd.KeyIsPressed(VK_UP) || wnd.kbd.KeyIsPressed(VK_DOWN) ||
				wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed(VK_RIGHT) ||
				wnd.kbd.KeyIsPressed('W') || wnd.kbd.KeyIsPressed('S') || 
				wnd.kbd.KeyIsPressed('A') || wnd.kbd.KeyIsPressed('D') )
				&& !brd.Goal.isPlaced())
			{
				brd.Goal.Spawn(rng, brd, Snake);
			}

			if (wnd.kbd.KeyIsPressed(VK_UP) || wnd.kbd.KeyIsPressed('W'))
			{
				Snake.SetMoveBuffer({ 0,-1 });
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN) || wnd.kbd.KeyIsPressed('S'))
			{
				Snake.SetMoveBuffer({ 0,1 });
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed('A'))
			{
				Snake.SetMoveBuffer({ -1,0 });
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT) || wnd.kbd.KeyIsPressed('D'))
			{
				Snake.SetMoveBuffer({ 1,0 });
			}

			if (MoveDelay >= MovePeriod)
			{
				MoveDelay -= MovePeriod - std::min(float(Eats)/120.0f, 15.0f);
				const Location Next = Snake.GetNextHead();
				if (!brd.InBoard(Next) || Snake.InTileExcEnd(Next) || brd.CheckObstacle(Next) == Board::CellObstacle::Doom)
				{
					Snake.DeadHead();
					Death = 1;
					ReInit = 1;
				}
				else
				{
					if (Next == brd.Goal.GetLoc())
					{
						brd.Consume(Next);
						Snake.Grow();
						Eats++;
						Snake.Update();
						brd.SpawnObstacle(rng, Board::CellObstacle::Doom, Snake);
						brd.Goal.Spawn(rng, brd, Snake);
					}
					else
					{
						Snake.Update();
					}
				}
			}
		}
	}
}


void Game::ComposeFrame()
{
	brd.DrawBound(Colors::White);
	brd.DrawBoard();

	Snake.Draw( brd );
	if (AtTitle)
	{
		SpriteCodex::DrawTitle(200, 200, gfx);
	}
	else
	{
		if (Death)
		{
			SpriteCodex::DrawGameOver(200, 200, gfx);
		}
	}
}
