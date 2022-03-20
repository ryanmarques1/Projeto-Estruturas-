#ifndef CHAPTER3_H_INCLUDED
#define CHAPTER3_H_INCLUDED
/*
======================================================================|
#Equipe: 1 - Ryan Marques; 2 - Bernardo Miranda; 3 - Mariana Castro   |
#Projeto de Algoritmos e Estrutura de Dados - Jogo Comandos em Loop   |
#Uso Obrigatorio de Fila e Pilha em determiandas fases                |
======================================================================|

*/

///Funções auxiliares.
void Orientacoes1(int ot,char** MAT,int* x, int* y);
void Orientacoes2(int* ot, char c);
void Dados_Player(int ot,int vida);
void Att_Tab(char **TabMat, int dimensao);
void Comandos_F3();
void Imprimir_Fila(NOF* aux);
void Imprimir_Pilha(NOP* aux);

///--------------------------------------------------------///


//Movimentação da Parte 1 (Fila)
int Move_Player_F3_P1(sFila *f,char **MAT,int vida){
    NOF* aux = f->ini;
    //Orientação Player = ot
    // Direita = 1 | Esquerda = 2 | Acima = 3 | Baixo = 4
    int ot = 4,i,x=0,y=0,h=8;
    while(aux != NULL){
        if(aux->infos.NumdoComando == 1){
            for(i = 0; i < aux->infos.vezesExec; i++){
                Orientacoes2(&ot,'D'); //Orientção de Girar pra Direita
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
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
                Orientacoes2(&ot,'E');//Orientção de Girar pra Esquerda
                Orientacoes1(ot,MAT,&x,&y);//Orientção de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y);//Orientção de Andar para Frente
            }
            Att_Tab(MAT,h);
        }
        Comandos_F3();
        Dados_Player(ot,vida);
        printf("\nComando %d-%d Executado\n",aux->infos.NumdoComando,aux->infos.vezesExec);
        NOF* aux2 = aux;
        aux = aux->next;
        free(aux2);
        Imprimir_Fila(aux);
        system("pause");
        system("cls");
    }
    //F recebe Aux para resetar, ou seja, falar que lista ta vazia
    f->ini=aux;
    f->fim=aux;
    if(x == 7 && y == 7){
        return ot; // Vitoria da Fase
    }else{
        return 0; // Derrota da Fase
    }
}

//Movimentação da Parte 2 (Pilha)
int Move_Player_F3_P2(Pilha *pl,char** MAT, int vida,int ot){
    MAT[0][0] = 'O';
    MAT[7][7] = 'P';
    NOP *aux = *pl;
    int i,x=7,y=7,h=8;

    while(aux != NULL){
        if(aux->infos_f2.NumdoComando == 1){
            for(i = 0; i < aux->infos_f2.vezesExec; i++){
                Orientacoes2(&ot,'D'); //Orientção de Girar pra Direita
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos_f2.NumdoComando == 2){
            for(i = 0; i < aux->infos_f2.vezesExec; i++){
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y); //Orientção de Andar para Frente
            }
            Att_Tab(MAT,h);
        }else
        if(aux->infos_f2.NumdoComando == 3){
            for(i = 0; i < aux->infos_f2.vezesExec; i++){
                Orientacoes2(&ot,'E');//Orientção de Girar pra Esquerda
                Orientacoes1(ot,MAT,&x,&y);//Orientção de Andar para Frente
                Orientacoes1(ot,MAT,&x,&y);//Orientção de Andar para Frente
            }
            Att_Tab(MAT,h);
        }
        Comandos_F3();
        Dados_Player(ot,vida);// Mostrar a vida do Player
        printf("\nComando %d-%d Executado\n",aux->infos_f2.NumdoComando,aux->infos_f2.vezesExec);
        NOP* aux2 = aux;
        aux = aux->top;
        free(aux2);
        Imprimir_Pilha(aux);
        system("pause");
        system("cls");
    }
    *pl = NULL;
    if(x == 0 && y == 0){
        return 1; // Vitoria da Fase
    }else{
        return 0; // Derrota da Fase
    }
}




///-----------------------------------------------///
///Traps---///

void traps_fase3(char** TabMat){
    TabMat[0][1] = 'X';
    TabMat[0][7] = 'X';
    TabMat[1][1] = 'X';
    TabMat[1][2] = 'X';
    TabMat[1][5] = 'X';
    TabMat[1][7] = 'X';
    TabMat[2][2] = 'X';
    TabMat[2][5] = 'X';
    TabMat[3][0] = 'X';
    TabMat[3][4] = 'X';
    TabMat[3][5] = 'X';
    TabMat[3][6] = 'X';
    TabMat[4][0] = 'X';
    TabMat[4][2] = 'X';
    TabMat[4][3] = 'X';
    TabMat[4][4] = 'X';
    TabMat[5][2] = 'X';
    TabMat[5][6] = 'X';
    TabMat[6][1] = 'X';
    TabMat[6][2] = 'X';
    TabMat[6][4] = 'X';
    TabMat[6][6] = 'X';
    TabMat[7][4] = 'X';
}

///---Comandos_F3---///

void Comandos_F3(void){
    printf("\n\t\t\t\t-=-=-=-=-=-=-=-=-=-=- Comandos -=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t\t\t\t  1) [D,F,F]\t"); //Comando 1
    printf("\t2) [F,F]\t");     //Comando 2
    printf("3) [E,F,F]\t"); //Comando 3
}
#endif // CHAPTER3_H_INCLUDED
