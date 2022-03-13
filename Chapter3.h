#ifndef CHAPTER3_H_INCLUDED
#define CHAPTER3_H_INCLUDED
#include "lib_1.h"
///Funções auxiliares.
void Orientacoes1(int ot,char** MAT,int* x, int* y);
void Orientacoes2(int* ot, char c);
void Dados_Player(int ot,int vida);
void Att_Tab(char **TabMat, int dimensao);
void Comandos_F3();
///-------------------Estruturas----------------------///


//Estrutura Fila Dinâmica.
// Dados Da Fila (Struct Dices)
typedef struct Dices_f3{
    int NumdoComando;
    int vezesExec;
}infos_f3;
// Nó que contem Os Dados e posições do nó da frente
typedef struct NOS_2{
    struct Dices infos;
    struct NOS_2* next;
}NOF_2;
// "Cabeçalho" da Fila onde Contem seu Inicio e Fim
typedef struct Fila_2{
    NOF_2* ini;
    NOF_2* fim;
}sFila_2;
sFila_2 *alloc_fila_2(){
    return malloc(sizeof(sFila_2));
}
NOF_2 *alloc_nos_2(){
    return malloc(sizeof(NOF_2));
}
void ini_fila_2(sFila_2 *fl){
    fl->ini = NULL;
    fl->fim = NULL;
}

///Pilha Dinamica.--------------.///
typedef struct Dices_f3p{
    int NumdoComando;
    int vezesExec;
}infos_f3p;

typedef struct spilha_2*Pilha_2; //Ponteiro para Ponteiro

typedef struct spilha_2{
    struct Dices_f3p infos_f3p;
    struct spilha_2 *top;
}NOP_2;

Pilha_2* alloc_pilha_2(){
    return malloc(sizeof(Pilha_2));
}
NOP_2* alloc_nosP_2(){
    return malloc(sizeof(NOP_2));
}
void ini_pilha_2(Pilha_2 *pl){
    *pl = NULL;
}
///-----------------------------------------------///









///-----------------------------------------------///
///Traps---///

void traps_fase3(char** TabMat){
    ///.
}

///---Comandos_F3---///

void Comandos_F3(){
    printf("\n-=-=-=-=-=-=-= Comandos =-=-=-=-=-=-=-\n");
    printf("_"); //Comando 1
    printf("_"); //Comando 2
    printf("_"); //Comando 3
    printf("_"); //Comando 4
}
#endif // CHAPTER3_H_INCLUDED
