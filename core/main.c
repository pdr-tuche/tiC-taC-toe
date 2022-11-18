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
#include <stdlib.h>
#include "functions.h"

int main(){

    char **matriz;
    int vezJogador = 1;
    int flagDeErros;
    int vencedor =0;
    int vzsJogadas = 0;
    int linha, coluna;
    int *row, *col;

    matriz = malloc(3 * sizeof(char*));
    for (int i = 0; i < 3; i++)
    {
        matriz[i] = malloc(3 * sizeof(char));
    }
    
    preencherMatriz(matriz);
    mostrarMatriz(matriz);

    row = &linha;
    col = &coluna;

    do{
        printf("\nvez do jogador %d\n", vezJogador);
        do{
            pegarPonto(row, col);
            
            flagDeErros = verificarPonto(row, col, matriz);
            if(flagDeErros > 0){
                printf("coordenada invalida, digite novamente \n");
            }
        }while(flagDeErros != 0);

        mudarMatriz(row, col, matriz, vezJogador);
        system("cls");
        mostrarMatriz(matriz);
        if(vezJogador == 1){
            vezJogador = 2;
        }else{
            vezJogador = 1;
        }

        vencedor = verificarVencedor(matriz);
        if(vencedor != 0){
            printf("\n O JOGADOR %d E O VENCEDOR !!! \n", vencedor);
            break;
        }
        
        vzsJogadas++;
        if(vzsJogadas >= 9){
            printf("DEU VELHA !");
        }
    }while (vzsJogadas < 9);

    return 0;
}