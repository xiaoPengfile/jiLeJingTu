#include<iostream>
#include<windows.h>
#include<graphics.h>
#include<MMSystem.h>//����������Ҫ��ͷ�ļ�
#pragma comment(lib,"winmm.lib")//���߱�����,����winmm.lib���ļ�(����ʱָ�����ļ�)  pragma ����ָʾ comment����
#define COUNT 148
using namespace std;

int main(void) {
	cout << "���ڼ���......" << endl;
	IMAGE images[COUNT];
	char fileName[128];
	for (int i = 1; i <= COUNT; i++) {
		sprintf_s(fileName,128, "images2\\_%04d_ͼ��-%d.jpg", COUNT - i, i);
		loadimage(&images[i-1], fileName);
	}
	initgraph(800, 513);
	loadimage(0, _T("jile.jpg"));
	mciSendString(_T("play ���־���.mp3 repeat"), 0, 0, 0); //�ظ����ż��־���   �ǲ������ֵ�һ���ӿ�(MMSystem.h)
	/*******************************************************
	*****mciý����ƽӿڣ�Media Control Interface�� send���� 
	*****����һ�������ַ�����ý����ƽӿ�
	*****play�п�����Ϸ����˼,�������ǲ���  repeat�ظ�
	*******************************************************/
	//_T("")ת������Ҫ�ı����ʽ
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