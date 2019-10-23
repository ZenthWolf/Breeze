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
#include "FrameTimer.h"

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
	
	bool BoxColl(float box0x, float box0y, float box0w, float box0h, float box1x, float box1y, float box1w, float box1h );
	void DrawSatoru(int x, int y);
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
	FrameTimer ft;
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	std::uniform_real_distribution<float> vDist;
	bool AtTitle = 1;
	bool DoneWon = 0;
	static  constexpr int NCoins = 25;

	Coin Coin[NCoins];

	Satoru Satoru;
};