#include"Game.h"
Game::Game()
{
	desktop= GetDesktopHandle();
    cout << "Game::Game()->win" << endl;
    cout << "HWND:" << desktop << endl;
}
//HWND Game::GetDesktopHandle()//��Ҫ��ȡ������;����ֻ��ȡһ�Σ�ʣ����һ�������Getdesktop������ȡ
//{//////����������ʹ��function.cpp�еĻص�����
//	std::vector<HWND>WorkerWHandle = EnumerationWindowHandle();
//	if (!WorkerWHandle.empty()) {
//		//for (std::vector<HWND>::iterator it = WorkerWHandle.begin(); it != WorkerWHandle.end(); it++){
//		for (HWND hwnd : WorkerWHandle) {
//			//��������vector�����������Ӵ���
//			HWND SHELLDLLDefView = FindWindowExA(hwnd, NULL, "SHELLDLL_DefView", NULL);
//			if (SHELLDLLDefView == NULL) {
//				continue;
//			}
//			else {
//				HWND HwndSysListView32 = FindWindowExA(SHELLDLLDefView, NULL, "SysListView32", NULL);
//				if (HwndSysListView32 == NULL) {
//					continue;
//				}
//				else {
//					cout << "GetdesktopMain->win" << endl;
//					return HwndSysListView32;
//				}
//			}
//		}
//	}
//	else
//	{
//		cout << "GetdesktopMain->fail" << endl;
//		return NULL;
//	}
//}
HWND Game::GetDesktopHandle()//��Ҫ��ȡ������;����ֻ��ȡһ�Σ�ʣ����һ�������Getdesktop������ȡ
{//////////����һ
    HWND DesktopHandle = GetDesktopWindow();
    HWND WorkerWHandle = NULL;
    HWND SHELLDLLDefViewHandle = NULL;
    HWND SysListView32Handle = NULL;
    HWND ProgmanHandle = NULL;
    ProgmanHandle = FindWindowExA(DesktopHandle, NULL, "Progman", NULL);
    SHELLDLLDefViewHandle = FindWindowExA(ProgmanHandle, NULL, "SHELLDLL_DefView", NULL);
    if (SHELLDLLDefViewHandle == NULL) {
        WorkerWHandle = FindWindowExA(DesktopHandle, WorkerWHandle, "WorkerW", NULL);
        SHELLDLLDefViewHandle = FindWindowExA(WorkerWHandle, NULL, "SHELLDLL_DefView", NULL);
        while (SHELLDLLDefViewHandle == NULL && WorkerWHandle != NULL) {
            WorkerWHandle = FindWindowExA(DesktopHandle, WorkerWHandle, "WorkerW", NULL);
            SHELLDLLDefViewHandle = FindWindowExA(WorkerWHandle, NULL, "SHELLDLL_DefView", NULL);
        }
    }
    SysListView32Handle = FindWindowExA(SHELLDLLDefViewHandle, NULL, "SysListView32", NULL);
    return SysListView32Handle;
}
void Game::Gameinit()//��Ϸ��ʼ��������ͼ�꣬
{
    //��������ʽȡ��/////////////////////////////////////////////////////////////////
    DWORD style = ListView_GetExtendedListViewStyle(desktop, GWL_EXSTYLE);
    if (style & LVS_EX_SNAPTOGRID)
    {
        ListView_SetExtendedListViewStyle(desktop, style & ~LVS_EX_SNAPTOGRID);
    }
    ///////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////��ȡ�ؼ�����
     
    iconCount = SendMessage(desktop, LVM_GETITEMCOUNT, 0, 0);
    //Get  Systemϵͳ
    //   Metrics ������ָ��
    //   SM_CXSCREEN
    // //GetSystemMetrics
    //����ָ����ϵͳָ���ϵͳ�������á�
   // ��ע�⣬ GetSystemMetrics ����������ά�ȶ�������Ϊ��λ��
    Width = GetSystemMetrics(SM_CXSCREEN)*1.5; //��ȡ��Ļ�ķֱ���(��)
    Height = GetSystemMetrics(SM_CYSCREEN) *1.5;//���豸���õ�DPI���ţ�ʹ��Ϊ150%;���Ի�ȡʹ�������1.5
    //����λ��Ϊ  x=30   y=1380  ���½�λ��,
//������Ļ�߽�Ϊ
    int screenx = 30;
    int screeny = Height - BORDER;
   // POINT iconposition;

    //��������ͼ��
    std::cout << iconCount << endl;
    for (int i = 0; i < iconCount; i++)
    {
        //ListView_SetItemPosition(desktop, i,screenx, screeny);
         SendMessageA(desktop, LVM_SETITEMPOSITION,i, MAKELONG(screenx,screeny));
        //////////�ƶ�λ�ú���
        /*SendMessageA(desktop, LVM_SETITEMPOSITION, i, (screeny << 16) + screenx);*/
    }////////////����λ�ú���
    cout << "Width:" << Width << "   " << "Height" <<Height<< endl;
}
int Game::GetWidth()//��Ļ��
{

    return Width;
}

int Game::GetHeight()//��Ļ��
{
    return Height;
}

int Game::GetIconCount()
{
    return iconCount;
}

void Game::DesktopLayout()
{
 
}


HWND Game::Getdesktop()//��ȡ�ѻ�õ�desktop�ľ��
{
    return desktop;
}

