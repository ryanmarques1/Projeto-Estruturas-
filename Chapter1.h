#ifndef CHAPTER1_H_INCLUDED
#define CHAPTER1_H_INCLUDED

#include "lib_1.h"


///------------------------------------------------------------------------------------------------------------------------------------


//Estrutura Fila Dinâmica.
// Dados Da Fila (Struct Dices)
typedef struct Dices{
    int NumdoComando;
    int vezesExec;
}infos;

// Nó que contem Os Dados e posições do nó da frente
typedef struct NOS{
    struct Dices infos;
    struct NOS* next;
}NOF;

// "Cabeçalho" da Fila onde Contem seu Inicio e Fim
typedef struct Fila{
    NOF* ini;
    NOF* fim;
}sFila;

// Alocar a Fila
sFila* alloc_fila(){
    return malloc(sizeof(sFila));
}

// Alocar Nós
NOF* alloc_nos(){
    return malloc(sizeof(NOF));
}
// Função de Iniciar Fila, Atribuindo Inicio e Fim como NULL;
void ini_fila(sFila *f){
    f->ini = NULL;
    f->fim = NULL;
}

// Função de Verificar se a Fila está vazia
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
    printf("\nNão deu certo!\n");
}
///------------------------------------------------------------------------------------------------------------------------------------
///-------------------------///
// Função que Insere os dados na Fila (Comando e Numero de Vezes que irá repetir
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
        printf("\nErro de alocação\n");
        exit(1);
    }
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

//Imprime Dados do Player
void Dados_Player_F1(int ot,int vida){
    printf("\n-=-=-=-=-=-=-= Comandos =-=-=-=-=-=-=-\n");
    printf("1) [F,D,F]\t"); //Comando 1
    printf("2) [F,F]\t");     //Comando 2
    printf("3) [D,F,F]\t"); //Comando 3
    printf("4) [E,F,F]\n"); //Comando 4


    printf("\n-=-=-=-=-=-=-= Status do Player =-=-=-=-=-=-=-\n");
    if(ot == 1){
        printf("P >\tVida: %d\n", vida);
    }else
    if(ot == 2){
        printf("< P\tVida: %d\n", vida);
    }else
    if(ot == 3){
        printf("P^\tVida: %d\n^\n", vida);
    }else
    if(ot == 4){
        printf("P\tVida: %d\nv\n", vida);
    }
    printf("\n");
}

// Mover Player na Tabela
int Move_Player_F1(sFila *f,char** MAT, int vida){
    NOF* aux = f->ini;
    //Orientação Player = ot
    // Direita = 1 | Esquerda = 2 | Acima = 3 | Baixo = 4
    int ot = 1,i,x=0,y=0,h=8;
    //x e y são as posições do P no tabuleiro (Matriz)

    //Loop ate Fila Acabar
    while(aux != NULL){
        if(aux->infos.NumdoComando == 1){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
                Orientacoes2(&ot,'D'); //Orientção de Girar pra Direita
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos.NumdoComando == 2){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos.NumdoComando == 3){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes2(&ot,'D');//Orientção de Girar pra Direita
                Orientacoes1(ot,MAT,&x,&y);//Orientção de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y);//Orientção de Andar para Frente
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

// Posição das Barreiras onde o Player não pode ultrapassar (Pré Defenido)
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
