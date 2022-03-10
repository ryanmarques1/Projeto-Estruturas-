#ifndef CHAPTER1_H_INCLUDED
#define CHAPTER1_H_INCLUDED


/*

Estrutura Fila Dinâmica.
*/
typedef struct Dices{
    int NumdoComando;
    int vezesExec;
}infos;
typedef struct NOS{
    struct Dices infos;
    struct NOS* next;
}NOF;
typedef struct Fila{
    NOF* ini;
    NOF* fim;
}sFila;

sFila* alloc_fila(){
    return malloc(sizeof(sFila));
}
NOF* alloc_nos(){
    return malloc(sizeof(NOF));
}
void ini_fila(sFila *f){
    f->ini = NULL;
    f->fim = NULL;
}
int fila_vazia(sFila *f){
    if(f->ini == NULL)
        return 1;
    return 0;
}
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
        printf("\nErro de alocação\n");
        exit(1);
    }
}
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
