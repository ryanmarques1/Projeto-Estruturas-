#ifndef CHAPTER3_H_INCLUDED
#define CHAPTER3_H_INCLUDED
#include "lib_1.h"
///Funções auxiliares.
void Orientacoes1(int ot,char** MAT,int* x, int* y);
void Orientacoes2(int* ot, char c);
void Dados_Player(int ot,int vida);
void Att_Tab(char **TabMat, int dimensao);
void Comandos_F3();
///-------------------Sobre as Estruturas----------------------///

NOF* alloc_nos();
void ini_fila(sFila *f);


NOP* alloc_nosP();
void ini_pilha(Pilha *pl);
///-----------------------------------------------///



int Move_Player_F3(char **MAT,int vida){
    return 1;
}





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
