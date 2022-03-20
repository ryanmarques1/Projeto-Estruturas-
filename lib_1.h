#ifndef LIB_1_H_INCLUDED
#define LIB_1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Chapter1.h"
#include "Chapter2.h"
#include "Chapter3.h"
/*
======================================================================|
#Equipe: 1 - Ryan Marques; 2 - Bernardo Miranda; 3 - Mariana Castro   |
#Projeto de Algoritmos e Estrutura de Dados - Jogo Comandos em Loop   |
#Uso Obrigatorio de Fila e Pilha em determiandas fases                |
======================================================================|

*/
/// Menu Programa

// Menu do Programa
void menu(void){
    printf("\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t=-=-=-=-=-=    Jogo    -=-=-=-=-=-=\n");
    printf("\t\t\t\t=-=-=    Comandos Em Loop    -=-=-=\n");
    printf("\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("- |Menu de Opções\n");
    printf("- |1 => Iniciar Jogo\n");
    printf("- |2 => Instruções\n");
    printf("- |3 => Créditos\n");
    printf("- |4 => Sair\n\n");
}

// Instruções de como jogar
void Instrucoes(void){
    system("cls");
    printf("Instruções do Jogo:\n\n");
    printf("1 - O Objetivo é chegar ao ponto (O) indicado em cada Tabela;\n");
    printf("2 - Deve escrever primeiro o Comando e depois a quantidade de vezes que irá repetir, caso queira finalizar digite \"0 0\";");
    printf("3 - O Player (P) possui 4 sentidos: Direita, Esquerda, Cima, Baixo (Depende da Seta de Indicação Mostrada).\n");
    printf("4 - O Player (P) possui 3 vidas e perde a vida caso não chegue ao objetivo (O). Perdendo as 3 vidas GAME OVER. A Vida é resetada ao concluir cada FASE!\n\n");
    system("pause");
    system("cls");
}

// Função para mostrar o Grupo do Programa
void Credits(void){
    system("cls");
    printf("Equipe:\n1 - Ryan Marques;\n2 - Bernardo Miranda;\n3 - Mariana Castro\n\n");
    printf("Projeto de Algoritmos e Estrutura de Dados - Jogo Comandos em Loop;\n");
    printf("Uso Obrigatorio de Fila e Pilha em determiandas fases;\n\n\n");
    system("pause");
    system("cls");
}

// Função de Saida do Programa
void Exit(void){
    char ex;
    system("cls");
    printf("\nDesejas sair do jogo? \n");
    printf("S -> Sim , N -> Não");
    printf(": ");
    scanf(" %c", &ex);
    if(ex == 'N' || ex == 'n'){
        system("cls");
        return;
    }else{
        exit(0);
    }
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
///-----------------------------------------------------------------------------------------------------------------------------------
//Imprime Dados do Player
void Dados_Player(int ot,int vida){
    printf("\n\t\t\t\t   -=-=-=-=-=-=-= Status do Player =-=-=-=-=-=-=-\n");
    if(ot == 1){
        printf("\t\t\t\t\t\t   P >\tVida: %d\n", vida);
    }else
    if(ot == 2){
        printf("\t\t\t\t\t\t   < P\tVida: %d\n", vida);
    }else
    if(ot == 3){
        printf("\t\t\t\t\t\t     ^\n\t\t\t\t\t\t     P\tVida: %d\n", vida);
    }else
    if(ot == 4){
        printf("\t\t\t\t\t\t     P\tVida: %d\n\t\t\t\t\t\t     v\n", vida);
    }
}

//Atualização da Tabela
void Att_Tab(char **TabMat, int dimensao){
    int i,j;
    for(i = 0; i < dimensao; i++){
        printf("\t\t\t\t\t|---|---|---|---|---|---|---|---|\n");
        for(j  = 0; j < dimensao; j++){
            if(j == 0) printf("\t\t\t\t\t|");
            printf(" %c |", TabMat[i][j]);
            if(j == 7) printf("\n");
        }
        if(i == 7)  printf("\t\t\t\t\t|---|---|---|---|---|---|---|---|\n");
    }
}
#endif // LIB_1_H_INCLUDED
