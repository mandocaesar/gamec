#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "qa_game.h"
#include "menu.h"

struct QuestionModel{
    char question[200], option1[200], option2[200], option3[200];
    int answer;
};

struct QAModel{
    char player[50];
    int point;
};

struct QuestionModel _questions[5];
int _point, _questionNumber;
struct QAModel _qamodel;

//Initialize questions
void createQuestions(){

    FILE *outfile;
    outfile = fopen ("QA.txt", "r");
    if(outfile == NULL){
        outfile = fopen ("QA.txt", "w+");
    }else{
        outfile = fopen ("QA.txt", "a");
    }

    struct QuestionModel _model[5] = {
        {"What is The Capital of Kingdom of Saudi Arabia ?","Jeddah","Riyadh","Dammam", 2},
        {"2 + 2 = ?","31","100","4", 3},
        {"What is The Capital of Kingdom of Great Britain ?","London","Manchester","Nottingham", 1},
        {"What is The Largest Animal ?","Blue Whale","Elephant","Ant", 1},
        {"What should i put on my foot ?","Hat","Scarf","Socks", 3}
    };

    for(int i = 0 ; i < 5 ;i++){
        fwrite(&_model[i], sizeof(struct QuestionModel),1, outfile);
    }
    fclose(outfile);
};

void readQuestions(){
    FILE *infile;
    struct QuestionModel input;

    infile = fopen("QA.txt","r");

    if(infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        fclose(infile);
        exit(1);
    }
    int i = 0;
    while(fread(&input, sizeof(struct QuestionModel), 1, infile)){
        _questions[i] = input;
        i++;
    }
    fclose(infile);
}

void initGame()
{
    readQuestions();
    _questionNumber = 0;

    printf("Enter your username:");
    scanf("%s", _qamodel.player);
    _qamodel.point = 0;
}

void startGame(){
    initGame();
    do{
        int _answer = 0;
        int _qanswer = _questions[_questionNumber].answer;

        printf("\nQ%d. %s\n",_questionNumber + 1,&_questions[_questionNumber].question);
        printf("[1] %s\n",&_questions[_questionNumber].option1);
        printf("[2] %s\n",&_questions[_questionNumber].option2);
        printf("[3] %s\n",&_questions[_questionNumber].option3);

        printf("Your answer : ");
        scanf("%d",&_answer);

        if(_answer == _qanswer){
            printf("\nexcellent!");
            _qamodel.point += 10;

        }else{
            printf("\nSorry wrong answer!");
        }
        printf("\npress any key for next question");
        _getch();

        _questionNumber++;
        system("@cls||clear");

    }while(_questionNumber < 5);
    saveQAresult();

    printf("\nCongratulations %s you got %d", _qamodel.player, _qamodel.point);
    printf("\npress any key to go back to main menu");
    _getch();
    system("@cls||clear");
    Start();
}

void saveQAresult(){
    FILE *outfile;
    outfile = fopen ("QAScore.txt", "r");
    if(outfile == NULL){
        outfile = fopen ("QAScore.txt", "w+");
    }else{
        outfile = fopen ("QAScore.txt", "a");
    }

    fwrite(&_qamodel, sizeof(struct QAModel),1, outfile);
    fclose(outfile);
}

void viewQAresult(){
    FILE *infile;
    struct QAModel input;

    infile = fopen("QAScore.txt","r");

    if(infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        fclose(infile);
        exit(1);
    }
    system("@cls||clear");

    printf("||================= QA Game Score================\n");
    printf("||Player name \t || Point\n");
    printf("||==================================================\n");

    while(fread(&input, sizeof(struct QAModel), 1, infile)){
        printf ("||%s \t ||%d\n", input.player, input.point);
    }

    fclose(infile);
    printf("||==================================================\n");
    printf("Press anything to continue..");
     _getch();
     system("@cls||clear");

};

