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

void hotBooks()
{
    gotoxy(34, 15);
    printf("Nossos livros mais vendidos:");
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

            if (point == 11)
                return 1;
            else if (point == 26)
                return 1;
            else
                return 4;
        }

        if (cOption == ESC)
        {
            return 4;
        }
    }
}

void buyList()
{
    int i;

    gotoxy(10, 12);
    textColor(12);
    printf("Meu carrinho:");
    gotoxy(10, 13);
    textColor(6);

    for (i = 0; i < 10; i++)
    {
        gotoxy(30, 13 + i);
        printf("|");
        gotoxy(55, 13 + i);
        printf("|");
        gotoxy(85, 13 + i);
        printf("|");
    }

    gotoxy(10, 13);
    printf("TITULO");
    gotoxy(35, 13);
    printf("AUTOR");
    gotoxy(60, 13);
    printf("GENERO");
    gotoxy(87, 13);
    printf("PRECO");

    gotoxy(10, 14);
    printf("O Nome do Vento");
    gotoxy(35, 14);
    printf("Patrick Rothfulls");
    gotoxy(60, 14);
    printf("fantasia, aventura");
    gotoxy(87, 14);
    printf("R$ 36.99");
}

void routes(int panel, int option)
{
    if (panel == 2 && option == 1)
    {
        registerBook();
    }

    CLEAR_SCREEN;

    if (panel == 1)
    {
        if (option == 1)
        {
            showBooks();
            
            gotoxy(35, 22);
            printf("[ ] - COMPRAR");
            gotoxy(55, 22);
            printf("[ ] - VOLTAR");
            gotoxy(36, 22);
            textColor(4);
            printf("=");
            selectRoute(36, 56, 22);
        }
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