#ifndef CHAPTER2_H_INCLUDED
#define CHAPTER2_H_INCLUDED
#include "lib_1.h"


void Orientacoes1(int ot,char** MAT,int* x, int* y);
void Orientacoes2(int* ot, char c);
void Dados_Player_F1(int ot,int vida);
void Att_Tab(char **TabMat, int dimensao);
///Definição da Pilha

typedef struct Dices_f2{
    int NumdoComando;
    int vezesExec;
}infos_f2;
typedef struct spilha*Pilha;
typedef struct spilha{
    struct Dices_f2 infos_f2;
    struct spilha *next;
}NOP;

Pilha* alloc_pilha(){
    return malloc(sizeof(Pilha));
}
NOP* alloc_nosP(){
    return malloc(sizeof(NOP));
}
void ini_pilha(Pilha *pl){
    *pl = NULL;
}
///------------------------------------------------------------------------------------------------------------------------------------
// Função que Insere os dados na Pilha (Comando e Numero de Vezes que irá repetir)
void insere_listaComandos_F2(Pilha *pl, struct Dices_f2 infos_f2){
    NOP* nos = NULL;
    nos = alloc_nosP();
    if(nos != NULL){
        nos->infos_f2 = infos_f2;
        nos->next = (*pl);//proximo no que é null, recebe topo pilha.
        *pl = nos; //topo da pilha aponta para novo nó.
    }else{
        printf("\nErro de alocação!\n");
        exit(1);
    }
}
void traps_fase2(char **TabMat){
    ///Fase 2 TRAPS.///(Incompleto)
    TabMat[0][1] = 'X';
    TabMat[0][4] = 'X';
    TabMat[0][5] = 'X';
    TabMat[0][6] = 'X';
    TabMat[0][7] = 'X';
    TabMat[2][2] = 'X';
    TabMat[2][1] = 'X';
    TabMat[2][3] = 'X';
    TabMat[2][4] = 'X';
    TabMat[4][0] = 'X';
    TabMat[4][1] = 'X';
    TabMat[4][3] = 'X';
    TabMat[4][4] = 'X';
    TabMat[3][6] = 'X';
    TabMat[3][5] = 'X';
    TabMat[5][7] = 'X';
    TabMat[6][7] = 'X';
    TabMat[6][3] = 'X';
    TabMat[6][4] = 'X';
    TabMat[7][4] = 'X';
    TabMat[7][5] = 'X';
    ///-------------///
}
///-------------------------///

#endif // CHAPTER2_H_INCLUDED
