#include "my_tool.h"
#include <iostream>



void My_SetConsoleOutputPos(int x, int y)
{
	HANDLE app;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	app = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(app, pos);
}

void My_HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

bool My_WriteChar(const char *pChar,const int& nX,const int& nY,WORD attr)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO stc = {};
	stc.bVisible = FALSE;
	stc.dwSize = 1;
	SetConsoleCursorInfo(handle, &stc);
	COORD cr = { 2 * nX,nY };
	SetConsoleCursorPosition(handle, cr);// …Ë÷√◊÷ÃÂ Ù–‘
	SetConsoleTextAttribute(handle, attr);
	printf(pChar);
	return true;
}

bool My_SetWindowSize(const char* pTitle,const int& nWid, const int& nHeight)
{
	SetConsoleTitleA(pTitle);
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT sr;
	sr.Bottom = nHeight;
	sr.Left = 0;
	sr.Right = nWid;
	sr.Top = 0;
	SetConsoleWindowInfo(hand, true, &sr);
	COORD cd = { nWid + 1,nHeight + 1 };
	SetConsoleScreenBufferSize(hand, cd);
	return true;
}
