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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(dev()), xDist(15, 799 - 15), yDist(15, 599 - 15), vDist(-5.0f*60.0f, 5*60.0f)
{
}
//,
//	Coin0(xDist(rng), yDist(rng), vDist(rng), vDist(rng)),
//	Coin1(xDist(rng), yDist(rng), vDist(rng), vDist(rng)),
//	Coin2(xDist(rng), yDist(rng), vDist(rng), vDist(rng))
void Game::Play()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	if (AtTitle)
	{
		Satoru.ROCKETMODE = 0;
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			AtTitle = !AtTitle;
			DoneWon = 0;

			for (int i = 0; i < NCoins; i++)
			{
				Coin[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
			}

			Satoru.Pos.X = Satoru.DefX;
			Satoru.Pos.Y = Satoru.DefY;
		}

		else if (wnd.kbd.KeyIsPressed('R'))
		{
			Satoru.ROCKETMODE = 1;
			AtTitle = !AtTitle;
			DoneWon = 0;

			for (int i = 0; i < NCoins; i++)
			{
				Coin[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
			}

			Satoru.Pos.X = Satoru.DefX;
			Satoru.Pos.Y = Satoru.DefY;

			Satoru.Vel.X = 0;
			Satoru.Vel.Y = 0;
		}
	}
	else
	{
		Satoru.Update( wnd.kbd, dt );

		for (int i = 0; i < NCoins; i++)
		{
			Coin[i].Update( dt );
		}

		for (int i = 0; i < NCoins; i++)
		{
			for (int j = i + 1; j < NCoins; j++)
			{
				Coin[i].CoinColl(Coin[j]);
			}
		}

		int CoinCoint = 0;
		while (Coin[CoinCoint].IsGot() && CoinCoint < NCoins)
		{
			CoinCoint++;
		}

	    if (CoinCoint >= NCoins && !DoneWon)
    	{
		    Beep(900, 100);
	    	Beep(600, 250);
    		Beep(120, 1000);

		    Beep(900, 100);
	    	Beep(600, 250);
    		Beep(120, 1000);

		    Beep(900, 100);
	    	Beep(600, 250);
    		Beep(120, 1000);

		    DoneWon = !DoneWon;
			AtTitle = 1;
	    }

		for (int i = 0; i < NCoins; i++)
		{
			if (Game::BoxColl(Satoru.Pos.X, Satoru.Pos.Y, Satoru.W, Satoru.H, Coin[i].PollX(), Coin[i].PollY(), Coin::W, Coin::H) && !DoneWon && !Coin[i].IsGot())
			{
				Coin[i].Get();
				Beep(300+300*int(abs(vDist(rng))/60.0f), 200);
			}
		}
	}
}



void Game::ComposeFrame()
{
	if (AtTitle)
	{
		DrawTitle();
	}
	else {

		for (int i = 0; i < NCoins; i++)
		{
			if (!Coin[i].IsGot())
			{
				Coin[i].Draw(gfx);
			}
		}

    	Satoru.Draw(gfx);
	}
}


bool Game::BoxColl(float box0x, float box0y, float box0W, float box0H, float box1x, float box1y, float box1W, float box1H )
{
	float b0left = box0x - box0W;
	float b0right = box0x + box0W;
	float b0top = box0y - box0H;
	float b0bot = box0y + box0H;

	float b1left = box1x - box1W;
	float b1right = box1x + box1W;
	float b1top = box1y - box1H;
	float b1bot = box1y + box1H;

	return (b0left <= b1right &&
		    b0right >= b1left &&
		    b0top <= b1bot &&
		    b0bot >= b1top);
}

void Game::DrawTitle()
{
	gfx.PutPixel(200, 200, 200, 200, 200);
}

int Game::WallX(int xp, int w)
{
	if (xp  < w)
	{
		return w;
	}

	else if (xp >= gfx.ScreenWidth - w)
	{
		return gfx.ScreenWidth - w-1;
	}

	else
	{
		return xp;
	}
}

int Game::WallY(int yp, int h)
{
	if (yp < h)
	{
		return h;
	}

	else if (yp >= gfx.ScreenHeight - h)
	{
		return gfx.ScreenHeight - h-1;
	}

	else
	{
		return yp;
	}
}

int Game::BounceX(int x, int vx, int w)
{
	if (WallX(x, w) == w || WallX(x, w) == gfx.ScreenWidth - w - 1)
	{
		return -vx;
	}

	else
	{
		return vx;
	}
}

int Game::BounceY(int y, int vy, int h)
{
	if (WallY(y, h) == h || WallY(y, h) == gfx.ScreenHeight - h - 1)
	{
		return -vy;
	}

	else
	{
		return vy;
	}
}
