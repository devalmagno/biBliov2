#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "book.h"

#define CLEAR_SCREEN system("cls");

FILE *fp;

void registerBook()
{
    int registerLoop, i, j;

    gotoxy(35, 11);
    printf("Quantos livros voce deseja cadastrar?  ");
    scanf("%d", &registerLoop);

    if (registerLoop == 0)
    {
        gotoxy(35, 11);
        printf("                                            ");
        return;
    }

    CLEAR_SCREEN;

    addPageComponent();

    gotoxy(45, 1);
    textColor(0);
    textBackground(4);
    printf("[CADASTRAR LIVRO]");

    for (i = 0; i < registerLoop; i++)
    {
        gotoxy(10, 5);
        textBackground(0);
        textColor(8);
        printf("Digite as informacoes do livro para continuar... ");
        gotoxy(10, 7);
        printf("Nome: ");
        gotoxy(10, 8);
        printf("Autor: ");
        gotoxy(10, 9);
        printf("Genero: ");
        gotoxy(10, 10);
        printf("Preco: R$ ");

        textColor(6);
        gotoxy(68, 5);
        printf("Livro Registrado");
        gotoxy(86, 5);
        printf("Preco R$");
        gotoxy(66, 6);
        printf("_____________________");
        gotoxy(86, 6);
        printf("__________");
        gotoxy(65, 4);
        printf("_______________________");
        gotoxy(85, 4);
        printf("___________");
        gotoxy(66, 7 + registerLoop);
        printf("____________________");
        gotoxy(86, 7 + registerLoop);
        printf("__________");

        for (j = 0; j < registerLoop + 3; j++)
        {
            gotoxy(65, 5 + j);
            printf("|");
            gotoxy(85, 5 + j);
            printf("|");
            gotoxy(95, 5 + j);
            printf("|");
        }

        gotoxy(20, 7);
        textColor(15);
        scanf(" %[^\n]*%c\n ", &Book[i].bookName);
        gotoxy(20, 8);
        scanf(" %[^\n]*%c\n ", &Book[i].authorName);
        gotoxy(20, 9);
        scanf(" %[^\n]*%c\n ", &Book[i].bookGenre);
        gotoxy(20, 10);
        scanf("%lf", &Book[i].bookPrice);

        Book[i].ID = i;
        Book[i].exibir = 1;

        gotoxy(20, 7);
        printf("                    ");
        gotoxy(20, 8);
        printf("                    ");
        gotoxy(20, 9);
        printf("                    ");
        gotoxy(20, 10);
        printf("                    ");

        gotoxy(66, 7 + i);
        printf("%s", Book[i].bookName);
        gotoxy(86, 7 + i);
        printf("%.2lf", Book[i].bookPrice);
        
        gotoxy(20, 7);
    }

    gotoxy(30, 26);
    system("pause");
    CLEAR_SCREEN;
}

void openBookArchive()
{
    fp = fopen("data.txt", "rb+");
    if (fp == NULL)
    {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL)
        {
            printf("Não foi possivel criar o arquivo de dados.\n");
            exit(1);
        }
    }
}

void closeBookArchive() {
    fclose(fp);
}