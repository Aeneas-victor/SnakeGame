//#include"common.h"
//#include<iostream>
//#include<vector>
//#include<Windows.h>
//using namespace std;
////BOOL CALLBACK��ʾһ���ص������ķ���ֵΪ����ֵ
////LPARAM  //windows�е�һ����ʾ�����͵Ĳ���
//BOOL CALLBACK EnumerationWindowProc(HWND hwnd, LPARAM parametric)
//{
//	std::vector<HWND>* WindowsDesktopHandle = (std::vector<HWND>*)parametric;
//	//����һ��vector������������ΪWorkerW�ľ��
//	char ClassName[256];
//	GetClassName(hwnd, ClassName, sizeof(ClassName));
//	//GetClassName������Ҫ֪��ClassName�������Ĵ�С����ȷ��������д�볬���������߽�����ݡ�
//	//����ʹ��sizeof��̬��ȡClassName�Ĵ�С
//	if (strcmp(ClassName, "WorkerW") == 0||strcmp(ClassName,"Progman")==0)
//	{
//		// �ҵ�����Ϊ"WorkerW"�Ĵ��ڣ���¼����
//		//��Ϊ���ڶ����������������Ϊ��WorkerW"�����
//		WindowsDesktopHandle->push_back(hwnd);
//	}
//	return TRUE;
//}
//std::vector<HWND> EnumerationWindowHandle()
//{
//	std::vector<HWND>WorkerWHandle;
//	// ö�����ж�������
//	EnumWindows(EnumerationWindowProc, (LPARAM)&WorkerWHandle);
//	return WorkerWHandle;
//}
