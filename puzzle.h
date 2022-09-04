#include<stdio.h>

typedef enum{  
    OK,
    NOT_ENOUGH_PARAM,
    DATEI_ERROR,
    DATEI_FORMAT_ERROR,
    MEM_ERROR
    }Error;

typedef struct puzzle
{
    char* magicNumber;
    int spalten;
    int zeilen;
    int maxGrauwert;
    int* pixle;
}puzzle;



void read_all_files(int argc, char ** argv, puzzle **root);

void print_puzzle(puzzle *root, FILE *output);

void free_puzzle(puzzle *root);