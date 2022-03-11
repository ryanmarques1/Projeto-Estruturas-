#ifndef CHAPTER1_H_INCLUDED
#define CHAPTER1_H_INCLUDED


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

// Fun��o que Insere os dados na Fila (Comando e Numero de Vezes que ir� repetir
void insere_listaComandos(sFila *f, struct Dices infos){
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

int Move_Player(sFila *f){
    // Direita = 1 | Esquerda = 2 | Acima = 3 | Baixo = 4
    int sentido = 1;
    while(f->ini != NULL){

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
