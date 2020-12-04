#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"
#include "book.h"

#define CLEAR_SCREEN system("cls");

#define LEFTKEY 0x4B
#define RIGHTKEY 0x4D
#define ENTER 13
#define ESC 27

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void paintTable()
{
    int totalSpace = 100, totalColun = 26, startPaint;

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

    for (startPaint = 1; startPaint <= totalColun; startPaint++)
    {
        gotoxy(2, startPaint);
        printf("|");
        gotoxy(97, startPaint);
        printf("|");
    }
}

void textColor(int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= iColor);
}

void textBackground(int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= (iColor << 4));
}

int selectRoute(int start, int end, int y)
{
    int startPoint = start, endPoint = end, point;
    point = start;
    char cOption = ' ';

    while (cOption != ENTER || cOption != ESC)
    {
        cOption = getch();

        if (cOption == RIGHTKEY)
        {
            if (startPoint + 20 <= end)
            {
                startPoint += 20;
                gotoxy(startPoint - 20, y);
                printf(" ");
                gotoxy(startPoint, y);
                printf("=");
            }
            else
            {
                gotoxy(startPoint, y);
                printf(" ");
                startPoint = start;
                gotoxy(startPoint, y);
                printf("=");
            }

            point = startPoint;
        }

        if (cOption == LEFTKEY)
        {
            if (endPoint - 20 >= start)
            {
                endPoint -= 20;
                gotoxy(endPoint + 20, y);
                printf(" ");
                gotoxy(endPoint, y);
                printf("=");
            }
            else
            {
                gotoxy(endPoint, y);
                printf(" ");
                endPoint = end;
                gotoxy(endPoint, y);
                printf("=");
            }

            point = endPoint;
        }

        if (cOption == ENTER)
        {

            if (point == 11 || point == 26 || point == 36)
                return 1;
            else if (point == 46 || point == 56 || point == 31)
                return 2;
            else if (point == 66 || point == 51)
                return 3;
            else if (point == 71)
                return 5;
            else
                return 4;
        }

        if (cOption == ESC)
        {
            return 4;
        }
    }
}

void routes(int panel, int option)
{
    if (panel == 2 && option == 1)
    {
        registerBook();
    }

    if (panel == 2)
    {
        if (option == 2)
            removeBook();
        else if (option == 3)
            changeBook();
        else if (option == 5)
        {
            CLEAR_SCREEN;
            addPageComponent();

            gotoxy(45, 1);
            printf("[ADMINISTRADOR]");
            gotoxy(35, 5);
            showBooks();
            gotoxy(30, 18);
            system("pause");
        }
    }

    CLEAR_SCREEN;

    if (panel == 1)
    {
        if (option == 1)
        {
            addPageComponent();
            gotoxy(45, 1);
            textColor(0);
            textBackground(4);
            printf("[LIVROS]");
            showBooks();

            optionsMenu();
        }
        else if (option == 2)
            searchBook();
        else if (option == 3)
            buyBook();
    }

    CLEAR_SCREEN;
}

void addPageComponent()
{
    textColor(4);
    paintTable();
    gotoxy(45, 25);
    printf("biBlio v2.0");
}