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
#include <unistd.h>
#include "functions.h"

int main(){

    switch (menu())
    {
    case 0:
        printf("See ya! ^^");
        break;
    case 1:
        system("cls");
        int single= setSinglePlayer();
        if(single == 1){
            initTicTacToeSinglePlayer();
        }else if(single == 2){
            initTicTacToe();
        }
        break;
    case 2:
        system("cls");
        verVencedores();
        break;
    case 3:
        system("cls");
        credits();
        break;
    default:
        printf("opcao invalida, digite novamente em alguns segundos\n");
        sleep(2);
        main();
    }
    return 0;
}