#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <MMSystem.h> //播放音乐的头文件
#pragma comment (lib,"winmm.lib")//告诉编译器，加载winmm.lib库文件

#define	COUNT1 148
#define COUNT2 80

int main(void) {

	IMAGE picture[COUNT1];
	char tmp[COUNT2];

	printf("\n\n\n\n\n                                Loading !......");

	
	for (int i = 1; i <= COUNT1; i++) {

		sprintf_s(tmp, "E:\\vs2015\\极乐净土\\picture\\_%04d_图层-%d.jpg", COUNT1 - i, i);
		loadimage(&picture[i-1], tmp);
	}

	initgraph(650, 450);

	setlinecolor(WHITE);
	setfillcolor(BLACK);

	fillrectangle(260, 109, 380,140);
	settextstyle(30, 0, "微软雅黑");
	outtextxy(268, 110, "请按a开始");
	fillrectangle(260, 159, 380, 190);
	outtextxy(268, 160, "请按b退出");

	//重复播放 极乐净土
	//mciSendString(_T("play 极乐净土.mp3 repeat"),0,0,0);

	//loadimage(0, _T("jile.jpg"));

	 

	while (1) {

		int kby;


		if(_kbhit()) {
			//mciSendString(_T("play 极乐净土.mp3 repeat"), 0, 0, 0);
			kby = _getch();
			if (kby == 'a') {
				mciSendString(_T("play 极乐净土.mp3 repeat"), 0, 0, 0);
				Sleep(500);
				while (1 == 1) {
					for (int i = 0; i < COUNT1; i++) {
						putimage(0, 0, &picture[i]);
						Sleep(80);
					}
				}
			}
			else {
				exit(0);
			}
		}
	}


	system("pause");
	closegraph();
	return 0;
}