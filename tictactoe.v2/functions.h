#ifndef functions_H_INCLUDED
#define functions_H_INCLUDED

struct results//initialization of the list which stores results of the game
{
    char *xxx;//data to be stored
    struct results *next;//pointer to the next element
};

void add_results(struct results **head, char *data);//add a result to the list of results

void print_results(struct results *p);//function to put list elements in file

//global tab necessary in my program, used in more than one file
extern char tab[];

//function checks the result of the game
int check_if_win ();

//showing on the screen menu of the game,which contains options in game
void menu();

//function enriches menu showing results of the game due to agenda
void read_score();

//match function- first option in menu
void game();

#endif // functions_H_INCLUDED


