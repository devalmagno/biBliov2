// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"
#include "book.h"

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

    FILE *fp;

    openBookArchive();

    fp = fopen("data.txt", "rb+");
    if (fp == NULL)
    {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL)
        {
            printf("Nao foi possivel criar data.txt!\n");
            exit(1);
        }
    }

    readValues();

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
        // hotBooks();

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

            if (option == 1)
            {
                while (option != 4)
                {
                    addPageComponent();
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
                    routes(1, option);
                }

                cOption = ' ';
                option = 1;
            }
            else if (option == 2)
            {
                // ADMINISTRADOR
                int password = 123456, typedPassword = 0;

                addPageComponent();

                gotoxy(45, 1);
                printf("[ADMINISTRADOR]");
                gotoxy(35, 5);
                textColor(8);
                printf("Para continuar faca o login:");
                gotoxy(35, 6);
                printf("senha: ");
                gotoxy(42, 6);
                scanf("%d", &typedPassword);

                if (password == typedPassword)
                {
                    CLEAR_SCREEN;

                    addPageComponent();

                    while (option != 4)
                    {
                        addPageComponent();
                        gotoxy(45, 1);
                        textColor(0);
                        textBackground(4);
                        printf("[ADMINISTRADOR]");

                        gotoxy(35, 5);
                        textBackground(0);
                        textColor(8);
                        printf("Escolha uma das opcoes para continuar: ");
                        gotoxy(10, 7);
                        printf("[ ] - Cadastrar |");
                        gotoxy(30, 7);
                        printf("[ ] - Remover  |");
                        gotoxy(50, 7);
                        printf("[ ] - Alterar |");
                        gotoxy(70, 7);
                        printf("[ ] - Ver catalogo");
                        gotoxy(43, 9);
                        printf("Para SAIR aperte ESC");

                        gotoxy(11, 7);
                        textColor(12);
                        printf("=");

                        option = selectRoute(11, 71, 7);
                        routes(2, option);
                    }
                }
                else
                {
                    gotoxy(30, 8);
                    printf("senha incorreta.");
                    gotoxy(30, 10);
                    system("pause");
                }

                cOption = ' ';
                option = 1;
            }
        }
    }

    saveBook();
    fclose(fp);
    closeBookArchive();
    gotoxy(1, 28);
    textColor(15);
    return 0;
}