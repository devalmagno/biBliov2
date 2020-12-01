#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "book.h"

#define CLEAR_SCREEN system("cls");

FILE *fpBook;

// Book B[100];

char bookName[100][41];
char authorName[100][41];
char bookGenre[100][41];
double bookPrice[100];
int ID[100];
int exibir[100];
int buyNumber[100];

int registerPackages = 0;

void registerBook()
{
    int registerLoop, loop, i, j, f;

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

    fpBook = fopen("data.txt", "wb+");

    loop = registerLoop + registerPackages;

    for (i = registerPackages; i < loop; i++)
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
        scanf(" %[^\n]*%c\n ", &bookName[i]);
        gotoxy(20, 8);
        scanf(" %[^\n]*%c\n ", &authorName[i]);
        gotoxy(20, 9);
        scanf(" %[^\n]*%c\n ", &bookGenre[i]);
        gotoxy(20, 10);
        scanf("%lf", &bookPrice[i]);

        ID[i] = i;
        exibir[i] = 1;
        buyNumber[i] = 0;
        registerPackages++;

        gotoxy(20, 7);
        printf("                    ");
        gotoxy(20, 8);
        printf("                    ");
        gotoxy(20, 9);
        printf("                    ");
        gotoxy(20, 10);
        printf("                    ");

        f = 0;
        gotoxy(66, 7 + f);
        printf("%s", bookName[i]);
        gotoxy(86, 7 + f);
        printf("%.2lf", bookPrice[i]);
        f++;
        // fwrite(&B[i].bookName, sizeof(Book), strlen(B[i].bookName) - 1, fpBook);
        // fwrite(Book[i].authorName, 41, sizeof(Book[i].authorName), fpBook);
        // fwrite(Book[i].bookGenre, 41, sizeof(Book[i].bookGenre), fpBook);
        // fputs(&B[i].bookName, fpBook);
        // // fputs(Book[i].authorName, fpBook);
        // // fputs(Book[i].bookGenre, fpBook);
        // // fputc(Book[i].bookPrice, fpBook);
        // // fputc(Book[i].ID, fpBook);
        // // fputc(Book[i].exibir, fpBook);
        // // fputc(Book[i].buyNumber, fpBook);

        // fputc(registerPackages, fpBook);

        gotoxy(20, 7);
    }

    fwrite(&registerPackages, sizeof(registerPackages), 1, fpBook);

    fwrite(&bookName, sizeof(char), 100, fpBook);
    fwrite(&authorName, sizeof(char), 100, fpBook);
    fwrite(&bookGenre, sizeof(char), 100, fpBook);
    fwrite(&bookPrice, sizeof(double), 1, fpBook);
    fwrite(&ID, sizeof(int), 1, fpBook);
    fwrite(&exibir, sizeof(int), 1, fpBook);
    fwrite(&buyNumber, sizeof(int), 1, fpBook);

    // fseek(fpBook, 0, SEEK_END);
    // fwrite(&bookName, sizeof(char), 100, fpBook);
    // fwrite(B[0].bookName, sizeof(Book), strlen(B[0].bookName) - 1, fpBook);
    // fwrite(B[0].bookName, sizeof(Book), 1, fpBook);

    // fwrite(&B, sizeof(Book), 100, fpBook);

    fclose(fpBook);

    gotoxy(30, 26);
    system("pause");
    CLEAR_SCREEN;
}

void readValues()
{
    int i;

    openBookArchive();

    if (fpBook != NULL)
    {
        fseek(fpBook, 0, SEEK_SET);
        fread(&registerPackages, sizeof(int), 1, fpBook);
        fread(&bookName, sizeof(char), 100, fpBook);
        fread(&authorName, sizeof(char), 100, fpBook);
        fread(&bookGenre, sizeof(char), 100, fpBook);
        fread(&bookPrice, sizeof(double), 1, fpBook);
        fread(&ID, sizeof(int), 1, fpBook);
        fread(&exibir, sizeof(int), 1, fpBook);
        fread(&buyNumber, sizeof(int), 1, fpBook);

        // fread(&B, sizeof(Book), 100, fpBook);
        // registerPackages = fgetc(fpBook);
        // fread(B[0].bookName, sizeof(Book), strlen(B[0].bookName) - 1, fpBook);
        // fread(B[0].bookName, sizeof(Book), 1, fpBook);

        for (i = 0; i < registerPackages; i++)
        {
            // fread(&B[i].bookName, sizeof(Book), strlen(B[i].bookName) - 1, fpBook);
            // fread(&Book[i].authorName, sizeof(char), 41, fpBook);
            // fread(&Book[i].bookGenre, sizeof(char), 41, fpBook);
            // fread(&Book[i].bookPrice, sizeof(double), 1, fpBook);
            // fread(&Book[i].ID, sizeof(int), 1, fpBook);
            // fread(&Book[i].exibir, sizeof(int), 1, fpBook);
            // fread(&Book[i].buyNumber, sizeof(int), 1, fpBook);

            // fgets(&B[i].bookName, sizeof(Book), fpBook);
        }
    }

    closeBookArchive();
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
    int i = 0;

    CLEAR_SCREEN;
    gotoxy(1, 1);

    if (registerPackages == 0)
    {
        printf("Ainda nao ha livros para mostrar!");
        return;
    }
    else
    {
        // printf("%d\n", registerPackages);
        // printf("%d\n", Book[0].ID);

        // printf("%s\n", bookName[0]);
        // printf("%s\n", bookName[1]);

        CLEAR_SCREEN;

        addPageComponent();

        for (i = 0; i < registerPackages + 1; i++)
        {
            gotoxy(30, 5 + i);
            printf("|");
            gotoxy(55, 5 + i);
            printf("|");
            gotoxy(85, 5 + i);
            printf("|");
        }

        gotoxy(5, 6);
        printf("_________________________");
        gotoxy(31, 6);
        printf("________________________");
        gotoxy(56, 6);
        printf("______________________");
        gotoxy(86, 6);
        printf("___________");

        gotoxy(10, 5);
        textColor(13);
        printf("TITULO");
        gotoxy(35, 5);
        printf("AUTOR");
        gotoxy(60, 5);
        printf("GENERO");
        gotoxy(87, 5);
        printf("PRECO");

        i = 0;

        while (registerPackages > i)
        {
            textColor(8);
            gotoxy(11, 7 + i);
            printf("%s\n", bookName[i]);
            gotoxy(36, 7 + i);
            printf("%s\n", authorName[i]);
            gotoxy(61, 7 + i);
            printf("%s\n", bookGenre[i]);
            gotoxy(88, 7 + i);
            printf("%.2lf\n", bookPrice[i]);
            i++;
        }

        gotoxy(10, 15);
        system("pause");
        // for (i = 0; i <= registerPackages; i++)
        // {
        //     gotoxy(1, 2 + i);
        //     printf("%s\n", bookName[i]);
        //     system("pause");
        //     return;
        // }
    }
}