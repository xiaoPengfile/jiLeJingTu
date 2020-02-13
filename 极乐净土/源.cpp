#include<iostream>
#include<windows.h>
#include<graphics.h>
#include<MMSystem.h>//播放音乐需要的头文件
#pragma comment(lib,"winmm.lib")//告诉编译器,加载winmm.lib库文件(链接时指定库文件)  pragma 编译指示 comment描述
#define COUNT 148
using namespace std;

int main(void) {
	cout << "正在加载......" << endl;
	IMAGE images[COUNT];
	char fileName[128];
	for (int i = 1; i <= COUNT; i++) {
		sprintf_s(fileName,128, "images2\\_%04d_图层-%d.jpg", COUNT - i, i);
		loadimage(&images[i-1], fileName);
	}
	initgraph(800, 513);
	loadimage(0, _T("jile.jpg"));
	mciSendString(_T("play 极乐净土.mp3 repeat"), 0, 0, 0); //重复播放极乐净土   是播放音乐的一个接口(MMSystem.h)
	/*******************************************************
	*****mci媒体控制接口（Media Control Interface） send发送 
	*****发送一个命令字符串到媒体控制接口
	*****play有开玩游戏的意思,在这里是播放  repeat重复
	*******************************************************/
	//_T("")转化成需要的编码格式
	initgraph(800, 450);
	while (1) {
		for (int i = 1; i <= COUNT; i++) {
			putimage(0, 0, &images[i - 1]);
			Sleep(80);
		}
	}


	system("pause");
	closegraph();

	return 0;
}