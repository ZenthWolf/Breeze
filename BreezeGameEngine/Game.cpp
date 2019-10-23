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
	rng(dev()), xDist(15, 799 - 15), yDist(15, 599 - 15), vDist(-5, 5)
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

			Satoru.X = Satoru.DefX;
			Satoru.Y = Satoru.DefY;
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

			Satoru.X = Satoru.DefX;
			Satoru.Y = Satoru.DefY;

			Satoru.Vx = 0;
			Satoru.Vy = 0;
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			if (!Satoru.ROCKETMODE)
			{
				Satoru.Y = Satoru.Y - 2;
			}
			else
			{
				Satoru.Vy = Satoru.Vy - 1;
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			if (!Satoru.ROCKETMODE)
			{
				Satoru.Y = Satoru.Y + 2;
			}
			else
			{
				Satoru.Vy = Satoru.Vy + 1;
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (!Satoru.ROCKETMODE)
			{
				Satoru.X = Satoru.X - 2;
			}
			else
			{
				Satoru.Vx = Satoru.Vx - 1;
			}
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			if (!Satoru.ROCKETMODE)
			{
				Satoru.X = Satoru.X + 2;
			}
			else
			{
				Satoru.Vx = Satoru.Vx + 1;
			}
		}

		Satoru.Update();

		for (int i = 0; i < NCoins; i++)
		{
			Coin[i].Update();
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
			if (Game::BoxColl(Satoru.X, Satoru.Y, Satoru.W, Satoru.H, Coin[i].PollX(), Coin[i].PollY(), Coin::W, Coin::H) && !DoneWon && !Coin[i].IsGot())
			{
				Coin[i].Get();
				Beep(300+300*int(vDist(rng)), 200);
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

    	Game::DrawSatoru(int(Satoru.X), int(Satoru.Y));
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

void Game::DrawSatoru(int x, int y)
{
	//Hair
	int py = -9;
	for (int px = -7; px <= 7; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}

	py = -8;
	for (int px = -9; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}

	py = -7;
	for (int px = -9; px <= -2; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}
	for (int px = 2; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}
	py = -6;
	for (int px = -9; px <= -2; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}
	for (int px = 4; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}

	py = -5;
	for (int px = -9; px <= -7; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}
	for (int px = 8; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}

	py = -4;
	for (int px = -9; px <= -7; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}
	for (int px = 8; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 94, 44, 44);
	}

	//Eye White
	py = -3;
	for (int px = -5; px <= -3; px++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}
	for (int px = 3; px <= 5; px++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}

	py = 1;
	for (int px = -5; px <= -3; px++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}
	for (int px = 3; px <= 5; px++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}

	int px = -5;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}

	px = -3;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}

	px = 3;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}

	px = 5;
	for (int py = -3; py <= 1; py++)
	{
		gfx.PutPixel(x + px, y + py, 255, 255, 255);
	}

	//skin
	py = -7;
	for (int px = -1; px <= 1; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	py = -6;
	for (int px = -1; px <= 4; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	py = -5;
	for (int px = -6; px <= 7; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	py = -4;
	for (int px = 6; px <= 7; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
	for (int px = -2; px <= 2; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
	gfx.PutPixel(x - 6, y + py, 209, 169, 109);

	py = -3;
	for (int px = -8; px <= -7; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
	for (int px = 7; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
	gfx.PutPixel(x + 1, y + py, 209, 169, 109);
	gfx.PutPixel(x - 1, y + py, 209, 169, 109);

	py = -2;
	for (int px = -9; px <= -7; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
	gfx.PutPixel(x , y + py, 209, 169, 109);

	py = 9;
	for (int px = -7; px <= 7; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	py = 8;
	for (int px = -8; px <= 8; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	py = 7;
	for (int px = -9; px <= -3; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
	for (int px = 3; px <= 9; px++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -9;
	for (int py = -1; py <= 7; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -8;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -7;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -6;
	for (int py = 2; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -5;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -4;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -3;
	for (int py = 3; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -2;
	for (int py = 2; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = -1;
	for (int py = -1; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 0;
	for (int py = -1; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 1;
	for (int py = -1; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 2;
	for (int py = 2; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 3;
	for (int py = 3; py <= 5; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 4;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 5;
	for (int py = 3; py <= 4; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 6;
	for (int py = 2; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 7;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 8;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}

	px = 9;
	for (int py = -1; py <= 6; py++)
	{
		gfx.PutPixel(x + px, y + py, 209, 169, 109);
	}
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
