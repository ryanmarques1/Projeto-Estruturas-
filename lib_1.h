#ifndef LIB_1_H_INCLUDED
#define LIB_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Chapter1.h"
#include "Chapter2.h"
#include "Chapter3.h"

/// Menu Programa

// Menu do Programa
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

// Instruções de como jogar
void Instrucoes(void){
    printf("Podes assumir 4 sentidos: Direita, Esquerda, Cima, Baixo (Depende da Seta de Indicação).\n");
    printf("O Player possui 3 vidas e perde a vida caso o Player Não chegue ao final. Perdendo as 3 vidas GAME OVER.\n");
    printf("\n3 dificuldades - Fase 1: Facil | Fase 2: Medio | Fase 3: Dificil\n");
}

// Função para mostrar o Grupo do Programa
void Credits(void){
    printf("Equipe: Ryan Marques, Bernardo Miranda, Mariana Castro\n\n");
}

// Função de Saida do Programa
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

/// Menu Fase

// Cria o Tabuleiro atribuindo valores a posições da Matriz
char** Create_Tabuleiro(int dimensao){
//    system("cls");
    char **TabMat;
    int i,j;
    TabMat = malloc(dimensao * sizeof(char*));
    for(i = 0; i < dimensao; i++){
        TabMat[i]  = malloc(dimensao * sizeof(char));
        for(j = 0; j < dimensao; j++){
            if(i == 0 && j == 0) TabMat[0][0] = 'P';
            else if(i == 7 && j == 7) TabMat[7][7] = 'O';
            else TabMat[i][j] = ' ';
        }
    }
    return TabMat;
}

//Imprime o Tabuleiro
//void Impress_Tabuleiro(char **TabMat, int dimensao){
//    int i,j;
//    for(i = 0; i < dimensao; i++){
//        printf("|---|---|---|---|---|---|---|---|\n");
//        for(j  = 0; j < dimensao; j++){
//            if(j == 0) printf("|");
//            printf(" %c |", TabMat[i][j]);
//            if(j == 7) printf("\n");
//        }
//        if(i == 7)  printf("|---|---|---|---|---|---|---|---|\n");
//    }
//
//}
///---------------------------===========--------------------==================////
void Orientacoes1(int ot,char** MAT,int* x, int* y){ //Função de Andar
    if(ot == 1){// Para Direita
        *y = *y + 1;
        if(*y < 8){
            if(MAT[(*x)][(*y)] == 'X'){//P volta a sua posição anterior pois tem obstaculo
                *y = *y - 1;
            }else{// P assume a posição se não houver obstaculo
                MAT[(*x)][(*y)] = 'P';
                MAT[(*x)][(*y-1)] = ' ';
            }
        }else{
            *y = *y - 1;
        }
    }else
    if(ot == 2){ // Para Esquerda
        *y = *y - 1;
        if(*y > -1){
            if(MAT[(*x)][(*y)] == 'X'){//P volta a sua posição anterior pois tem obstaculo
                *y = *y + 1;
            }else{// P assume a posição se não houver obstaculo
                MAT[(*x)][(*y)] = 'P';
                MAT[(*x)][(*y+1)] = ' ';
            }
        }else{
            *y = *y + 1;

        }

    }
    else
    if(ot == 3){ // Para Cima
        *x = *x - 1;
        if(*x > -1){
            if(MAT[(*x)][(*y)] == 'X'){//P volta a sua posição anterior pois tem obstaculo
                *x = *x + 1;
            }else{// P assume a posição se não houver obstaculo
                MAT[(*x)][(*y)] = 'P';
                MAT[(*x+1)][(*y)] = ' ';
            }
        }else{
            *x = *x + 1;
        }
    }
    else
    if(ot == 4){ // Para Baixo
        *x = *x + 1;
        if(*x < 8){
            if(MAT[(*x)][(*y)] == 'X'){//P volta a sua posição anterior pois tem obstaculo
                *x = *x - 1;
            }else{ // P assume a posição se não houver obstaculo
                MAT[(*x)][(*y)] = 'P';
                MAT[(*x-1)][(*y)] = ' ';
            }
        }else{
            *x = *x - 1;
        }
    }
}

void Orientacoes2(int* ot, char c){ // Função de Girar
    if(*ot == 1){ // Direção para Direita
        if(c == 'D'){
            *ot = 4;
        }else{
            *ot = 3;
        }
    }else
    if(*ot == 2){// Direção para Esquerda
        if(c == 'D'){
            *ot = 3;
        }else{
            *ot = 4;
        }
    }
    else
    if(*ot == 3){// Direção para Cima
       if(c == 'D'){
            *ot = 1;
        }else{
            *ot = 2;
        }
    }
    else
    if(*ot == 4){// Direção para Baixo
        if(c == 'D'){
            *ot = 2;
        }else{
            *ot = 1;
        }
    }
}
///---------------------------===========--------------------==================////
//Imprime Dados do Player
void Dados_Player(int ot,int vida){
    printf("\n-=-=-=-=-=-=-= Status do Player =-=-=-=-=-=-=-\n");
    if(ot == 1){
        printf("P >\tVida: %d\n", vida);
    }else
    if(ot == 2){
        printf("< P\tVida: %d\n", vida);
    }else
    if(ot == 3){
        printf("P1\tVida: %d\n^\n", vida);
    }else
    if(ot == 4){
        printf("P\tVida: %d\nv\n", vida);
    }
    printf("\n");
}

//Atualização da Tabela
void Att_Tab(char **TabMat, int dimensao){
    int i,j;
    for(i = 0; i < dimensao; i++){
        printf("|---|---|---|---|---|---|---|---|\n");
        for(j  = 0; j < dimensao; j++){
            if(j == 0) printf("|");
            printf(" %c |", TabMat[i][j]);
            if(j == 7) printf("\n");
        }
        if(i == 7)  printf("|---|---|---|---|---|---|---|---|\n");
    }
}
#endif // LIB_1_H_INCLUDED
