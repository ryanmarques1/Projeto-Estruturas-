#ifndef CHAPTER1_H_INCLUDED
#define CHAPTER1_H_INCLUDED
#include "lib_1.h"


///------------------------------------------------------------------------------------------------------------------------------------
void Orientacoes1(int ot,char** MAT,int* x, int* y);
void Orientacoes2(int* ot, char c);
void Dados_Player_F1(int ot,int vida);
void Att_Tab(char **TabMat, int dimensao);
//Estrutura Fila Din�mica.
// Dados Da Fila (Struct Dices)
typedef struct Dices{
    int NumdoComando;
    int vezesExec;
}infos;

// N� que contem Os Dados e posi��es do n� da frente
typedef struct NOS{
    struct Dices infos;
    struct NOS* next;
}NOF;

// "Cabe�alho" da Fila onde Contem seu Inicio e Fim
typedef struct Fila{
    NOF* ini;
    NOF* fim;
}sFila;

// Alocar a Fila
sFila* alloc_fila(){
    return malloc(sizeof(sFila));
}

// Alocar N�s
NOF* alloc_nos(){
    return malloc(sizeof(NOF));
}
// Fun��o de Iniciar Fila, Atribuindo Inicio e Fim como NULL;
void ini_fila(sFila *f){
    f->ini = NULL;
    f->fim = NULL;
}

// Fun��o de Verificar se a Fila est� vazia
int fila_vazia(sFila *f){
    if(f->ini == NULL)
        return 1;
    return 0;
}
void destroi_fila(sFila *f){
    NOF* aux = NULL;
    if(f != NULL){
        while(f->ini != NULL){
            aux = f->ini;
            f->ini = f->ini->next;
            free(aux);
        }
        free(f);
        printf("\nDeu certo!\n");
        return;
    }
    printf("\nN�o deu certo!\n");
}
///------------------------------------------------------------------------------------------------------------------------------------
///-------------------------///
// Fun��o que Insere os dados na Fila (Comando e Numero de Vezes que ir� repetir
void insere_listaComandos_F1(sFila *f, struct Dices infos){
    NOF* nos = NULL;
    nos = alloc_nos();
    if(nos != NULL){
        nos->infos = infos;
        nos->next = NULL;
        if(fila_vazia(f))
            f->ini = nos;
        else
            f->fim->next = nos;
        f->fim = nos;
    }else{
        printf("\nErro de aloca��o\n");
        exit(1);
    }
}
// Mover Player na Tabela
int Move_Player_F1(sFila *f,char** MAT, int vida){
    NOF* aux = f->ini;
    //Orienta��o Player = ot
    // Direita = 1 | Esquerda = 2 | Acima = 3 | Baixo = 4
    int ot = 1,i,x=0,y=0,h=8;
    //x e y s�o as posi��es do P no tabuleiro (Matriz)

    //Loop ate Fila Acabar
    while(aux != NULL){
        if(aux->infos.NumdoComando == 1){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y); //Orient��o de Andar para Frente
                Orientacoes2(&ot,'D'); //Orient��o de Girar pra Direita
                Orientacoes1(ot,MAT,&x,&y); //Orient��o de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos.NumdoComando == 2){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y); //Orient��o de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y); //Orient��o de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos.NumdoComando == 3){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes2(&ot,'D');//Orient��o de Girar pra Direita
                Orientacoes1(ot,MAT,&x,&y);//Orient��o de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y);//Orient��o de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos.NumdoComando == 4){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes2(&ot,'E');
                Orientacoes1(ot,MAT,&x,&y);
                Orientacoes1(ot,MAT,&x,&y);
            }
            Att_Tab(MAT,h);
        }
        Dados_Player_F1(ot,vida);
        NOF* aux2 = aux;
        aux = aux->next;
        free(aux2);
    }
    //F recebe Aux para resetar, ou seja, falar que lista ta vazia
    f->ini=aux;
    f->fim=aux;
    if(x == 7 && y == 7){
        return 1; // Vitoria da Fase
    }else{
        return 0; // Derrota da Fase
    }

}
// Posi��o das Barreiras onde o Player n�o pode ultrapassar (Pr� Defenido)
void traps_fase1(char **TabMat){
    ///Fase 1 TRAPS.///(Completo)
    TabMat[0][7] = 'X';
    TabMat[1][7] = 'X';
    TabMat[1][1] = 'X';
    TabMat[1][2] = 'X';
    TabMat[1][5] = 'X';
    TabMat[2][1] = 'X';
    TabMat[2][5] = 'X';
    TabMat[3][3] = 'X';
    TabMat[3][4] = 'X';
    TabMat[3][5] = 'X';
    TabMat[5][0] = 'X';
    TabMat[5][1] = 'X';
    TabMat[5][2] = 'X';
    TabMat[5][7] = 'X';
    TabMat[5][6] = 'X';
    TabMat[4][0] = 'X';
    TabMat[4][1] = 'X';
    TabMat[6][1] = 'X';
    TabMat[6][2] = 'X';
    TabMat[6][3] = 'X';
    TabMat[7][3] = 'X';
    TabMat[7][5] = 'X';
    TabMat[7][6] = 'X';
    ///----------------///
}

#endif // CHAPTER1_H_INCLUDED
