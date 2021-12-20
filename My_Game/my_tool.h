#pragma once
#include <windows.h>
void My_SetConsoleOutputPos(int x, int y);
void My_HideCursor();
bool My_WriteChar(const char* pChar, const int& nX, const int& nY, WORD attr);
bool My_SetWindowSize(const char* pTitle, const int& nWid, const int& nHeight);

