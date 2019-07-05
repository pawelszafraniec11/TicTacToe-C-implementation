#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "boards.h"
#include "functions.h"


void board_game()//board used in game
{

       system("cls");
        printf("\n");
        printf("\tPlayer 1 symbol- X\n");
        printf("\tPlayer 2 symbol- O\n");

        printf("\n\t\t       |       |       ");
        printf("\n\t\t   %c   |   %c   |   %c    ",tab[1],tab[2],tab[3]);
        printf("\n\t\t       |       |       ");
        printf("\n\t\t=======|=======|=======");
        printf("\n\t\t       |       |       ");
        printf("\n\t\t   %c   |   %c   |   %c    ",tab[4],tab[5],tab[6]);
        printf("\n\t\t       |       |       ");
        printf("\n\t\t=======|=======|=======");
        printf("\n\t\t       |       |       ");
        printf("\n\t\t   %c   |   %c   |   %c    ",tab[7],tab[8],tab[9]);
        printf("\n\t\t       |       |       ");
        printf("\n\n");

}


void game_menu_display()//game menu
{
        printf("********| Tic Tac Toe |********\n");
        printf("    Game menu\n");
        printf("   [1].Start game             \n");
        printf("   [2].Rules of competition   \n");
        printf("   [3].Author                 \n");
        printf("   [4].Scores                 \n");
        printf("   [5].Quit                   \n");

}

void board_display()//board used in explaining rules of the game
{
        printf("\n");
        printf("\tPlayer 1 symbol- X\n");
        printf("\tPlayer 2 symbol- O\n");
        char matrix2[9];
        for(int i=0;i<9;i++)
            matrix2[i]='?';
        printf("\n\t\t\t       |       |       ");
        printf("\n\t\t\t   %c   |   %c   |   %c    ",matrix2[0],matrix2[1],matrix2[2]);
        printf("\n\t\t\t      1|      2|      3");
        printf("\n\t\t\t=======|=======|=======");
        printf("\n\t\t\t       |       |       ");
        printf("\n\t\t\t   %c   |   %c   |   %c    ",matrix2[3],matrix2[4],matrix2[5]);
        printf("\n\t\t\t      4|      5|      6");
        printf("\n\t\t\t=======|=======|=======");
        printf("\n\t\t\t       |       |       ");
        printf("\n\t\t\t   %c   |   %c   |   %c    ",matrix2[6],matrix2[7],matrix2[8]);
        printf("\n\t\t\t      7|      8|      9");
        printf("\n\n");

}








