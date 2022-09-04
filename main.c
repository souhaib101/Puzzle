#include<stdio.h>
#include"puzzle.h"


int main(int argc, char** argv){
    
    /*
    at least we got 3 string input {"./puzzle", "eingabe.txt", "ausgabe.txt"}
    */
    if(argc <= 3){
        return 1;
    }


    /*TODO:
    read all input datei and store it in array from type puzzle, each puzzle should save one file.
    the file is formatted
    */
    
    // pointer to hold the adress of first puzzle 
    puzzle *root = NULL;
    
    read_all_files(argc, argv, &root);
    print_puzzle(root, stdout);
    free_puzzle(root);



   
   return 0;
}