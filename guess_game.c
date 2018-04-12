#include <stdio.h>
#include <stdlib.h>
#include "guess_game.h"

char *_id;
int _secret1, _secret2, _round, _point;

void initGuessGame(char *ID){
    _id = ID;
    _secret1 = generateSecret();
    _point = 0;

    playGuessGame2(1);
};

void initGuessGame2(char *ID){
    initGuessGame(ID);
    _secret2 = generateSecret();
};

int generateSecret(){
   int i = rand() % 10 + 1;
   return i;
};

void playGuessGame(int round){
    _round = round;

    printf("User ID : %s\n", _id);
    printf("||============= Guessing Game Level 1 =========\n");
    printf("|| Guesting game Round number [%d]\n", _round);
    printf("|| I selected a random number in this range [0 - 10]\n");
    printf("|| Can you guess what is it ? Enter your first guest:");

    int _answer1;
    int _numberTry = 2;

    scanf("%d", &_answer1);
    if(_answer1 != _secret1){
        do{
            printf("|| Wrong guess, try again [%d]:", _numberTry);
            scanf("%d", &_answer1);
            _numberTry++;

        }while((_answer1 != _secret1) && (_numberTry <= 5));
    }

    if(_answer1 == _secret1){
        printf("|| Great guess you guessed the right number");
        _point = _point + 20;
    }else{
        printf("|| Missed out all of your chance");
    }


    if(_round < 5){
        printf("Press any key to start next round");

        getchar();
        system("@cls||clear");

        _secret1 = generateSecret();
        playGuessGame(_round + 1);
    }else{
        saveResult();
    }
};

void playGuessGame2(int round){
    _round = round;
    int _answer1, _answer2;
    int _numberTry = 2;


    printf("User ID : %s\n", _id);
    printf("||============= Guessing Game Level 2 =========\n");
    printf("|| Guesting game Round number [%d]\n", _round);
    printf("|| I selected two random number in this range [0 - 10]\n");

    printf("|| Can you guess what is it ? Enter your first number guess:");
    scanf("%d", &_answer1);

    printf("|| Enter your second number guess:");
    scanf("%d", &_answer2);


    if((_answer1 != _secret1)&&(_answer2 != _secret2)){
        do{
            printf("|| Wrong guess, try again [%d] first number:", _numberTry);
            scanf("%d", &_answer1);

            printf("|| second number:", _numberTry);
            scanf("%d", &_answer2);

            _numberTry++;

        }while(((_answer1 != _secret1)&&(_answer2 != _secret2)) && (_numberTry <= 5));
    }

    if((_answer1 == _secret1)&&(_answer2 == _secret2)){
        printf("|| Great guess you guessed two right number");
        _point = _point + 20;
    }
    else if((_answer1 == _secret1)||(_answer2 == _secret2)){
        printf("|| Great guess you guessed two right number");
        _point = _point + 10;
    }else{
        printf("|| Missed out all of your chance");
    }


    if(_round < 5){
        printf("Press any key to start next round");

        getchar();
        system("@cls||clear");

        _secret1 = generateSecret();
        _secret2 = generateSecret();

        playGuessGame2(_round + 1);
    }else{
        saveResult();
    }
};

void saveResult(){
    printf("UserID %s got %d", _id, _point);
};
