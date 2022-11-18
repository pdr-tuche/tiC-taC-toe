#include <stdio.h>

void preencherMatriz (char m [][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = ' ';
        }  
    }
}

void mostrarMatriz (char m [][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j <= 1)
            {
                printf("%c | ", m[i][j]);
            }else{
                printf("%c", m[i][j]);
            }
        }
        if (i <= 1)
        {
            printf("\n---------\n");
        }
    }
}

int verificaInvalidez(int linha,int coluna, *matriz);

