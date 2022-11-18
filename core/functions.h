#include <stdio.h>

void preencherMatriz (char **m){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = ' ';
        }  
    }
}

void mostrarMatriz (char **m){
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d",i);
        for (int j = 0; j < 3; j++)
        {
            if (j <= 1)
            {
                printf(" %c | ", m[i][j]);
            }else{
                printf("%c", m[i][j]);
            }
        }
        if (i <= 1)
        {
            printf("\n--------------\n");
        }
    }
}

void pegarPonto (int *a, int *b){
    printf("\nDigite a linha:\n");
    scanf("%d", a);
    printf("Digite a coluna:\n");
    scanf("%d", b);
}

void mudarMatriz(int *a, int *b, char **m, int jogador){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i == *a && j == *b){
                if(jogador == 1){
                    m[i][j] = 'X';
                }else{
                     m[i][j] = 'O';
                }
            }
        }
        
    }
    
}

int verificarPonto (int *a, int *b, char **mat){
    int quantidadeDeTestes =2;
    if(*a <= 2 && *a >=0 && *b <= 2 && *b >=0){
        quantidadeDeTestes--;
        if(mat[*a][*b] == ' '){
            quantidadeDeTestes--;
        }
    }
    return quantidadeDeTestes;
}

int verificarVencedor(char **m){
    //linhas
    if(m[0][0] == 'X' && m[0][1] == 'X' && m[0][2] == 'X'){return 1;}
    if(m[1][0] == 'X' && m[1][1] == 'X' && m[1][2] == 'X'){return 1;}
    if(m[2][0] == 'X' && m[2][1] == 'X' && m[2][2] == 'X'){return 1;}

    if(m[0][0] == 'O' && m[0][1] == 'O' && m[0][2] == 'O'){return 2;}
    if(m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == 'O'){return 2;}
    if(m[2][0] == 'O' && m[2][1] == 'O' && m[2][2] == 'O'){return 2;}

//colunas

    if(m[0][0] == 'X' && m[1][0] == 'X' && m[2][0] == 'X'){return 1;}
    if(m[0][1] == 'X' && m[1][1] == 'X' && m[2][1] == 'X'){return 1;}
    if(m[0][2] == 'X' && m[1][2] == 'X' && m[2][2] == 'X'){return 1;}

    if(m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == 'O'){return 2;}
    if(m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == 'O'){return 2;}
    if(m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == 'O'){return 2;}

    //diagonais
    if(m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == 'X'){return 1;}
    if(m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == 'X'){return 1;}
    
    if(m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == 'O'){return 2;}
    if(m[0][2] == 'O' && m[1][1] == 'O' && m[2][0] == 'O'){return 2;}
    
    return 0;
}