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

void mudarMatriz(int *a, int *b, char **m){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i == *a && j == *b){
                m[i][j] = 'X';
            }
        }
        
    }
    
}
int verificarPonto (int *a, int *b, char **mat){
    int passouTeste =0;
    if(*a <= 2 && *a >=0 && *b <= 2 && *b >=0){
        passouTeste++;
        if(mat[*a][*b] == ' '){
            passouTeste++;
        }
    }
    return passouTeste;
}