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
        int goBackFlag=0;
        struct jogador p1;
        struct jogador p2;
        int res;

        printf("digite o nome do jogador 1: ");
        scanf("%s", &p1.nome);
        p1.id = 1;

        printf("digite o nome do jogador 2: ");
        scanf("%s", &p2.nome);
        p2.id =2;

        res = tictactoe(); 
        if (res == p1.id){
            printf("Parabens %s !!!\n", p1.nome);
            gravarNomeVencedor(p1.nome);
        }else if(res == p2.id){
            printf("Parabens %s !!!\n", p2.nome);
            gravarNomeVencedor(p2.nome);
        }else{
            printf("\nDEU VELHA !");
        }
        
        printf("digite 1 para voltar ao menu\n");
        scanf("%d", &goBackFlag);
        goBack(goBackFlag);
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
        printf("See ya! ^^");
        break;
    }

    return 0;
}