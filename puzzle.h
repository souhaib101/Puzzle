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



int read_all_files(int argc, char ** argv, puzzle **root);

void print_puzzle(puzzle **root, FILE *output);

void free_puzzle(puzzle **root);

int read_one_file(char* file_name, puzzle *element);

void add_element(puzzle *root, puzzle *new);

int read_pixles(FILE *input, puzzle *element);

int read_max_grauWert(FILE *input, puzzle *element);

int read_spalten_zeilen(FILE *input, puzzle *element);

int read_magicNumber(FILE *input, puzzle *element);

puzzle* new_puzzle(void);

void free_element(puzzle* element);

int print_one_file(puzzle* one, char* output_name);

void print_foot(FILE* output, puzzle *element);

void print_pixels(FILE* output, puzzle *element);

void print_head(FILE* output, puzzle *element);