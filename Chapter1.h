#ifndef CHAPTER1_H_INCLUDED
#define CHAPTER1_H_INCLUDED


/*

Estrutura Fila Din�mica.
*/
typedef struct Dados{
};
typedef struct Fila{
};
typedef struct NOS{
};

















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
void traps_fase2(char **TabMat){
    ///Fase 2 TRAPS.///(Incompleto)
    TabMat[0][1] = 'X';
    TabMat[0][4] = 'X';
    TabMat[0][5] = 'X';
    TabMat[0][6] = 'X';
    TabMat[0][7] = 'X';
    TabMat[2][1] = 'X';
    TabMat[4][0] = 'X';
    TabMat[4][1] = 'X';
    TabMat[4][3] = 'X';
    TabMat[4][4] = 'X';
    TabMat[4][5] = 'X';
    TabMat[4][6] = 'X';
    TabMat[5][7] = 'X';
    TabMat[6][7] = 'X';
    ///-------------///
}
#endif // CHAPTER1_H_INCLUDED
