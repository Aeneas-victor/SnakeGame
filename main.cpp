#include"Snake.h"//��Snake.h���Ѱ�����common.hͷ�ļ�
//�����ظ������������״��
HWND DesktopHandle;
int main()
{
	int youinput;
	cout << "Welcome to my Game Box" << endl;
	cout << "plase input you select" << endl;
	cin >> youinput;
	thread snakemode(SnakeMode);
	snakemode.join();
}