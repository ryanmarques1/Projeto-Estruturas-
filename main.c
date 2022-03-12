#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "lib_1.h"


int main()
{
    setlocale(LC_ALL,"");
    infos info;
    infos_f2 info_f2;
    char **MAT;
    int n,op, dimensao = 8, vida=3;
    ///Inicio
    do{
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
                Impress_Tabuleiro(MAT,dimensao);
                Dados_Player_F1(1,vida);
                while(1){
                    printf("Qual comando:");
                    scanf("%d",&info.NumdoComando);
                    printf("Quantidade de vezes:");
                    scanf("%d",&info.vezesExec);
                    if(info.NumdoComando == 0 && info.vezesExec == 0){
                        break;
                    }
                    insere_listaComandos_F1(f,info);
                }
                n = Move_Player_F1(f,MAT,vida);
                if(n == 0){
                    printf("\n----------------------=Perdeu Vida Mané=-----------------------------\n");
                    vida--;
                    if(vida == 0)
                        printf("\n----------------------=GAME OVER=-----------------------------\n");
                }else{
                    printf("\n----------------------=Fase 1 Concluida=-----------------------------\n\n");
                    destroi_fila(f);
                    break;
                }

                /*printf("\n");
                /// Fase 2
                printf("\n--------------------------=Fase 2=-----------------------------\n\n");
                Pilha *pl = NULL;
                pl = alloc_pilha();
                if(pl == NULL){
                    printf("\nErro de alocação\n");
                    exit(1);
                }else
                    ini_pilha(pl);
                MAT = Create_Tabuleiro(dimensao);
                traps_fase2(MAT);
                Impress_Tabuleiro(MAT,dimensao);
                while(1){
                    printf("Qual comando:");
                    scanf("%d",&info_f2.NumdoComando);
                    printf("Quantidade de vezes:");
                    scanf("%d",&info_f2.vezesExec);
                    if(info_f2.NumdoComando == 0 && info_f2.vezesExec == 0){
                        break;
                    }
                    insere_listaComandos_F2(pl,info_f2);
                }*/
            }
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
