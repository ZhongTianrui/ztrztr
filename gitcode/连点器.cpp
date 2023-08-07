#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
void L_Down() {
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
}
void L_Up() {
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
 
}
void R_Down() {
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
}
void R_Up() {
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
int main() {
	printf("鼠标连点器1.0\n按下F7左键连点\n按下F8右键连点\n按下Esc结束连点\n注：输入间隔时间后要等待3秒\n");
	while(1) {
		if(KEY_DOWN(VK_F7)) {
			printf("输入间隔时间(单位:毫秒):");
			int s;
			bool ok=1;
			scanf("%d",&s);
			Sleep(3000);
			while(1) {
				if(ok==0)
					break;
				L_Down();
				L_Up();
				for(int i=1; i<=s*100000; i++)
					if(KEY_DOWN(VK_ESCAPE)) {
						ok=0;
						break;
					}
			}
		}
		if(KEY_DOWN(VK_F8)) {
			printf("输入间隔时间(单位:毫秒):");
			int s;
			bool ok=1;
			scanf("%d",&s);
			Sleep(3000);
			while(1) {
				if(ok==0)
					break;
				R_Down();
				R_Up();
				for(int i=1; i<=s*100000; i++)
					if(KEY_DOWN(VK_ESCAPE)) {
						ok=0;
						break;
					}
			}
		}
	}
 
 
	return 0;
}