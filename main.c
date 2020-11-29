// BIBLIOTECAS
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"

#define WAIT sleep(2);
#define CLEAR_SCREEN system("cls");

#define KEY_LEFT 0x4B
#define KEY_RIGHT 0x4D

int ENTER = 13;
int ESC = 27;
int KEYUP = 72;
int KEYDOWN = 80;

int main()
{
    int option = 1;
    char cOption = ' ';

    while (cOption != ESC)
    {
        CLEAR_SCREEN;

        textColor(4);
        paintTable();

        gotoxy(30, 1);
        textColor(0);
        textBackground(4);
        printf("Bem vindo a BiBlio,");
        gotoxy(35, 2);
        printf("a sua biblioteca do terminal!\n");
        gotoxy(45, 25);
        printf("biBlio v2.0");

        textColor(12);
        textBackground(0);
        hotBooks();

        textColor(8);
        textBackground(0);

        gotoxy(37, 6);
        printf("Como deseja continuar?");
        gotoxy(37, 8);
        printf("[ ] - Cliente");
        gotoxy(37, 9);
        printf("[ ] - Administrador");
        gotoxy(37, 11);
        printf("Para SAIR aperte ESC.");

        gotoxy(38, 8);
        textColor(12);
        printf("@");
        while (cOption != ENTER)
        {
            cOption = getch();

            if (cOption == KEYDOWN)
            {
                gotoxy(38, 8);
                printf(" ");
                gotoxy(38, 9);
                printf("@");
                option = 2;
            }

            if (cOption == KEYUP)
            {
                gotoxy(38, 9);
                printf(" ");
                gotoxy(38, 8);
                printf("@");
                option = 1;
            }

            if (cOption == ESC)
            {
                gotoxy(1, 28);
                textColor(15);
                return 0;
            }
        }

        if (option != 0)
        {
            int start = 26, end = 66;

            CLEAR_SCREEN;

            textColor(4);
            paintTable();
            gotoxy(45, 25);
            printf("biBlio v2.0");

            if (option == 1)
            {
                while (option != 4)
                {
                    // CLIENTE
                    gotoxy(45, 1);
                    printf("[CLIENTE]");
                    gotoxy(30, 5);
                    textColor(8);
                    printf("Escolha uma das opcoes para continuar: ");
                    gotoxy(25, 7);
                    printf("[ ] - Ver catalogo | ");
                    gotoxy(45, 7);
                    printf("[ ] - Pesquisar | ");
                    gotoxy(65, 7);
                    printf("[ ] - Comprar");
                    gotoxy(40, 8);
                    printf("Aperte ESC para voltar.");

                    buyList();

                    gotoxy(start, 7);
                    textColor(12);
                    printf("=");

                    option = selectRoute(start, end, 7);
                }

                cOption = ' ';
                option = 1;
            }
            else if (option == 2)
            {
                // ADMINISTRADOR
                gotoxy(37, 9);
                printf("Area em construcao.\n");
                cOption = ' ';
                option = 1;
                system("pause");
            }
        }
    }

    gotoxy(1, 28);
    textColor(15);
    return 0;
}