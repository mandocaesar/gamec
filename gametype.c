#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "gametype.h"
#include "guess_game.h"

void GuessGame()
{
    initGuessGame();
}

void ViesGuessGameScore(){
    readResult();
    _getch();
}

void QAGame()
{
    printf("QA game");
}
