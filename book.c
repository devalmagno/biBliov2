#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "book.h"

#define CLEAR_SCREEN system("cls");

FILE *fpBook;

int registerPackages = 0;

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
        printf("%d %d", i, registerPackages + registerLoop);
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
        Book[i].buyNumber = 0;
        registerPackages++;

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

        // fwrite(Book[i].authorName, 41, sizeof(Book[i].authorName), fpBook);
        // fwrite(Book[i].bookGenre, 41, sizeof(Book[i].bookGenre), fpBook);
        // // fputs(Book[i].bookName, fpBook);
        // // fputs(Book[i].authorName, fpBook);
        // // fputs(Book[i].bookGenre, fpBook);
        // // fputc(Book[i].bookPrice, fpBook);
        // // fputc(Book[i].ID, fpBook);
        // // fputc(Book[i].exibir, fpBook);
        // // fputc(Book[i].buyNumber, fpBook);

        // fputc(registerPackages, fpBook);

        gotoxy(20, 7);
    }

    fpBook = fopen("data.txt", "wb+");
    fwrite(&Book, sizeof(Book), 100, fpBook);
    fwrite(&registerPackages,sizeof(registerPackages), 1, fpBook);

    fclose(fpBook);

    gotoxy(30, 26);
    system("pause");
    CLEAR_SCREEN;
}

void readValues()
{
    int i;

    // openBookArchive();

    if (fpBook != NULL)
    {
        fread(&registerPackages, sizeof(int), 1, fpBook);
        // registerPackages = fgetc(fpBook);
        fread(&Book, sizeof(Book), 100, fpBook);

        // for (i = 0; i < registerPackages; i++)
        // {
        //     // fread(&Book[i].authorName, sizeof(char), 41, fpBook);
        //     // fread(&Book[i].bookGenre, sizeof(char), 41, fpBook);
        //     // fread(&Book[i].bookPrice, sizeof(double), 1, fpBook);
        //     // fread(&Book[i].ID, sizeof(int), 1, fpBook);
        //     // fread(&Book[i].exibir, sizeof(int), 1, fpBook);
        //     // fread(&Book[i].buyNumber, sizeof(int), 1, fpBook);

        //     // fgets(Book[i].bookName, sizeof(Book[i].bookName), fpBook);
        // }
    }

    // closeBookArchive();
}

void openBookArchive()
{
    fpBook = fopen("data.txt", "rb+");
    if (fpBook == NULL)
    {
        fpBook = fopen("data.txt", "wb+");
        if (fpBook == NULL)
        {
            printf("Não foi possivel criar o arquivo de dados.\n");
            exit(1);
        }
    }
}

void closeBookArchive()
{
    fclose(fpBook);
}

void showBooks()
{
    int i;

    CLEAR_SCREEN;
    gotoxy(1, 1);

    if (registerPackages == 0)
    {
        printf("Ainda nao ha livros para mostrar!");
        return;
    }
    else
    {
        printf("%d\n", registerPackages);
        printf("%d\n", Book[0].ID);

        for (i = 0; i < registerPackages; i++)
        {
            printf("%s\n", Book[i].bookName);
        }
    }

    system("pause");
}