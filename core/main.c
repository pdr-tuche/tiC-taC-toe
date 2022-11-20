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

    switch (menu())
    {
    case 1:
        system("cls");
        tictactoe();
        break;

    case 2:
        printf("aqui eu exibo o arquivo com os nomes de jogadores e quantas vezes ganharam");
        break;
    case 3:
        system("cls");
        credits();
        break;
    default:
        printf("See ya! ^^");
        break;
    }

    return 0;
}