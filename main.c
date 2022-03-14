#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib_1.h"
int main()
{
    setlocale(LC_ALL,"");
    infos info_f1; //Referente as infos fila.
    infos_f2 info_f2; //Referentes as infos pilha.
    char **MAT; //Matriz referente ao Tabuleiro.
    int n,op, dimensao = 8;
    ///Inicio
    do{
        int vida = 3;
        menu();
        printf("Digite sua Opção: ");
        scanf("%d", &op);
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        switch(op){
        case 1:
            /// Fase 1
            while(vida != 0){
                printf("\n--------------------------=Fase 1=-----------------------------\n\n");
                sFila *f =  NULL;
                f = alloc_fila();
                if(f == NULL){ //se for null, erro ao alocar, senão inicia fila.
                    printf("\nErro de alocação\n");
                    exit(1);
                }else
                    ini_fila(f);
                ///=- So cria a fila no case 1-=///
                MAT = Create_Tabuleiro(dimensao);
                traps_fase1(MAT);
                Att_Tab(MAT,dimensao);
                Comandos_F1();
                Dados_Player(1,vida);
                printf("Digite | 0 0 | para finalizar!\n");
                while(1){
                    printf("Digite o número referente a seção de comandos listado acima(Ex: 1 [F,D,F]): ");
                    scanf("%d",&info_f1.NumdoComando);
                    printf("\n");
                    printf("Quantidade de vezes que o comando repetirá: ");
                    scanf("%d",&info_f1.vezesExec);
                    printf("\n_____________________________________________________________________________\n");
                    if(info_f1.NumdoComando > 4 || (info_f1.NumdoComando <= 0 && info_f1.vezesExec != 0)){
                        printf("Comando digitado é inválido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f1.NumdoComando == 0 && info_f1.vezesExec == 0){
                        break;
                    }
                    insere_listaComandos_F1(f,info_f1);
                }
                n = Move_Player_F1(f,MAT,vida);
                if(n == 0){
                    printf("\n----------------------=Uma vida a menos =( (Você não tem 7 vidas...)=-----------------------------\n");
                    vida--;
                    if(vida == 0){
                        printf("\n----------------------=GAME OVER=-----------------------------\n");
                        break;
                    }
                }else{
                    printf("\n----------------------=FASE 1 Concluída=-----------------------------\n\n");
                    destroi_fila(f);
                    break;
                }
                printf("\n");
            }

/// Fase 2 ------------------------------------------------------------------------------------------------------------
            while(vida != 0){
                printf("\n--------------------------=Fase 2=-----------------------------\n\n");
                Pilha *pl = NULL;
                pl = alloc_pilha();

                if(pl == NULL){
                    printf("\nErro de alocação\n");
                    exit(1);
                }else{
                    ini_pilha(pl);
                }
                MAT = Create_Tabuleiro(dimensao);
                traps_fase2(MAT);
                Att_Tab(MAT,dimensao);
                Comandos_F2();
                Dados_Player(4,vida);
                printf("Digite 0 0 para finalizar!\n");
                while(1){
                    printf("Digite o número referente a seção de comandos listado acima(Ex: 2 [F,F]):");
                    scanf("%d",&info_f2.NumdoComando);
                    printf("\n");
                    printf("Quantidade de vezes que o comando repetirá: ");
                    scanf("%d",&info_f2.vezesExec);
                    printf("\n_____________________________________________________________________________\n");
                    if(info_f2.NumdoComando > 3 || (info_f2.NumdoComando <= 0 && info_f2.vezesExec != 0)){
                        printf("Comando digitado é inválido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f2.NumdoComando == 0 && info_f2.vezesExec == 0){
                        break;
                    }
                    insere_listaComandos_F2(pl,info_f2);
                }
                n = Move_Player_F2(pl,MAT,vida);
                if(n == 0){
                    printf("\n----------------------=Uma vida a menos =( (Você não tem 7 vidas...)=-----------------------------\n");
                    vida--;
                    if(vida == 0){
                        printf("\n----------------------=GAME OVER=-----------------------------\n");
                        break;
                    }
                }else{
                    printf("\n----------------------=FASE 2 Concluida=-----------------------------\n\n");
                    destroi_pilha(pl);
                    break;
                }
                printf("\n");
            }

/// Fase 3 ------------------------------------------------------------------------------------------------------------
            while(vida != 0){
                printf("\n--------------------------=Fase 3=-----------------------------\n\n");

                //Fila ----------
                sFila *f =  NULL;
                f = alloc_fila();
                //Pilha ---------
                Pilha *pl = NULL;
                pl = alloc_pilha();

                if(f == NULL || pl == NULL){ //se for null, erro ao alocar, senão inicia fila.
                    printf("\nErro de alocação\n");
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
                printf("Digite 0 0 para finalizar!\n");

                while(1){
                    /// Parte 1 - Fila
                    printf("Digite o NÚMERO referente a seção de comandos listado acima(Ex: 1 [F,D,F]): ");
                    scanf("%d",&info_f1.NumdoComando);
                    printf("\n");
                    printf("Quantidade de vezes que o comando repetirá: ");
                    scanf("%d",&info_f1.vezesExec);
                    printf("\n_____________________________________________________________________________\n");
                    if(info_f1.NumdoComando > 3 || (info_f1.NumdoComando <= 0 && info_f1.vezesExec != 0)){
                        printf("Comando digitado é inválido. Digite novamente!\n");
                        continue;
                    }
                    if(info_f1.NumdoComando == 0 && info_f1.vezesExec == 0){
                        break;
                    }
                    insere_listaComandos_F1(f,info_f1);
                }
                n = Move_Player_F3_P1(f,MAT,vida);
                if(n == 0){
                    printf("\n----------------------=Uma vida a menos =( (Você não tem 7 vidas...)=-----------------------------\n");
                    vida--;
                    if(vida == 0){
                        printf("\n----------------------=GAME OVER=-----------------------------\n");
                        break;
                    }
                }else{
                    printf("\n----------------------=FASE 3 Parte 1 Concluida=-----------------------------\n\n");
                    destroi_fila(f);
                }
                printf("\n");

                ///Fase 3 - Parte 2 (Pilha)
                int ot = n;
                while(vida != 0){
                    printf("\n--------------------------=Fase 3 Parte 2=-----------------------------\n");
                    printf("------=Seu Objetivo agora é voltar ao Inicio, Ponto 'O' na Tabela!=-----\n\n");
                    Pilha *pl = NULL;
                    pl = alloc_pilha();

                    if(pl == NULL){
                        printf("\nErro de alocação\n");
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
                    printf("Digite 0 0 para finalizar!\n");
                    while(1){
                        printf("Digite o número referente a seção de comandos listado acima(Ex: 2 [F,F]):");
                        scanf("%d",&info_f2.NumdoComando);
                        printf("\n");
                        printf("Quantidade de vezes que o comando repetirá: ");
                        scanf("%d",&info_f2.vezesExec);
                        printf("\n_____________________________________________________________________________\n");
                        if(info_f2.NumdoComando > 3 || (info_f2.NumdoComando <= 0 && info_f2.vezesExec != 0)){
                            printf("Comando digitado é inválido. Digite novamente!\n");
                            continue;
                        }
                        if(info_f2.NumdoComando == 0 && info_f2.vezesExec == 0){
                            break;
                        }
                        insere_listaComandos_F2(pl,info_f2);
                    }
                    n = Move_Player_F3_P2(pl,MAT,vida, ot);
                    if(n == 0){
                        printf("\n----------------------=Uma vida a menos =( (Você não tem 7 vidas...)=-----------------------------\n");
                        vida--;
                        if(vida == 0){
                            printf("\n----------------------=GAME OVER=-----------------------------\n");
                            break;
                        }
                    }else{
                        printf("\n----------------------=FASE 3 Parte 2 Concluida=-----------------------------\n\n");
                        destroi_pilha(pl);
                        break;
                    }
                    printf("\n");
                }
                break;
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
            break;
        default:
            printf("Opção invalida!\n\n");
            break;
        }
    }while(op != 5);
    return 0;
}
//
