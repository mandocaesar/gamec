#include <stdio.h>
#include "utility.h"

struct GuessModel{
   char[50] Player;
   int Score, Level;
};

struct QAModel{
   char[50] Player;
   int Score;
};

void createFile(char *FileName){
    FILE *fptr;

    printf("%s",Header);
    printf("%s",&Header);

    fptr = fopen(FileName, "w+");

    fprintf(fptr,"%s","");
    fclose(fptr);
};

int checkFile(char *FileName){

};


