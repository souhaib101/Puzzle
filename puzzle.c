#include"puzzle.h"
#include<stdlib.h>
#include <string.h>


int read_magicNumber(FILE *input, puzzle *element)
{

    char magic[10];
    if(fscanf(input, "%s", magic) != 1){
        return DATEI_FORMAT_ERROR;
    }
        
    

    if(strstr(magic, "P2") == NULL){
        return DATEI_FORMAT_ERROR;
    }
    element->magicNumber = malloc((strlen(magic) +1) * sizeof(char));

    strcpy(element->magicNumber, magic);
    return OK;

}

int read_spalten_zeilen(FILE *input, puzzle *element)
{
    if(fscanf(input, "%i %i", &(element->spalten), &(element->zeilen)) != 2){
        return DATEI_FORMAT_ERROR;
    }
    return OK;
}

int read_max_grauWert(FILE *input, puzzle *element)
{
    if(fscanf(input, "%i", &(element->maxGrauwert)) != 1){
        return DATEI_FORMAT_ERROR;
    }
    return OK;
}

int read_pixles(FILE *input, puzzle *element)
{
    element->pixle = malloc(sizeof(int) * (element->spalten * element->zeilen));
    for (size_t i = 0; i < element->spalten * element->zeilen; i++)
    {
        int pixle;
        if(fscanf(input, "%i", &pixle) != 1){
            return DATEI_ERROR;
        }
        *(element->pixle + i) = pixle;
    }
    return OK;
}


int read_one_file(char* file_name, puzzle *element){
    FILE *input = fopen(file_name, "r");
    if(input == NULL){
        return DATEI_ERROR;
    }
    if(
    (read_magicNumber(input, element) ||
    read_spalten_zeilen(input, element) ||
    read_max_grauWert(input, element)||
    read_pixles(input, element)) != OK ){
        fclose(input);    
        return DATEI_FORMAT_ERROR;
    }
    fclose(input);
    return OK;
}

void add_element(puzzle *root, puzzle *new){

}

puzzle* new_puzzle(void)
{
    puzzle *new = malloc(sizeof(puzzle));
    new->magicNumber = NULL;
    new->maxGrauwert = 0;
    new->pixle = NULL;
    new->spalten = 0;
    new->zeilen = 0;
    return new;
}


// so we can now read on datei and print it on the terminal to check if out read work right.
//./puzzle images/berge_puzzleteil1.pgm output.pgm
int read_all_files(int argc, char **argv, puzzle **root){
    puzzle *ptr ;
    
        puzzle *element = new_puzzle();
        if(read_one_file(argv[1], element) != OK){
            free_element(element);
            free(root);
            return DATEI_ERROR;
        }
        ptr = element;
        //add_elemnt(root, element);
       
    
    
    print_one_file(ptr, argv[argc - 1]);
    free(ptr);
    return OK;
    
}

void print_head(FILE* output, puzzle *element){
    fprintf(output, "%s\n", element->magicNumber);
    fprintf(output, "%i %i\n", element->spalten, element->zeilen);
    fprintf(output, "%i\n", element->maxGrauwert);
}

void print_pixels(FILE* output, puzzle *element)
{
     for (size_t i = 0; i < element->zeilen - 1; i++)
    {
        for (size_t j = 0; j < element->spalten; j++)
        {
            fprintf(output, "%i ", *(element->pixle + ((i * element->spalten) + j)));
            /*if (j != (ptr->spalten - 1))
            {
                fprintf(ausgabe, " ");
            }*/
        }
        fprintf(output, "\n");
    }
}

void print_foot(FILE* output, puzzle *element)
{
int *pixle;
    pixle = element->pixle;
    for (size_t i = (element->zeilen - 1) * element->spalten; i < (element->zeilen) * element->spalten; i++)
    {

        fprintf(output, "%i ", *(pixle + i));
    }
    fprintf(output, "\n");
}

int print_one_file(puzzle* one, char* output_name){
    FILE *output = fopen(output_name, "w");
    if(output == NULL){
        return DATEI_ERROR;
    }
    print_head(output, one);
    print_pixels(output, one);
    print_foot(output, one);
    fclose(output);
    return OK;
}

void print_puzzle(puzzle **root, FILE *output){

    

}


void free_puzzle(puzzle **root){

}

void free_element(puzzle* element){
    free(element->pixle);
    free(element->pixle);


    free(element->magicNumber);
    
    free(element);
}