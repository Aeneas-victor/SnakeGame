//#include"common.h"
//#include<iostream>
//#include<vector>
//#include<Windows.h>
//using namespace std;
////BOOL CALLBACK表示一个回调函数的返回值为布尔值
////LPARAM  //windows中的一个表示长整型的参数
//BOOL CALLBACK EnumerationWindowProc(HWND hwnd, LPARAM parametric)
//{
//	std::vector<HWND>* WindowsDesktopHandle = (std::vector<HWND>*)parametric;
//	//创建一个vector储存所有类名为WorkerW的句柄
//	char ClassName[256];
//	GetClassName(hwnd, ClassName, sizeof(ClassName));
//	//GetClassName函数需要知道ClassName缓冲区的大小，以确保它不会写入超出缓冲区边界的数据。
//	//所以使用sizeof动态获取ClassName的大小
//	if (strcmp(ClassName, "WorkerW") == 0||strcmp(ClassName,"Progman")==0)
//	{
//		// 找到类名为"WorkerW"的窗口，记录下来
//		//因为存在多个顶级窗口类名都为“WorkerW"的情况
//		WindowsDesktopHandle->push_back(hwnd);
//	}
//	return TRUE;
//}
//std::vector<HWND> EnumerationWindowHandle()
//{
//	std::vector<HWND>WorkerWHandle;
//	// 枚举所有顶级窗口
//	EnumWindows(EnumerationWindowProc, (LPARAM)&WorkerWHandle);
//	return WorkerWHandle;
//}
