#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "lib_1.h"
#include "Chapter1.h"
#include "Chapter2.h"

int main()
{
    setlocale(LC_ALL,"");
    sFila *f =  NULL;
    infos L;
    int op, dimensao = 8, healthPoints = 3;
    char **TabMat;
    f = alloc_fila();
    if(f == NULL){ //se for null, erro ao alocar, senão inicia fila.
        printf("\nErro de alocação\n");
        exit(1);
    }else
        ini_fila(f);
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
            /*printf("Digite o numero referente a lista de comandos e as vezes que será executado: ");
            scanf("%d %d", &L.NumdoComando, &L.vezesExec);
            insere_listaComandos(f,L);*/
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
