#include "Snake.h"
#include"Game.h"

Snake::Snake():pdesktop(new Game)//Snake��Ĺ��캯��ʹ�ó�ʼ���б�����ʼ��ָ���Ա����pDesktop
{
	Music(1);
	pdesktop->Gameinit();
	cout << "Gameinit->win" << endl;
	snake.push_back({ 240,240 });
	cout << "Snake::Snake():pdesktop(new Game)->initialize complete!" << endl;
	direction= Dir::UP;
	srand(time(0));
	food.x = (rand() % (pdesktop->GetWidth()-ICONSIZE) + 1) / ICONSIZE * ICONSIZE;
	food.y = (rand() % (pdesktop->GetHeight()-2*ICONSIZE) + 1) / ICONSIZE * ICONSIZE;
	cout << "food.x:" << food.x << endl;
	cout << "food.y:" << food.y << endl;
}

Snake::~Snake()
{

}
void Snake::MoveSnake()
{
	//����ÿһ����������������һ�ڵ������ʹ�������ƶ�
	for (size_t i = snake.size() - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	sftW = pdesktop->GetWidth()-ICONSIZE;//��ȥICONSIZE����������Ļ�ڣ�ͼ�걾���п��
	//SnakeFileTempWidth 
	sftH=pdesktop->GetHeight()-2*ICONSIZE;//��ȥ������ICONSIZE��ȥ״̬����ռ�ռ�
	//SnakeFileTempHeight
	//���Ƴ�������direction�ƶ�
	snake[0].x = direction == LEFT ? (snake[0].x-ICONSIZE+sftW)%sftW : direction == RIGHT ?  (snake[0].x+ICONSIZE+sftW)%sftW : snake[0].x;
	snake[0].y = direction == UP ? (snake[0].y-ICONSIZE+sftH)%sftH : direction == DOWN ? (snake[0].y+ICONSIZE+sftH)%sftH : snake[0].y;
	//������һ����Χ��ѭ�������������鷳�Ĵ�ǽ��·�ж�

	//���ƴ�ǽ
	/*if (snake[0].x <= -10)
		snake[0].x = pdesktop->GetWidth() - BORDER;
	if (snake[0].x >= pdesktop->GetWidth())
		snake[0].x = 0;
	if (snake[0].y <= 0)
		snake[0].y = pdesktop->GetHeight() - BORDER;
	if (snake[0].y >= pdesktop->GetHeight())
		snake[0].y = 0;
	*/
}

void Snake::SnakeInput()
{/////////Get Async �첽����ͬ��
	//Key  State///////////////////�첽�������������ؼ���״̬�������谭���̵�����
	if ((GetAsyncKeyState(0x57)|| GetAsyncKeyState(VK_UP))&&direction!=DOWN)//w,UP
		direction = UP;//ǰ�������DOWN���UP
	if ((GetAsyncKeyState(0x53) || GetAsyncKeyState(VK_DOWN))&&direction!=UP)//s,DOWN
		direction = DOWN;
	if ((GetAsyncKeyState(0x41)|| GetAsyncKeyState(VK_LEFT))&&direction!=RIGHT)//a,LEFT
		direction = LEFT;
	if ((GetAsyncKeyState(0x44)|| GetAsyncKeyState(VK_RIGHT))&&direction!=LEFT)//d,RIGHT
		direction = RIGHT;
}

void Snake::DramSnake()
{
	for (int i = 0; i < snake.size(); i++)
	{////////////////////////////////////////////////////////////////��16λΪy����16λΪx
		SendMessageA(pdesktop->Getdesktop(), LVM_SETITEMPOSITION, i, (snake[i].y << 16) + snake[i].x);
	}
	SendMessageA(pdesktop->Getdesktop(), LVM_SETITEMPOSITION, snake.size(), MAKELONG(food.x, food.y));
	//////////////////////////////////////////////////////////////////////////////MAKELONG  ���������µĳ�����
   //////////////////////////////////////////////////////////////////////////////ͬ�����÷���һ������Ϊ��λ���ڶ���Ϊ��λ������16λ
	//snake[0].x<=food.x&&snake[0].y<=food.y&&snake[0].x<=Getfoodx()&&snake[0].y<=Getfoody()
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		cout << "snake.size()" << snake.size() << endl;
		POINT NewNode({ food.x,food.y });
		snake.push_back(NewNode);
		srand(time(0));
		food.x = (rand() % (pdesktop->GetWidth() - ICONSIZE) + 1) / ICONSIZE * ICONSIZE;
		///////////////////////////////////////////////////////���������������ICONSIZE�ı���
		food.y = (rand() % (pdesktop->GetHeight() - 2 * ICONSIZE) + 1) / ICONSIZE * ICONSIZE;
		cout << "food.x:" << food.x << endl;
		cout << "food.y:" << food.y << endl;
	}
}


bool Snake::GameOver()
{
	for (vector<POINT>::iterator it = snake.begin()+1; it != snake.end(); it++)
	{
		if (snake[0].x == (*it).x && snake[0].y == (*it).y)
		{
			return true;
		}
	}
	return false;
}

int Snake::Getfoodx()
{
	return food.x+ICONSIZE;
}

int Snake::Getfoody()
{
	return food.y+ICONSIZE;
}

void Snake::GameAgain()
{
	pdesktop->Gameinit();
}

void Snake::Music(int a)
{
	if(a==1)
	{
		// �������ļ�
		mciSendString("open Metrohead.mp3 type mpegvideo alias myMusic", NULL, 0, NULL);
		// ��������
		mciSendString("play myMusic", NULL, 0, NULL);
	}
	if(a==2)
	{
		// �ȴ����ֲ������
		// Sleep(5000); // �ȴ�5��
		//// ֹͣ����
		mciSendString("stop myMusic", NULL, 0, NULL);
		//// �ر������ļ�
		mciSendString("close myMusic", NULL, 0, NULL);
	}
}

size_t Snake::GetdnSnakeSize()
{
	return snake.size();
}

int Snake::Gamebox()
{
	return MessageBox(pdesktop->Getdesktop(), " ��Ϸ����", "�Ƿ����¿�ʼ", MB_YESNO);
}
