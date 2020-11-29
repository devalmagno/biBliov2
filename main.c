// BIBLIOTECAS
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"

#define WAIT sleep(2);
#define CLEAR_SCREEN system("cls");

#define KEY_LEFT  0x4B
#define KEY_RIGTH 0x4D

int ENTER = 13;
int ESC = 27;
int KEYUP = 72;
int KEYDOWN = 80;

int main()
{
    int option;
    char cOption = ' ';

    CLEAR_SCREEN;

    textColor(4);
    paintTable();

    gotoxy(50, 1);
    textColor(0);
    textBackground(4);
    printf("Bem vindo a BiBlio,");
    gotoxy(55, 2);
    printf("a sua biblioteca do terminal!\n");
    gotoxy(60, 25);
    printf("biBlio v2.0");

    textColor(12);
    textBackground(0);
    hotBooks();

    textColor(8);
    textBackground(0);
    while (cOption != ESC)
    {
        gotoxy(55, 6);
        printf("Como deseja continuar?");
        gotoxy(55, 8);
        printf("[ ] - Cliente");
        gotoxy(55, 9);
        printf("[ ] - Administrador");
        gotoxy(55, 11);
        printf("Para SAIR aperte ESC.");

        gotoxy(56, 8);
        while (cOption != ENTER)
        {
            cOption = getch();
            option = 1;

            if (cOption == KEYDOWN)
            {
                gotoxy(56, 9);
                option = 1;
            }

            if (cOption == KEYUP)
            {
                gotoxy(56, 8);
                option = 2;
            }

            if (cOption == ESC)
            {
                gotoxy(1, 28);
                textColor(15);
                return 0;
            }
        }
    }

    gotoxy(1, 28);
    textColor(15);
    return 0;
}