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
int myCart[100];
int buyNumber[100];

int registerPackages = 0;

void registerBook()
{
    int registerLoop, loop, i, j, f;

    f = 0;

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
        myCart[i] = 0;
        registerPackages++;

        gotoxy(20, 7);
        printf("                    ");
        gotoxy(20, 8);
        printf("                    ");
        gotoxy(20, 9);
        printf("                    ");
        gotoxy(20, 10);
        printf("                    ");

        gotoxy(66, 7 + f);
        printf("%s", bookName[i]);
        gotoxy(86, 7 + f);
        printf("%.2lf", bookPrice[i]);
        f++;

        gotoxy(20, 7);
    }

    fwrite(&registerPackages, sizeof(registerPackages), 1, fpBook);

    fwrite(&bookName, sizeof(char), 100, fpBook);
    fwrite(&authorName, sizeof(char), 100, fpBook);
    fwrite(&bookGenre, sizeof(char), 100, fpBook);
    fwrite(&bookPrice, sizeof(double), 100, fpBook);
    fwrite(&ID, sizeof(int), 100, fpBook);
    fwrite(&exibir, sizeof(int), 100, fpBook);
    fwrite(&buyNumber, sizeof(int), 100, fpBook);
    fwrite(&myCart, sizeof(int), 100, fpBook);

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
        fread(&bookPrice, sizeof(double), 100, fpBook);
        fread(&ID, sizeof(int), 100, fpBook);
        fread(&exibir, sizeof(int), 100, fpBook);
        fread(&buyNumber, sizeof(int), 100, fpBook);
        fread(&myCart, sizeof(int), 100, fpBook);

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
    int i = 0, printBookPosition = 0;
    // printf("%d\n", registerPackages);
    // printf("%d\n", Book[0].ID);

    // printf("%s\n", bookName[0]);
    // printf("%s\n", bookName[1]);

    textBackground(0);
    textColor(6);

    for (i = 0; i < registerPackages + 2; i++)
    {
        gotoxy(5, 5 + i);
        printf("|");
        gotoxy(30, 5 + i);
        printf("|");
        gotoxy(55, 5 + i);
        printf("|");
        gotoxy(75, 5 + i);
        printf("|");
        gotoxy(85, 5 + i);
        printf("|");
        gotoxy(95, 5 + i);
        printf("|");
    }

    gotoxy(5, 4);
    printf("___________________________________________________________________________________________");
    gotoxy(6, 6);
    printf("________________________");
    gotoxy(31, 6);
    printf("________________________");
    gotoxy(56, 6);
    printf("___________________");
    gotoxy(76, 6);
    printf("_________");
    gotoxy(86, 6);
    printf("_________");

    gotoxy(6, 5);
    textColor(15);
    printf("TITULO");
    gotoxy(32, 5);
    printf("AUTOR");
    gotoxy(56, 5);
    printf("GENERO");
    gotoxy(76, 5);
    printf("PRECO R$");
    gotoxy(86, 5);
    printf("ID");

    i = 0;

    while (registerPackages > i)
    {
        if (exibir[i] != 0)
        {
            textColor(8);
            gotoxy(7, 7 + printBookPosition);
            printf("%s\n", bookName[i]);
            gotoxy(33, 7 + printBookPosition);
            printf("%s\n", authorName[i]);
            gotoxy(57, 7 + printBookPosition);
            printf("%s\n", bookGenre[i]);
            gotoxy(77, 7 + printBookPosition);
            printf("R$ %.2lf\n", bookPrice[i]);
            gotoxy(87, 7 + printBookPosition);
            printf("%d\n", ID[i]);

            printBookPosition++;
        }
        i++;
    }
    // for (i = 0; i <= registerPackages; i++)
    // {
    //     gotoxy(1, 2 + i);
    //     printf("%s\n", bookName[i]);
    //     system("pause");
    //     return;
    // }
}

void searchBook()
{
    int i, j, foundBook = 0, otherBooks = 0;
    char pesquisa[41];

    addPageComponent();
    gotoxy(40, 1);
    textColor(0);
    textBackground(4);
    printf("[PESQUISAR LIVRO]");

    textBackground(0);
    textColor(7);

    if (registerPackages == 0)
    {
        printf("Sem livros no catalogo.");
    }
    else
    {
        gotoxy(30, 4);
        printf("Digite um nome para pesquisar:");
        gotoxy(65, 4);
        scanf(" %[^\n]*%c\n ", &pesquisa);

        gotoxy(29, 4);
        printf("                                                    ");
        for (i = 0; i < registerPackages; i++)
        {
            if (strcmp(bookName[i], pesquisa) == 0)
            {
                gotoxy(35, 4);
                printf("Livro encontrado com sucesso!\n\n");

                gotoxy(10, 6);
                printf("Nome do livro: %s", bookName[i]);
                gotoxy(10, 7);
                printf("Autor: %s", authorName[i]);
                gotoxy(10, 8);
                printf("Genero: %s", bookGenre[i]);
                gotoxy(10, 9);
                printf("Preco: R$ %.2lf", bookPrice[i]);
                gotoxy(10, 10);
                printf("ID: %d", ID[i]);

                // for (j = 0; j < registerPackages; j++)
                // {
                //     if (strcmp(authorName[i], authorName[j]))
                //     {
                //         gotoxy(75, 8 + otherBooks);
                //         printf("%s", bookName[j]);
                //         otherBooks++;
                //     }
                // }

                // if (otherBooks > 0)
                // {
                //     gotoxy(70, 6);
                //     printf("Outros livros de %s: ", authorName[i]);
                // } else {
                //     gotoxy(70, 6);
                //     printf("O autor só possui essa obra no sistema.");
                // }

                foundBook = 1;
            }
        }

        if (!foundBook)
        {
            gotoxy(41, 4);
            printf("Nao encontrei %s.\n\n", pesquisa);
            gotoxy(25, 6);
            system("pause");
            return;
        }

        optionsMenu();
    }
}

void optionsMenu()
{
    int option;

    gotoxy(35, 22);
    printf("[ ] - COMPRAR");
    gotoxy(55, 22);
    printf("[ ] - VOLTAR");
    gotoxy(36, 22);
    textColor(4);
    printf("=");
    option = selectRoute(36, 56, 22);

    if (option == 2)
        return;

    CLEAR_SCREEN;
    buyBook();
}

void buyBook()
{
    int bookID, option;
    addPageComponent();
    gotoxy(45, 1);
    textColor(0);
    textBackground(4);
    printf("[COMPRAR]");

    showBooks();
    gotoxy(38, 15);
    textBackground(0);
    textColor(7);
    printf("Digite o ID do livro: ");
    gotoxy(62, 15);
    scanf("%d", &bookID);

    gotoxy(35, 17);
    printf("%s", bookName[bookID]);
    gotoxy(60, 17);
    printf("R$ %2.lf", bookPrice[bookID]);

    gotoxy(35, 22);
    printf("[ ] - COMPRAR");
    gotoxy(55, 22);
    printf("[ ] - VOLTAR");
    gotoxy(36, 22);
    textColor(4);
    printf("=");
    option = selectRoute(36, 56, 22);

    if (option == 2)
        return;

    myCart[bookID] = 1;
    buyNumber[bookID] += 1;

    gotoxy(35, 18);
    printf("Compra realizada com sucesso.");
    gotoxy(30, 19);
    system("pause");
    return;
}

void buyList()
{
    int i, inMyCart = 0;

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

    for (i = 0; i < registerPackages; i++)
    {
        if (myCart[i] == 1)
        {
            gotoxy(10, 14 + inMyCart);
            printf("%s", bookName[i]);
            gotoxy(35, 14 + inMyCart);
            printf("%s", authorName[i]);
            gotoxy(60, 14 + inMyCart);
            printf("%s", bookGenre[i]);
            gotoxy(87, 14 + inMyCart);
            printf("R$ %.2lf", bookPrice[i]);
            inMyCart++;
        }
    }
}

void removeBook()
{
    int bookID, option;

    CLEAR_SCREEN;

    addPageComponent();
    gotoxy(45, 1);
    textColor(0);
    textBackground(4);
    printf("[REMOVER]");

    showBooks();
    gotoxy(38, 15);
    textBackground(0);
    textColor(7);
    printf("Digite o ID do livro: ");
    gotoxy(62, 15);
    scanf("%d", &bookID);

    gotoxy(35, 17);
    printf("%s", bookName[bookID]);
    gotoxy(60, 17);
    printf("R$ %2.lf", bookPrice[bookID]);

    gotoxy(35, 22);
    printf("[ ] - REMOVER");
    gotoxy(55, 22);
    printf("[ ] - VOLTAR");
    gotoxy(36, 22);
    textColor(4);
    printf("=");
    option = selectRoute(36, 56, 22);

    if (option == 2)
        return;

    exibir[bookID] = 0;

    fpBook = fopen("data.txt", "wb+");

    fwrite(&exibir, sizeof(int), 100, fpBook);

    fclose(fpBook);

    gotoxy(35, 18);
    printf("Livro removido com sucesso.");
    gotoxy(30, 19);
    system("pause");
    return;
}

void changeBook()
{
    int bookID, option;

    CLEAR_SCREEN;

    addPageComponent();
    gotoxy(45, 1);
    textColor(0);
    textBackground(4);
    printf("[ALTERAR]");

    showBooks();
    gotoxy(38, 15);
    textBackground(0);
    textColor(7);
    printf("Digite o ID do livro: ");
    gotoxy(62, 15);
    scanf("%d", &bookID);

    gotoxy(25, 17);
    printf("%s", bookName[bookID]);
    gotoxy(45, 17);
    printf("Preco antigo: R$ %2.lf", bookPrice[bookID]);
    gotoxy(65, 17);
    printf("Preco novo: R$");

    gotoxy(35, 22);
    printf("[ ] - ALTERAR");
    gotoxy(55, 22);
    printf("[ ] - VOLTAR");
    gotoxy(36, 22);
    textColor(4);
    printf("=");
    option = selectRoute(36, 56, 22);

    if (option == 2)
        return;

    gotoxy(80, 17);
    scanf("%lf", &bookPrice[bookID]);

    // fpBook = fopen("data.txt", "wb+");

    fwrite(&bookPrice, sizeof(double), 100, fpBook);

    // fclose(fpBook);

    gotoxy(35, 18);
    printf("Livro alterado com sucesso.");
    gotoxy(30, 19);
    system("pause");
    return;
}

void saveBook()
{
    fpBook = fopen("data.txt", "wb+");

    fwrite(&registerPackages, sizeof(registerPackages), 1, fpBook);

    fwrite(&bookName, sizeof(char), 100, fpBook);
    fwrite(&authorName, sizeof(char), 100, fpBook);
    fwrite(&bookGenre, sizeof(char), 100, fpBook);
    fwrite(&bookPrice, sizeof(double), 100, fpBook);
    fwrite(&ID, sizeof(int), 100, fpBook);
    fwrite(&exibir, sizeof(int), 100, fpBook);
    fwrite(&buyNumber, sizeof(int), 100, fpBook);
    fwrite(&myCart, sizeof(int), 100, fpBook);

    fclose(fpBook);
}

// void hotBooks()
// {
//     int i, j, recordSales, secondInSales, thirdInSales;

//     gotoxy(34, 15);
//     printf("Nossos livros mais vendidos:");

//     for (i = 0; i < registerPackages; i++)
//     {
//         for (j = 1; j < registerPackages; j++)
//         {
//             if (buyNumber[i] > buyNumber[j])
//             {
//                 recordSales = i;
//                 secondInSales = j;
//             }
//             else
//             {
//                 recordSales = j;
//                 secondInSales = i;
//             }

//             if (secondInSales > buyNumber[i])
//             {
//                 thirdInSales = i;
//             }
//         }
//     }

//     if (buyNumber[recordSales] != 0)
//     {
//         gotoxy(30, 16);
//         printf("%s RECORDE DE VENDAS com %d unidades vendidas.", bookName[recordSales], buyNumber[recordSales]);
//     }

//     if (buyNumber[secondInSales] != 0)
//     {
//         gotoxy(30, 17);
//         printf("%s SEGUNDO LUGAR com %d unidades vendidas.", bookName[secondInSales], buyNumber[secondInSales]);
//     }

//     if (buyNumber[thirdInSales] != 0)
//     {
//         gotoxy(30, 18);
//         printf("%s TERCEIRO LUGAR com %d unidades vendidas.", bookName[thirdInSales], buyNumber[thirdInSales]);
//     }
// }