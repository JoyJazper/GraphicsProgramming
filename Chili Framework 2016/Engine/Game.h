
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawBox(int x, int y, int r, int g, int b);
	void DrawEnemy(int x, int y, int r, int g, int b);
	bool OverlapTest(int box0x, int box0y, int box1x, int box1y);
	void ContainBox();
	int ClampScreenX(int x);
	int ClampScreenY(int y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int x_fixed0 = 200;
	int y_fixed0 = 200;
	int x_fixed1 = 210;
	int y_fixed1 = 200;
	int x_fixed2 = 215;
	int y_fixed2 = 200;
	int x_fixed3 = 230;
	int y_fixed3 = 200;
	int x_mobile = 400;
	int y_mobile = 400;
	bool colliding = false;
	/********************************/
};