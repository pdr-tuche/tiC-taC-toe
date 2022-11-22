#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct jogador
{
    int id;
    char nome [20];
}s_player;

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

int tictactoe(){
    int goBackFlag = 0;

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
    }while (vzsJogadas < 9);

    return vencedor;
}

int menu(){
    int option = 0;
    system("cls");
    printf("_______________________________________________________________________________________\n");
    printf("|                                                                                     |\n");
    printf("|  sssssssss d   sSSs.      sss sssss d s.     sSSs.      sss sssss   sSSSs   d sss   |\n");
    printf("|      S     S  S               S     S  ~O   S               S      S     S  S       |\n");
    printf("|      S     S S                S     S   `b S                S     S       S S       |\n");
    printf("|      S     S S                S     S sSSO S                S     S       S S sSSs  |\n");
    printf("|      S     S S                S     S    O S                S     S       S S       |\n");
    printf("|      S     S  S               S     S    O  S               S      S     S  S       |\n");
    printf("|      P     P   sss            P     P    P   sss            P        sss    P sSSss |\n");
    printf("_______________________________________________________________________________________\n");
    printf("|                                                                                     |\n");
    printf("|               1 - play    2 - Ranking    3 - See Credits    0 - Exit                |\n");
    printf("|_____________________________________________________________________________________|\n");
    printf("option: ");
    scanf("%d", &option);
    return option;
}

void credits(){
    int goBackFlag=0;
    printf("____________________________________________________\n");
    printf("|                                                   |\n");
    printf("|               Developed by Tucha.                 |\n");
    printf("|                  follow me on:                    |\n");
    printf("|               GitHub: @pdr-tuche                  |\n");
    printf("|               twitter: @pdrtuche                  |\n");
    printf("|________________________________________1 - menu___|\n");
    scanf("%d", &goBackFlag);
    goBack(goBackFlag);   
}

void goBack(int flag){
    if(flag == 1)
        main();
    while(flag != 1){
        printf("digite 1 para ir ao menu\n");
        scanf("%d", &flag);
        if (flag == 1)
        {
            main();
        }
    }
}

void gravarNomeVencedor(char vencedor[20]){
    FILE *f;
    f = fopen("vencedores.txt", "a+");
    if (f == NULL) {
        printf("erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }

    int res = fputs(vencedor, f);
    fputc('\n', f);
    if (res == EOF)
        printf("erro na gravaçao\n");

    fclose(f);
}

void verVencedores(){
    int goBackFlag =0;
    FILE *arq;
    arq = fopen("vencedores.txt", "r");
    if (arq == NULL) {
        printf("erro na abertura\n");
        system("pause");
        exit(1);
    }

    printf("ULTIMOS VENCEDORES:\n");
    char c = fgetc(arq);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(arq);
    }
    fclose(arq);

    printf("digite 1 para voltar ao menu\n");
    scanf("%d", &goBackFlag);
    goBack(goBackFlag);
}

void initTicTacToe(){
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
}

int setSinglePlayer(){
    int opcao;
    printf("1 - Um jogador\n2 - Dois jogadores\nopcao: ");
    scanf("%d", &opcao);
    if(opcao == 1 || opcao == 2){
        return opcao;
    }else{
        system("cls");
        printf("valor invalido, digite novamente a opçao\n");
        setSinglePlayer();
    }
}

int coordenadaAleatoria(){   
  srand(time(NULL));
  return rand() % 3;
}

void initTicTacToeSinglePlayer(){
    int goBackFlag = 0;

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
            if(vezJogador == 2){
                linha = coordenadaAleatoria();
                coluna = coordenadaAleatoria();    
                flagDeErros = verificarPonto(row, col, matriz);
            }else{
                pegarPonto(row, col);
            
                flagDeErros = verificarPonto(row, col, matriz);
                if(flagDeErros > 0){
                    printf("coordenada invalida, digite novamente \n");
                }
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
    }while (vzsJogadas < 9);

    printf("digite 1 para voltar ao menu: ");
    scanf("%d", &goBackFlag);
    goBack(goBackFlag);
}
