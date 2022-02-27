#ifndef LIB_1_H_INCLUDED
#define LIB_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/// Menu Programa

/// Menu Fase

void Tabuleiro(){
    int i,j;
    char TabMat [8][8];
    TabMat[0][0] = 'P';
    TabMat[7][7] = 'O';

    for(i = 0; i < 8; i++){
        printf("|---|---|---|---|---|---|---|---|\n");
        for(j = 0; j < 8; j++){
            if(j == 0){
                printf("|");
            }
            printf(" %c |",TabMat[i][j]);
            if(j == 7){
                printf("\n");
            }
        }
        if(i == 7){
            printf("|---|---|---|---|---|---|---|---|\n");
        }
    }

//    printf("| P |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   |   |\n");
//    printf("|   |   |   |   |   |   |   | O |\n");
//    printf("|---|---|---|---|---|---|---|---|\n");
}

/// Primeira Fase

/// Segunda Fase

/// Terceira Fase

///Etc
/*

*/




#endif // LIB_1_H_INCLUDED
