#pragma once
#include"common.h"
class Game {
public:
	Game();
	void Gameinit();
	int GetWidth();
	int GetHeight();
	int GetIconCount();
	void DesktopLayout();
	HWND GetDesktopHandle();
	HWND Getdesktop();

private:
	HWND desktop;
	double Width;
	double Height;
	LRESULT iconCount;


};