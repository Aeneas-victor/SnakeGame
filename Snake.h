#pragma once
#include"common.h"
class Game;
class Snake {
public:
	enum Dir { UP = 0, DOWN, LEFT, RIGHT };
	Snake();
	~Snake();
	void MoveSnake();
	void SnakeInput();
	void DramSnake();
	bool GameOver();
	int Getfoodx();
	int Getfoody();
	void GameAgain();
	void Music(int a);
	size_t GetdnSnakeSize();
	int Gamebox();
	int sftW;//SnakeFileTempWidth
	int sftH;//SnakeFileTempHeight
private:
	Game* pdesktop;
	vector<POINT>snake;
	POINT food;
	Dir direction;
};