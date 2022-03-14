#ifndef CHAPTER2_H_INCLUDED
#define CHAPTER2_H_INCLUDED


//Funções da lib_1.h
void Orientacoes1(int ot,char** MAT,int* x, int* y);
void Orientacoes2(int* ot, char c);
void Dados_Player(int ot,int vida);
void Att_Tab(char **TabMat, int dimensao);
void Comandos_F2();

///Definição da Pilha ----------------------------------------------------------------------------------------------------------------
typedef struct Dices_f2{
    int NumdoComando;
    int vezesExec;
}infos_f2;

typedef struct spilha*Pilha; //Ponteiro para Ponteiro

typedef struct spilha{
    struct Dices_f2 infos_f2;
    struct spilha *top;
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
void destroi_pilha(Pilha *pl){
    NOP* aux = NULL;
    if(pl != NULL){
        while((*pl)!=NULL){
            aux = *pl;
            *pl = (*pl)->top;
            free(aux);
        }
        free(pl);
    }
}
// Função que Insere os dados na Pilha (Comando e Numero de Vezes que irá repetir)
void insere_listaComandos_F2(Pilha *pl, struct Dices_f2 infos_f2){
    NOP* nos = NULL;
    nos = alloc_nosP();
    if(nos != NULL){
        nos->infos_f2 = infos_f2; //recebe os dados escritos
        nos->top = (*pl);//proximo no que é null, recebe topo pilha.
        *pl = nos; //topo da pilha aponta para novo nó.
    }else{
        printf("\nErro de alocação!\n");
        exit(1);
    }
}

//
int Move_Player_F2(Pilha *pl,char** MAT, int vida){
    NOP *aux = *pl;
    //Orientação Player = ot
    // Direita = 1 | Esquerda = 2 | Acima = 3 | Baixo = 4
    int ot = 4,i,x=0,y=0,h=8;

    while(aux != NULL){
        if(aux->infos_f2.NumdoComando == 1){
            for(i = 0; i < aux->infos_f2.vezesExec; i++){
                Orientacoes2(&ot,'D');
                Orientacoes1(ot,MAT,&x,&y);
                Orientacoes1(ot,MAT,&x,&y);
                Orientacoes2(&ot,'E');
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos_f2.NumdoComando == 2){
            for(i = 0; i < aux->infos_f2.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y);
                Orientacoes1(ot,MAT,&x,&y);
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos_f2.NumdoComando == 3){
            for(i = 0; i < aux->infos_f2.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y);
                Orientacoes2(&ot,'E');
                Orientacoes1(ot,MAT,&x,&y);
                Orientacoes1(ot,MAT,&x,&y);
            }
            Att_Tab(MAT,h);
        }
        Comandos_F2();
        Dados_Player(ot,vida);// Mostrar a vida do Player
        NOP* aux2 = aux;
        aux = aux->top;
        free(aux2);
    }
    *pl = NULL;
    if(x == 7 && y == 7){
        return 1; // Vitoria da Fase
    }else{
        return 0; // Derrota da Fase
    }
}
void traps_fase2(char **TabMat){
    ///Fase 2 TRAPS
    TabMat[0][1] = 'X';
    TabMat[0][4] = 'X';
    TabMat[0][5] = 'X';
    TabMat[0][6] = 'X';
    TabMat[2][2] = 'X';
    TabMat[2][1] = 'X';
    TabMat[2][3] = 'X';
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
void Comandos_F2(){
    printf("\n-=-=-=-=-=-=-= Comandos =-=-=-=-=-=-=-\n");
    printf("1) [D,F,F,E]\t"); //Comando 1
    printf("2) [F,F]\t");     //Comando 2
    printf("3) [F,E,F,F]\t"); //Comando 3
}

///-------------------------///

#endif // CHAPTER2_H_INCLUDED
