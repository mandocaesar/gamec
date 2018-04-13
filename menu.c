#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "menu.h"
#include "gametype.h"

void Start()
{
    int _answer;
    char* _menu[8] = {
        "============= Main Screen Menu =========",
        " 1- Play a new game",
        " 2- View previous score",
        " 3- Who is the highest scored player ?",
        " 4- Programmer Information",
        " 5- Program Information",
        " 6- Exit Program",
        "========================================"
    };

    for(int i = 0 ; i < 8; i++)
    {
        printf("%s%s\n","||",_menu[i]);
    };

    printf("Please enter your choice:");
    scanf("%d", &_answer);
    switch(_answer){
        case 1 :

            GameMenu();
            break;
        case 6 :
            system("@cls||clear");
            printf("Thank you for using ICS103 Game Program, Good luck");
            break;
        default:
            printf("Invalid Menu");
            Start();
    }
}

void GameMenu()
{
    system("@cls||clear");
    char* _menu[5] = {
        "============= Main Screen Menu =========",
        " 1- Guessing Game",
        " 2- Ask & Answer Game",
        " - \'ESC\' button to return back",
        "========================================"
    };

    for(int i = 0 ; i < 5; i++)
    {
        printf("%s%s\n","||",_menu[i]);
    };

    int _answer;
    printf("Your choice:");
    _answer = _getch();
    switch(_answer)
    {
        case 49:
            system("@cls||clear");
            GuessGame();
            break;
        case 50:
            system("@cls||clear");
            QAGame();
            break;
        case 27:
            system("@cls||clear");
            Start();
            break;
         default:
            system("@cls||clear");
            printf("Invalid Menu");
            GameMenu();
    }

}

