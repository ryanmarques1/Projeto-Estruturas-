#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "lib_1.h"

int main()
{
    setlocale(LC_ALL,"");


    int n,op, dimensao = 8, vida=3;
    char **MAT;

//    sFila *f =  NULL;
//    f = alloc_fila();
//    if(f == NULL){ //se for null, erro ao alocar, senão inicia fila.
//        printf("\nErro de alocação\n");
//        exit(1);
//    }else
//        ini_fila(f);

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
                MAT = Create_Tabuleiro(dimensao);
                traps_fase1(MAT);
                Impress_Tabuleiro(MAT,dimensao);
                n = Move_Player();
                if(n == 0){
                    vida--;
                }else{
                    break;
                }

            }

            /// Fase 2

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
