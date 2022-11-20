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
        tictactoe();
        break;
    
    default:
        printf("caiu no default");
        break;
    }

    return 0;
}