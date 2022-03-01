#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "lib_1.h"
#include "Chapter1.h"

int main()
{
    setlocale(LC_ALL,"");
    int op, dimensao = 8, healthPoints = 3;
    char **TabMat;
    do{
        menu();
        printf("Digite sua Opção: ");
        scanf("%d", &op);
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        switch(op){
        case 1:
            TabMat = Create_Tabuleiro(dimensao);
            traps_fase1(TabMat);
            Impress_Tabuleiro(TabMat,dimensao);
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
