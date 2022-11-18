/**
 * @file main.c
 * @author Pedro Neves (github.com/pdr-tuche)
 * @brief 
 * @version 0.1
 * @date 2022-11-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "functions.h"

int main(){

    char matriz [3][3];
    int vez = 1;
    
    preencherMatriz(matriz);
    

    char flag;
    int vzsJogadas = 0, linha, coluna;
    do{
        vzsJogadas =1;
        do{
            mostrarMatriz(matriz);
            printf("Digite a linha:\n");
            scanf("%d", linha);
            printf("Digite a coluna:\n");
            scanf("%d", coluna);
            verificaInvalidez(linha,coluna,&matriz);
            
        }while (vzsJogadas <=9);
                
        printf("deseja jogar novamente? [s][n]\n");
        scanf("%c", &flag);
    }while(flag = 's');
    //pegarCoordenadas(vez, &matriz);
    
    
    

    return 0;
}