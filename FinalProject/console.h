#pragma once
#include <Windows.h>
#include <Shlwapi.h>
#include <conio.h>

void FixConsoleWindow();
void resizeConsole(int width, int height);
void gotoxy(SHORT x, SHORT y);
void setColor(WORD color);
void setBackgroundColor(WORD color);
