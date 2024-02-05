#include"Snake.h"
bool game(false);
bool GamePause = false;
void SnakeMode()
{
	Snake* psnake = new Snake;
	cout << "Game is begin!" << endl;
	while (!game)
	{
 		if (GetAsyncKeyState(VK_SPACE) & 0x8000) // 检测空格键按下
		{
			if (GamePause)
			{
				// 按下空格键，切换为继续游戏
				GamePause = false;
			}
			else
			{
				// 按下空格键，切换为暂停游戏
				GamePause = true;
				int result = MessageBox(GetDesktopWindow(), "是否继续游戏?", "暂停", MB_YESNO);
				if (result == IDYES)
				{
					GamePause = false; // 用户选择继续游戏
				}
			}
		}
		if (psnake->GameOver()) {
			cout << "Game is over" << endl;
			MessageBox(GetDesktopWindow(), "撞到蛇身了", "Game Over!", MB_OK);	
			game = true;
			break;
		}
		psnake->DramSnake();		
		psnake->SnakeInput();
		psnake->MoveSnake();
		Sleep(100);
	}
	psnake->Music(2);
}
