#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "gametype.h"
#include "guess_game.h"
#include "qa_game.h"

void GuessGame()
{
    initGuessGame();
}

void ViesGuessGameScore(){
    readResult();
    viewQAresult();
    Start();
}

void QAGame()
{
    startGame();
    _getch();
}
