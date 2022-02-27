#ifndef LIB_1_H_INCLUDED
#define LIB_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/// Menu Programa

/// Menu Fase

void Tabuleiro(){
    int i,j;

    // Tabela em Matriz
    char TabMat [8][8];

    // Atribui a Matriz da Tabela as posições menos as Colunas 'x'
    TabMat[7][7] = 'O';
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(i == 0 && j == 0){
                TabMat[0][0] = 'P';
            }else
            if(i == 7 && j == 7){
                TabMat [8][8] = 'O';
            }else{
                TabMat [i][j] = ' ';
            }
        }
    }

    // Imprime a Tabela
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
}

/// Primeira Fase

/// Segunda Fase

/// Terceira Fase

///Etc
/*

*/




#endif // LIB_1_H_INCLUDED
