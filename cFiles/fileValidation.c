#include<stdio.h>
#include"../headerFiles/fileValidation.h"

unsigned char FileValidation(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r+");

    if (file != NULL) {
        printf("Failas sekmingai atidarytas\n");
        fclose(file);
        return 1;
    }
    else {
        printf("Nepavyko atidaryti duomenu failo\n");
        return 0;
    }
}