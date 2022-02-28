#ifndef LIB_1_H_INCLUDED
#define LIB_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/// Menu Programa

/// Menu Fase



void Impress_TabFase1(void){
    system("cls");
    int i,j;
    char TabMat[8][8];
    for(i = 0; i < 8; i++){
        printf("|---|---|---|---|---|---|---|---|\n");
        for(j = 0; j < 8; j++){
            if(j == 0) printf("|");
            if(i == 0 && j == 0) TabMat[0][0] = 'P';
            else if(i == 7 && j == 7) TabMat[7][7] = 'O';
            else{
                for(int k = 0; k < 10; k++){
                    int a = rand() % 5;
                    if(a == 0) ///se o numero randomico for 0, � trap.
                        TabMat[i][j] = 'X';
                    else
                        TabMat[i][j] = ' ';
                }
            }
            printf(" %c |", TabMat[i][j]);
            if(j == 7) printf("\n");
        }
        if(i == 7) printf("|---|---|---|---|---|---|---|---|\n");
    }
    getchar();
}
void Instrucoes(void){
    printf("Podes assumir 4 sentidos: Direita, Esquerda, Cima, Baixo.\nTens 3 vidas, perdeu as 3 GAME OVER.");
}
void Credits(void){
    printf("Equipe: Ryan Marques, Bernardo Miranda, Mariana Castro\n\n");
}
void Exit(void){
    char ex;
    printf("\nDesejas sair do jogo? \n");
    printf("Y -> Sim , N -> N�o");
    printf(": ");
    getchar();
    scanf("%c", &ex);
    if(ex == 'N' || ex == 'n') return;
    else exit(0);
}
/// Primeira Fase
  ///7 caminhos pr�-definidos. 8obstaculos - Fila Din�mica ou Deque Din�mico.
/// Segunda Fase
  ///5 caminhos pr�-definidos. 13 obstaculos - Pilha din�mica
/// Terceira Fase
  ///1 ou 2 caminhos pr�-definido(s). 18 obstaculos - Fila Din�mica ou Deque Din�mico e Pilha din�mica
///Etc
/*
Fazer caminhos pr� definidos e depois dispor dinamicamente
os obstaculos que n�o PODEM interferir nos caminhos para a vitoria.
*/

void menu(){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("=-=-=-=-=-=    Jogo    -=-=-=-=-=-=\n");
    printf("=-=-=    Comandos Em Loop    -=-=-=\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("Menu de Opcoes\n");
    printf("1 - Iniciar Jogo\n");
    printf("2 - Instru��es\n");
    printf("3 - Cr�ditos\n");
    printf("4 - Sair\n\n");
}
#endif // LIB_1_H_INCLUDED
