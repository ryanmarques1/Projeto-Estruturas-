#ifndef LIB_1_H_INCLUDED
#define LIB_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/// Menu Programa

/// Menu Fase



int Impress_Tabuleiro(int dimensao){
    system("cls");
    char **TabMat;
    int i,j;
    TabMat = malloc(dimensao * sizeof(char*));
    for(i = 0; i < dimensao; i++){
        TabMat[i]  = malloc(dimensao * sizeof(char));
        printf("|---|---|---|---|---|---|---|---|\n");
        for(j = 0; j < dimensao; j++){
            if(j == 0) printf("|");
            if(i == 0 && j == 0) TabMat[0][0] = 'P';
            else if(i == 7 && j == 7) TabMat[7][7] = 'O';
            else TabMat[i][j] = ' ';
            printf(" %c |", TabMat[i][j]);
            if(j == 7) printf("\n");
        }
        if(i == 7) printf("|---|---|---|---|---|---|---|---|\n");
    }
    getchar();
    return 1;
}

void Instrucoes(void){
    printf("Podes assumir 4 sentidos: Direita, Esquerda, Cima, Baixo.\nTens 3 vidas, perdeu as 3 GAME OVER.\n Dificuldade aleatória (Rogue Like).");
}
void Credits(void){
    printf("Equipe: Ryan Marques, Bernardo Miranda, Mariana Castro\n\n");
}
void Exit(void){
    char ex;
    printf("\nDesejas sair do jogo? \n");
    printf("Y -> Sim , N -> Não");
    printf(": ");
    getchar();
    scanf("%c", &ex);
    if(ex == 'N' || ex == 'n') return;
    else exit(0);
}
/// Primeira Fase
  ///7 caminhos pré-definidos. 8obstaculos - Fila Dinâmica ou Deque Dinâmico.
/// Segunda Fase
  ///5 caminhos pré-definidos. 13 obstaculos - Pilha dinâmica
/// Terceira Fase
  ///1 ou 2 caminhos pré-definido(s). 18 obstaculos - Fila Dinâmica ou Deque Dinâmico e Pilha dinâmica
///Etc
/*
Fazer caminhos pré definidos e depois dispor dinamicamente
os obstaculos que não PODEM interferir nos caminhos para a vitoria.
*/

void menu(){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("=-=-=-=-=-=    Jogo    -=-=-=-=-=-=\n");
    printf("=-=-=    Comandos Em Loop    -=-=-=\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("Menu de Opcoes\n");
    printf("1 - Iniciar Jogo\n");
    printf("2 - Instruções\n");
    printf("3 - Créditos\n");
    printf("4 - Sair\n\n");
}
#endif // LIB_1_H_INCLUDED
