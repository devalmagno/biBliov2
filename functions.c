#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void paintTable()
{
    int totalSpace = 120, totalColun = 26, startPaint;

    gotoxy(0, 0);
    for (startPaint = 0; startPaint < totalSpace; startPaint++)
    {
        printf("=");
    }

    gotoxy(0, 27);
    for (startPaint = 0; startPaint < totalSpace; startPaint++)
    {
        printf("=");
    }

    for (startPaint = 1; startPaint <= totalColun; startPaint++) {
        gotoxy(5, startPaint);
        printf("|");
        gotoxy(115, startPaint);
        printf("|");
    }
}

void hotBooks() {
    gotoxy(52, 15);
    printf("Nossos livros mais vendidos:");
}

void textColor (int iColor)
{
       HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
       CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
       BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
       bufferInfo.wAttributes &= 0x00F0;
       SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void textBackground (int iColor)
{
       HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
       CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
       BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
       bufferInfo.wAttributes &= 0x000F;
       SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}