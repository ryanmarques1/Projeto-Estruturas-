#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib_1.h"

int main()
{
    setlocale(LC_ALL,"");
    int op;
    do{
        menu();
        printf("Digite sua Opção: ");
        scanf("%d", &op);
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        switch(op){
        case 1:
            Impress_Tab();
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
