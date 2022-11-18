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
    char **mat;
    int vezJogador = 1;
    int flag;
    int vzsJogadas = 0;
    int linha, coluna;
    int *row, *col;

    mat = malloc(3 * sizeof(char*));
    for (int i = 0; i < 3; i++)
    {
        mat[i] = malloc(3 * sizeof(char));
    }
    
    preencherMatriz(mat);
    mostrarMatriz(mat);

    row = &linha;
    col = &coluna;

    do{
        pegarPonto(row, col);
        
        flag = verificarPonto(row, col, mat);
        if(flag < 2){
            printf("coordenada invalida, digite novamente \n");
        }
    }while(flag < 2);

    mudarMatriz(row, col, mat);
    mostrarMatriz(mat);
    
    
    
    

    return 0;
}