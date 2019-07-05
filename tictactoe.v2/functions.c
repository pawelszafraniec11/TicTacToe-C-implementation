#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "boards.h"
#include "functions.h"

#define MAX_LENGTH 100

extern int errno;//global variable to return error values

char tab[10]={'0','1','2','3','4','5','6','7','8','9'};
char temp[10]={'0','1','2','3','4','5','6','7','8','9'};


void add_results(struct results **head, char *data)
{
     struct results *new_node=(struct results*)malloc(sizeof(struct results));//allocating memory for new variable of a list
     new_node->xxx=data;//assigning value to the new element of the list
     new_node->next=(*head);//assigning pointer of new element to previous head as pointer to next element
     (*head)=new_node;// new node is set as a head of the list
}

void print_results (struct results *p)
{
   FILE *fp=fopen("results.txt","a");
   if (fp==NULL)//condition if file opening fails
       fprintf(stderr,"Error opening a txt file. Error code:%d\n",errno);//print message into standard error stream
    while(p)
   {
       fprintf(fp,"%s \n",p->xxx);
       p=p->next;
   }
   fclose(fp);
}


/*
 Function check_if_win checks result of the game.
 When there are 3 the same characters in line or in diagonal, it returns 1.
 When the game is in progress it returns -1.
 Game draw is when this function returns 0.
 */
int check_if_win()//function checks the result of the game
{
    if(tab[1] == tab[2] && tab[2] == tab[3])//if characters in row are the same
        return 1;//win

    else if (tab[4] == tab[5] && tab[5] == tab[6])//same as in if condition
        return 1;//win

    else if (tab[7] == tab[8] && tab[8] == tab[9])//same as in if condition
        return 1;//win

    else if (tab[1] == tab[4] && tab[4] == tab[7])//if characters in column are the same
        return 1;//win

    else if (tab[2] == tab[5] && tab[5] == tab[8])//if characters in column are the same
        return 1;//win

    else if (tab[3] == tab[6] && tab[6] == tab[9])//if characters in column are the same
        return 1;//win

    else if (tab[1] == tab[5] && tab[5] == tab[9])//if characters in diagonal are the same
        return 1;//win

    else if (tab[3] == tab[5] && tab[5] == tab[7])//if characters in diagonal are the same
        return 1;//win

    else if (tab[1] != '1' && tab[2] != '2' && tab[3] != '3' &&
        tab[4] != '4' && tab[5] != '5' && tab[6] != '6' && tab[7]
        != '7' && tab[8] != '8' && tab[9] != '9')
        return 0;

    else
        return  - 1;//game in progress

}
void game()//play function
{
    struct results *ccc=NULL;

    int move;//move of the player
    int i;//variable used in scores option in menu
    int player=1;
    char xo;
    char cz[100];

        do
        {

        board_game();//showing board to play

        player=(player%2)?1:2;//Players must put characters alternately
        printf("\tPlayer %d move. Enter number to place sign: ",player);

        //input validation
        fflush(stdin);//cleaning stdin buffer
        gets(cz);//players enters choice
        move=atoi(cz);//ASCII->int
        if(move>0&&move<10)//available moves are from 1 to 9
            {

        xo=(player==1)?'X':'O';//characters are being put alternately

        if(move==1&&tab[1]=='1')//if player's choice matches to the place in board
            tab[1] = xo;//put X or O depending on who's turn it is
        //same procedure as above for all else if conditions
        else if (move == 2 && tab[2] == '2')
            tab[2] = xo;
        else if (move == 3 && tab[3] == '3')
            tab[3] = xo;
        else if (move == 4 && tab[4] == '4')
            tab[4] = xo;
        else if (move == 5 && tab[5] == '5')
            tab[5] = xo;
        else if (move == 6 && tab[6] == '6')
            tab[6] = xo;
        else if (move == 7 && tab[7] == '7')
            tab[7] = xo;
        else if (move == 8 && tab[8] == '8')
            tab[8] = xo;
        else if (move == 9 && tab[9] == '9')
            tab[9] = xo;
        else//invalid move- invalid data, on given place there is already other symbol
            {
            printf("Invalid move!\n");
            player--;
            getch();

            }

        i=check_if_win();//after every turn checks the result
        player++;//switch players

            }

        }while(i==-1);//i==-1 -> game is in progress

        board_game();//rebuilding the board due to players moves

        if(i==1)//Someone won
        {
        printf("\tPlayer %d won!\n",--player);//Player who put the last element is a winner
        if(player==1)
        add_results(&ccc,"Player 1 won!");
        else
        add_results(&ccc,"Player 2 won!");

        printf("\tPress any button to continue!\n");
            for(int i=0;i<10;i++)
            tab[i]=temp[i];//reset board
        }
        else
        {
        printf("\tGame draw!\n");//Game draw
        add_results(&ccc,"Game draw!");
        printf("\tPress any button to continue!\n");
            for(int i=0;i<10;i++)
            tab[i]=temp[i];//reset board
        }

        print_results(ccc);
        getch();//prompts for pressing button

}
void read_score()//option 4 in menu
{
   char read[MAX_LENGTH];//tab for reading from the file
   int i=1;//variable used for graphic enrichment
   FILE *fp1=fopen("Results.txt","r");//opening file with result
   if(fp1==NULL)//condition if file opening fails
        fprintf(stderr,"Error opening a txt file. Error code:%d\n",errno);//print message into standard error stream
   while(fgets(read,MAX_LENGTH,fp1)!=NULL)//moving through file line by line
   {
                printf("\t[%d] %s",i,read);//print results
                i++;
   }
   fclose(fp1);//closing file


}

void menu()
{
    int choice;//choice of player in menu
    char ch[100];

    game_menu_display();//print menu

    while(choice)
    {
    printf("   Select option: ");
    //input validation
    fflush(stdin);
    gets(ch);
    choice=atoi(ch);//ANSCII->int
    if(choice==0)//invalid data
        choice=choice+10;

    printf("\n");
    switch(choice)//menu options depending on what user wants to do
    {
        case 1://game option
            game();//users play
            system("cls");
            game_menu_display();
        break;
        case 2://rules of the game
            printf("-> The object of Tic Tac Toe is to get three in a row.\n");
            printf("-> You play on a three by three game board.\n");
            printf("-> The first player is known as 'X' and the second is 'O'.\n");
            printf("-> Players alternate placing Xs and Os on the game board until either opponent has three in row or in diagonal.\n");
            printf("-> If none of the player complete the path, it is a draw.\n");
            board_display();
        break;
        case 3://author
            printf("-> Pawel Szafraniec, Informatics, 2nd semster, project for Computer Programming\n\n");
        break;
        case 4://scores table
            read_score();
            printf("\n");
            printf("\tREMARK: The latest game score is on the last place of the list of scores!\n");
            printf("\n");
        break;
        case 5://quitting option
            exit(0);
        break;
        default:
            printf("-> No such option. Try any from 1 to 4.\n\n");
            }
        }
}







