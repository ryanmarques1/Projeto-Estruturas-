#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib_1.h"
/*
======================================================================|
#Equipe: 1 - Ryan Marques; 2 - Bernardo Miranda; 3 - Mariana Castro   |
#Projeto de Algoritmos e Estrutura de Dados - Jogo Comandos em Loop   |
#Uso Obrigatorio de Fila e Pilha em determiandas fases                |
======================================================================|

*/
int main()
{
    setlocale(LC_ALL,"");
    infos info_f1; //Referente as infos fila.
    infos_f2 info_f2; //Referentes as infos pilha.
    char **MAT; //Matriz referente ao Tabuleiro.
    int n,op, dimensao = 8;
    ///Inicio
    do{
        int vida;
        menu();
        printf("Digite sua Op??o: ");
        scanf("%d", &op);
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        switch(op){
        case 1:
/// Fase 1 ---------------------------------------------------------------------------------------------------------------------------
            system("cls");
            vida = 3;
            while(vida != 0){
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=   FASE 1   =-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=   Chegue ao Objetivo (O)   =-=-=-=-=-=-=-=-=-=-\n\n");
                sFila *f =  NULL;
                f = alloc_fila();
                if(f == NULL){ //se for null, erro ao alocar, sen?o inicia fila.
                    printf("\nErro de aloca??o\n");
                    exit(1);
                }else
                    ini_fila(f);
                ///=- So cria a fila no case 1-=///
                MAT = Create_Tabuleiro(dimensao);
                traps_fase1(MAT);
                Att_Tab(MAT,dimensao);
                Comandos_F1();
                Dados_Player(1,vida);
                printf("\t\t\t\t\t   Digite | 0 0 | para finalizar!\n\n");
                while(1){
                    printf("Digite o n?mero referente a se??o de comandos listado acima(Ex, 1) [F,D,F]): ");
                    scanf("%d",&info_f1.NumdoComando);
                    printf("Quantidade de vezes que o comando repetir?: ");
                    scanf("%d",&info_f1.vezesExec);
                    printf("\n");
                    if(info_f1.NumdoComando > 4 || (info_f1.NumdoComando <= 0 && info_f1.vezesExec != 0)){
                        printf("Comando digitado ? inv?lido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f1.NumdoComando == 0 && info_f1.vezesExec == 0){
                        system("cls");
                        break;
                    }
                    insere_listaComandos_F1(f,info_f1);
                }
                n = Move_Player_F1(f,MAT,vida);
                if(n == 0){
                    printf("\n\t\t===----------------------> Voce perdeu 1 vida. N?o Chegue a 0 <----------------------===\n");
                    vida--;
                    if(vida == 0){
                        printf("\n\t\t\t##########################################################################\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t####               #####           ####       ##       ##             ####\n"
                               "\t\t\t####   ###############     #####     ##   #        #   ##   ##############\n"
                               "\t\t\t####   ###          ##               ##   ####  ####   ##             ####\n"
                               "\t\t\t####   ##########   ##   #########   ##   ##########   ##   ##############\n"
                               "\t\t\t####                ##   #########   ##   ##########   ##             ####\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t####                ##   #########   ##              ##               ####\n"
                               "\t\t\t####   ##########   ##   #########   ##   #############   #########   ####\n"
                               "\t\t\t####   ##########   ##     #####     ##              ##               ####\n"
                               "\t\t\t####   ##########   ####     #     ####   #############   #   ############\n"
                               "\t\t\t####                ######       ######              ##   #           ####\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t##########################################################################\n");

                        system("pause");
                        system("cls");
                        break;
                    }
                }else{
                    printf("\n\t\t\t\t|==================================================|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| -->     PARAB?NS     <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| --> FASE 1 CONCLU?DA <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|==================================================|\n");
                    printf("\n\t\t\t\t\t     --> COME?ANDO A FASE 2 <--\n\n");
                    system("pause");
                    system("cls");
                    vida = 3;
                    destroi_fila(f);
                    break;
                }
                printf("\n");
            }

/// Fase 2 ------------------------------------------------------------------------------------------------------------
            while(vida != 0){
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=   FASE 2   =-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=   Chegue ao Objetivo (O)   =-=-=-=-=-=-=-=-=-=-\n\n");
                Pilha *pl = NULL;
                pl = alloc_pilha();

                if(pl == NULL){
                    printf("\nErro de aloca??o\n");
                    exit(1);
                }else{
                    ini_pilha(pl);
                }
                MAT = Create_Tabuleiro(dimensao);
                traps_fase2(MAT);
                Att_Tab(MAT,dimensao);
                Comandos_F2();
                Dados_Player(4,vida);
                printf("\t\t   Digite | 0 0 | para finalizar! Obs: Escreva do ultimo comando ao primeiro\n\n");
                while(1){
                    printf("Digite o n?mero referente a se??o de comandos listado acima(Ex, 2) [F,F]):");
                    scanf("%d",&info_f2.NumdoComando);
                    printf("Quantidade de vezes que o comando repetir?: ");
                    scanf("%d",&info_f2.vezesExec);
                    printf("\n");
                    if(info_f2.NumdoComando > 3 || (info_f2.NumdoComando <= 0 && info_f2.vezesExec != 0)){
                        printf("Comando digitado ? inv?lido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f2.NumdoComando == 0 && info_f2.vezesExec == 0){
                        system("cls");
                        break;
                    }
                    insere_listaComandos_F2(pl,info_f2);
                }
                n = Move_Player_F2(pl,MAT,vida);
                if(n == 0){
                    printf("\n\t\t===----------------------> Voce perdeu 1 vida. N?o Chegue a 0 <----------------------===");
                    vida--;
                    if(vida == 0){
                        printf("\n\t\t\t##########################################################################\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t####               #####           ####       ##       ##             ####\n"
                               "\t\t\t####   ###############     #####     ##   #        #   ##   ##############\n"
                               "\t\t\t####   ###          ##               ##   ####  ####   ##             ####\n"
                               "\t\t\t####   ##########   ##   #########   ##   ##########   ##   ##############\n"
                               "\t\t\t####                ##   #########   ##   ##########   ##             ####\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t####                ##   #########   ##              ##               ####\n"
                               "\t\t\t####   ##########   ##   #########   ##   #############   #########   ####\n"
                               "\t\t\t####   ##########   ##     #####     ##              ##               ####\n"
                               "\t\t\t####   ##########   ####     #     ####   #############   #   ############\n"
                               "\t\t\t####                ######       ######              ##   #           ####\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t##########################################################################\n");

                        system("pause");
                        system("cls");
                        break;
                    }
                }else{
                    printf("\n\t\t\t\t|==================================================|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| -->     PARAB?NS     <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| --> FASE 2 CONCLU?DA <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|==================================================|\n");
                    printf("\n\t\t\t\t\t     --> COME?ANDO A FASE 3 <--\n\n");
                    system("pause");
                    system("cls");
                    vida = 3;
                    destroi_pilha(pl);
                    break;
                }
                printf("\n");
            }

/// Fase 3 ---------------------------------------------------------------------------------------------------------------------------
            while(vida != 0){
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=-=   FASE 3 - Parte 1   =-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=   Chegue ao Objetivo (O)   =-=-=-=-=-=-=-=-=-=-\n\n");

                //Fila ----------
                sFila *f =  NULL;
                f = alloc_fila();
                //Pilha ---------
                Pilha *pl = NULL;
                pl = alloc_pilha();

                if(f == NULL || pl == NULL){ //se for null, erro ao alocar, sen?o inicia fila.
                    printf("\nErro de aloca??o\n");
                    exit(1);
                }else{
                    ini_fila(f);
                    ini_pilha(pl);
                }

                MAT = Create_Tabuleiro(dimensao);
                traps_fase3(MAT);
                Att_Tab(MAT,dimensao);
                Comandos_F3();
                Dados_Player(4,vida);
                printf("\t\t\t\t\t   Digite | 0 0 | para finalizar!\n\n");

                while(1){
                    /// Parte 1 - Fila
                    printf("Digite o N?MERO referente a se??o de comandos listado acima(Ex, 1) [F,D,F]): ");
                    scanf("%d",&info_f1.NumdoComando);
                    printf("Quantidade de vezes que o comando repetir?: ");
                    scanf("%d",&info_f1.vezesExec);
                    printf("\n");
                    if(info_f1.NumdoComando > 3 || (info_f1.NumdoComando <= 0 && info_f1.vezesExec != 0)){
                        printf("Comando digitado ? inv?lido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f1.NumdoComando == 0 && info_f1.vezesExec == 0){
                        system("cls");
                        break;
                    }
                    insere_listaComandos_F1(f,info_f1);
                }
                n = Move_Player_F3_P1(f,MAT,vida);
                if(n == 0){
                    printf("\n\t\t===----------------------> Voce perdeu 1 vida. N?o Chegue a 0 <----------------------===");
                    vida--;
                    if(vida == 0){
                        printf("\n\t\t\t##########################################################################\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t####               #####           ####       ##       ##             ####\n"
                               "\t\t\t####   ###############     #####     ##   #        #   ##   ##############\n"
                               "\t\t\t####   ###          ##               ##   ####  ####   ##             ####\n"
                               "\t\t\t####   ##########   ##   #########   ##   ##########   ##   ##############\n"
                               "\t\t\t####                ##   #########   ##   ##########   ##             ####\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t####                ##   #########   ##              ##               ####\n"
                               "\t\t\t####   ##########   ##   #########   ##   #############   #########   ####\n"
                               "\t\t\t####   ##########   ##     #####     ##              ##               ####\n"
                               "\t\t\t####   ##########   ####     #     ####   #############   #   ############\n"
                               "\t\t\t####                ######       ######              ##   #           ####\n"
                               "\t\t\t##########################################################################\n"
                               "\t\t\t##########################################################################\n");

                        system("pause");
                        system("cls");
                        break;
                    }
                }else{
                    printf("\t\t\t-=-=-=-=-=-=-=-=   FASE 3 - Parte 1 Conclu?da   =-=-=-=-=-=-=-=-=-=-\n");
                    destroi_fila(f);
                    break;
                }
                printf("\n");
            }
                ///Fase 3 - Parte 2 (Pilha)
            int ot = n;
            while(vida != 0){
                printf("\t\t\t-=-=-=-=-=-=-=-=-=-=-=   FASE 3 - Parte 2   =-=-=-=-=-=-=-=-=-=-=-=-\n");
                printf("\t\t\t-=-=-=-=-=-=-=-=   Chegue ao In?cio, Objetivo (O)   =-=-=-=-=-=-=-=-\n\n");
                Pilha *pl = NULL;
                pl = alloc_pilha();

                if(pl == NULL){
                    printf("\nErro de aloca??o\n");
                    exit(1);
                }else{
                    ini_pilha(pl);
                }
                MAT = Create_Tabuleiro(dimensao);
                traps_fase3(MAT);
                MAT[0][0] = 'O';
                MAT[7][7] = 'P';
                Att_Tab(MAT,dimensao);
                Comandos_F3();
                Dados_Player(ot,vida);
                printf("\t\t   Digite | 0 0 | para finalizar! Obs: Escreva do ultimo comando ao primeiro\n\n");
                while(1){
                    printf("Digite o n?mero referente a se??o de comandos listado acima(Ex, 2)[F,F]):");
                    scanf("%d",&info_f2.NumdoComando);
                    printf("Quantidade de vezes que o comando repetir?: ");
                    scanf("%d",&info_f2.vezesExec);
                    printf("\n");
                    if(info_f2.NumdoComando > 3 || (info_f2.NumdoComando <= 0 && info_f2.vezesExec != 0)){
                        printf("Comando digitado ? inv?lido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f2.NumdoComando == 0 && info_f2.vezesExec == 0){
                        system("cls");
                        break;
                    }
                    insere_listaComandos_F2(pl,info_f2);
                }
                n = Move_Player_F3_P2(pl,MAT,vida, ot);
                if(n == 0){
                    printf("\n\t\t===----------------------> Voce perdeu 1 vida. N?o Chegue a 0 <----------------------===");
                    vida--;
                    if(vida == 0){
                        printf("\n\t\t\t##########################################################################\n"
                           "\t\t\t##########################################################################\n"
                           "\t\t\t####               #####           ####       ##       ##             ####\n"
                           "\t\t\t####   ###############     #####     ##   #        #   ##   ##############\n"
                           "\t\t\t####   ###          ##               ##   ####  ####   ##             ####\n"
                           "\t\t\t####   ##########   ##   #########   ##   ##########   ##   ##############\n"
                           "\t\t\t####                ##   #########   ##   ##########   ##             ####\n"
                           "\t\t\t##########################################################################\n"
                           "\t\t\t####                ##   #########   ##              ##               ####\n"
                           "\t\t\t####   ##########   ##   #########   ##   #############   #########   ####\n"
                           "\t\t\t####   ##########   ##     #####     ##              ##               ####\n"
                           "\t\t\t####   ##########   ####     #     ####   #############   #   ############\n"
                           "\t\t\t####                ######       ######              ##   #           ####\n"
                           "\t\t\t##########################################################################\n"
                           "\t\t\t##########################################################################\n");

                    system("pause");
                    system("cls");
                        break;
                    }
                }else{
                    printf("\n\t\t\t\t|==================================================|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| -->     PARAB?NS     <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| -->    FIM DE JOGO   <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|-X-|-X-|-X-| -->    VOC? VENCEU   <-- |-X-|-X-|-X-|\n");
                    printf("\t\t\t\t|==================================================|\n\n");
                    system("pause");
                    system("cls");
                    destroi_pilha(pl);
                    break;
                }
                printf("\n");
            }
            break; //Break Case 1
        case 2:
            Instrucoes();
            break;
        case 3:
            Credits();
            break;
        case 4:
            Exit();
            op=0;
            break;
        default:
            printf("Op??o invalida!\n\n");
            break;
        }
    }while(op != 4);
    return 0;
}
//

