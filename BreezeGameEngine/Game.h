/***************************************************************************/
/***               Temper Tech DirectX Framework V 1.0.0                 ***/
/*** Game.h                                                              ***/
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <random>

#include "Coin.h"
#include "Satoru.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Play();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void DrawTitle();
	
	bool BoxColl(int box0x, int box0y, int box0w, int box0h, int box1x, int box1y, int box1w, int box1h );
	void DrawSatoru(int x, int y);
	void DrawCoin(int x, int y);
	int WallX(int x, int w);
	int WallY(int y, int h);
	int BounceX(int x, int vx, int w);
	int BounceY(int y, int vy, int h);

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	std::uniform_int_distribution<int> vDist;
	bool AtTitle = 1;
	bool DoneWon = 0;
	static  constexpr int NCoins = 25;

	Coin Coin[NCoins];

	Satoru Satoru;
};