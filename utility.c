#include <stdio.h>
#include "utility.h"

struct GuessModel{
   char Player[50];
   int Score, Level;
};

struct QAModel{
   char Player[50];
   int Score;
};

void createFile(char *FileName, char *Payload){
    FILE *fptr;
    printf("%s",Payload);

    fptr = fopen(FileName, "w+");

    fprintf(fptr,"%s",Payload);
    fclose(fptr);
};

int checkFile(char *FileName){

};


