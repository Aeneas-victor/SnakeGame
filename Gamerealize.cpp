#include"Snake.h"
bool game(false);
bool GamePause = false;
void SnakeMode()
{
	Snake* psnake = new Snake;
	cout << "Game is begin!" << endl;
	while (!game)
	{
 		if (GetAsyncKeyState(VK_SPACE) & 0x8000) // ���ո������
		{
			if (GamePause)
			{
				// ���¿ո�����л�Ϊ������Ϸ
				GamePause = false;
			}
			else
			{
				// ���¿ո�����л�Ϊ��ͣ��Ϸ
				GamePause = true;
				int result = MessageBox(GetDesktopWindow(), "�Ƿ������Ϸ?", "��ͣ", MB_YESNO);
				if (result == IDYES)
				{
					GamePause = false; // �û�ѡ�������Ϸ
				}
			}
		}
		if (psnake->GameOver()) {
			cout << "Game is over" << endl;
			MessageBox(GetDesktopWindow(), "ײ��������", "Game Over!", MB_OK);	
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
