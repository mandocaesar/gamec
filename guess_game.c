#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "guess_game.h"
#include "utility.h"
#include "menu.h"


struct GuessModel{
    char player[50];
    int lvl, point;
};

char _id[50];
int _secret1, _secret2, _round, _point, _lvl;
struct GuessModel _models[10];
struct GuessModel _model;

void initGuessGame(){
    //readResult();
    //char _username[50];
    printf("Enter your username:");
    scanf("%s", _model.player);

    printf("Lest platy %s \n", _model.player);

   // _id = _username;
    _secret1 = generateSecret();
    _model.point = 0;
    _model.lvl = 1;

    playGuessGame(1);
};

void initGuessGame2(){
    _secret1 = generateSecret();
    _secret2 = generateSecret();
    _model.lvl = 2;

    playGuessGame2(1);
};

int generateSecret(){
   int i = rand() % 10 + 1;
   return i;
};

void playGuessGame(int round){
    _round = round;

    printf("User ID : %s\n", _model.player);
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
        _model.point = _model.point + 20;
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
        if(_model.point > 50){
            printf("Press any key to start next Level");
            getchar();
            initGuessGame2(1);
        }else{
            printf("\nCongratulations your final point is %d \n", _model.point);
            printf("\nSorry you don't have enough point to proceed to next level, thanks for playing!\n");
            getchar();
            Start();
        }
    }
};

void playGuessGame2(int round){
    _round = round;
    int _answer1, _answer2;
    int _numberTry = 2;


    printf("User ID : %s\n", _model.player);
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

            printf("|| second number:");
            scanf("%d", &_answer2);

            _numberTry++;

        }while(((_answer1 != _secret1)&&(_answer2 != _secret2)) && (_numberTry <= 5));
    }

    if((_answer1 == _secret1)&&(_answer2 == _secret2)){
        printf("|| Great guess you guessed two right number");
        _model.point = _model.point + 20;
    }
    else if((_answer1 == _secret1)||(_answer2 == _secret2)){
        printf("|| Great guess you guessed two right number");
        _model.point = _model.point + 10;
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
        printf("\nCongratulations your final point is %d \n", _model.point);
        printf("saving result...");
        saveResult();
        getchar();
    }
};

void saveResult(){

    FILE *outfile;
    outfile = fopen ("GuessScore.txt", "r");
    if(outfile == NULL){
        outfile = fopen ("GuessScore.txt", "w+");
    }else{
        outfile = fopen ("GuessScore.txt", "a");
    }

    _models[0] = _model;

    fwrite(&_model, sizeof(struct GuessModel),1, outfile);
    fclose(outfile);
};

void readResult(){
    FILE *infile;
    struct GuessModel input;

    infile = fopen("GuessScore.txt","r");

    if(infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        fclose(infile);
        exit(1);
    }
     // read file contents till end of file
    while(fread(&input, sizeof(struct GuessModel), 1, infile)){
        printf ("%s \t %d \t %d \n", input.player,input.lvl, input.point);
    }
    fclose(infile);
    //return 0;
};
