#include <stdio.h>
#include "utility.h"
#include "menu.h"


void DeveloperInfo(){
     system("@cls||clear");
    printf("*******************************************************************************************\n");
    printf("* Name is Ahmed Said Khalid \t Student ID : 201500008 \t Major: Electrical \t  *\n");
    printf("* Welcome to my project. This Program is a Game. it has QA style and Guessing -- Enjoy it *\n");
    printf("*******************************************************************************************\n");
    GoToMenu();
};

void GoToMenu(){
    printf("\nPress any key to continue\n");
    _getch();
    system("@cls||clear");
    Start();
}

void ProgramInfo(){
    system("@cls||clear");
    printf("*********************************PROGRAM INFO******************************************************\n");
    printf("This program is a game that has two options. Guessing Game, and Ask/Answer \n");
    printf("In the guessing game, the program will select randomly a number or two,\n and then you should guess what the program selected \n");
    printf("If your guess are correct then you win otherwise the program wins.\n");
    printf("In the ask and answer, the program will show multi-option questions.\n For each of the questions, you meed to answer by typing your choice \n");
    printf("The program will score the correct answers, Finally, it will show you scores\n");

    GoToMenu();
};

