#include"Snake.h"//在Snake.h中已包含过common.h头文件
//不在重复包含，，，易错点
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