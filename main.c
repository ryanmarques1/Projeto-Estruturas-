#include <stdio.h>
#include <stdlib.h>
#include "lib_1.h"

int main()
{
    int n;
    do{
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("=-=-=-=-=-=    Jogo    -=-=-=-=-=-=\n");
        printf("=-=-=    Comandos Em Loop    -=-=-=\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        printf("Menu de Opcoes\n");
        printf("1 - Iniciar Jogo\n");
        printf("2 - Informações\n");
        printf("3 - \n");
        printf("4 - Sair\n\n");

        printf("Digite sua Opcao: ");
        scanf("%d", &n);
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

        switch(n){
        case 1:
            Tabuleiro();
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        default:
            printf("Opcao invalida!\n\n");
            break;
        }

    }while(n != 4);
    return 0;
}
//
