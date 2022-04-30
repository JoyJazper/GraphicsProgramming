#include "MainWindow.h"
#include "Game.h"

using namespace std;

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (x_mobile < 789) {
			x_mobile = x_mobile + 1;
		}
		else {
			x_mobile = 10;
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (x_mobile > 10) {
			x_mobile = x_mobile - 1;
		}
		else {
			x_mobile = 789;
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (y_mobile > 10) {
			y_mobile = y_mobile - 1;
		}
		else {
			y_mobile = 589;
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (y_mobile < 589) {
			y_mobile = y_mobile + 1;
		}
		else {
			y_mobile = 10;
		}
	}

	x_mobile = ClampScreenX(x_mobile);
	y_mobile = ClampScreenY(y_mobile);

	colliding =
		OverlapTest(x_fixed0, y_fixed0, x_mobile, y_mobile) ||
		OverlapTest(x_fixed1, y_fixed1, x_mobile, y_mobile) ||
		OverlapTest(x_fixed2, y_fixed2, x_mobile, y_mobile) ||
		OverlapTest(x_fixed3, y_fixed3, x_mobile, y_mobile);
}

void Game::ComposeFrame()
{
	DrawEnemy(x_fixed0, y_fixed0, 0, 255, 0);
	DrawEnemy(x_fixed1, y_fixed1, 0, 255, 0);
	DrawEnemy(x_fixed2, y_fixed2, 0, 255, 0);
	DrawEnemy(x_fixed3, y_fixed3, 0, 255, 0);

	if (colliding)
	{
		DrawBox(x_mobile, y_mobile, 255, 0, 0);
	}
	else
	{
		DrawBox(x_mobile, y_mobile, 255, 255, 255);
	}
}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(-5 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, -4 + y, r, g, b);
	gfx.PutPixel(-5 + x, -3 + y, r, g, b);
	gfx.PutPixel(-4 + x, -5 + y, r, g, b);
	gfx.PutPixel(-3 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 4 + y, r, g, b);
	gfx.PutPixel(-5 + x, 3 + y, r, g, b);
	gfx.PutPixel(-4 + x, 5 + y, r, g, b);
	gfx.PutPixel(-3 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, -4 + y, r, g, b);
	gfx.PutPixel(5 + x, -3 + y, r, g, b);
	gfx.PutPixel(4 + x, -5 + y, r, g, b);
	gfx.PutPixel(3 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 3 + y, r, g, b);
	gfx.PutPixel(4 + x, 5 + y, r, g, b);
	gfx.PutPixel(3 + x, 5 + y, r, g, b);
}

bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
	const int left_box0 = box0x - 20;
	const int right_box0 = box0x + 20;
	const int top_box0 = box0y - 20;
	const int bottom_box0 = box0y + 20;

	const int left_box1 = box1x - 5;
	const int right_box1 = box1x + 5;
	const int top_box1 = box1y - 5;
	const int bottom_box1 = box1y + 5;

	return
		left_box0 <= right_box1 &&
		right_box0 >= left_box1 &&
		top_box0 <= bottom_box1 &&
		bottom_box0 >= top_box1;
}

void Game::DrawEnemy(int x, int y, int r, int g, int b) 
{
	gfx.PutPixel(-5 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, -4 + y, r, g, b);
	gfx.PutPixel(-5 + x, -3 + y, r, g, b);
	gfx.PutPixel(-4 + x, -5 + y, r, g, b);
	gfx.PutPixel(-3 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 4 + y, r, g, b);
	gfx.PutPixel(-5 + x, 3 + y, r, g, b);
	gfx.PutPixel(-4 + x, 5 + y, r, g, b);
	gfx.PutPixel(-3 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, -4 + y, r, g, b);
	gfx.PutPixel(5 + x, -3 + y, r, g, b);
	gfx.PutPixel(4 + x, -5 + y, r, g, b);
	gfx.PutPixel(3 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 3 + y, r, g, b);
	gfx.PutPixel(4 + x, 5 + y, r, g, b);
	gfx.PutPixel(3 + x, 5 + y, r, g, b);
}

void Game::ContainBox()
{
	const int left = x_mobile - 10;
	const int right = x_mobile + 10;
	const int top = y_mobile - 10;
	const int bottom = y_mobile + 10;

	if (left < 0)
	{
		x_mobile = 5;
	}
	else if (right >= gfx.ScreenWidth)
	{
		x_mobile = gfx.ScreenWidth - 6;
	}

	if (top < 0)
	{
		y_mobile = 5;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		y_mobile = gfx.ScreenHeight - 6;
	}
}

int Game::ClampScreenX(int x)
{
	const int left = x - 5;
	const int right = x + 5;

	if (left < 0)
	{
		return 5;
	}
	else if (right >= gfx.ScreenWidth)
	{
		return gfx.ScreenWidth - 6;
	}
	else
	{
		return x;
	}
}

int Game::ClampScreenY(int y)
{
	const int top = y - 5;
	const int bottom = y + 5;

	if (top < 0)
	{
		return 5;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		return gfx.ScreenHeight - 6;
	}
	else
	{
		return y;
	}
}
