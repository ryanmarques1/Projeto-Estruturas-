#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "lib_1.h"


int main()
{
    setlocale(LC_ALL,"");
    infos info_f1;
    infos_f2 info_f2;
    char **MAT;
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
                printf("Digite 0 0 para finalizar!\n");
                while(1){
                    printf("Digite o número referente a seção de comandos listado acima(Ex: 1 [F,D,F]): ");
                    scanf("%d",&info_f1.NumdoComando);
                    printf("\n");
                    printf("Quantidade de vezes que o comando repetiá: ");
                    scanf("%d",&info_f1.vezesExec);
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
                }
                printf("\n");
            }

/// Fase 3 ------------------------------------------------------------------------------------------------------------
            /*while(vida != 0){
                printf("\n--------------------------=Fase 3=-----------------------------\n\n");

            }*/
            break;
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
            printf("Opcao invalida!\n\n");
            break;
        }
    }while(op != 5);
    return 0;
}
//
