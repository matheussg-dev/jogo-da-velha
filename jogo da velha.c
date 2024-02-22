#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define linhaQuantidade 3
#define colunaQuantidade 3


char posicaoJogo[linhaQuantidade][colunaQuantidade];

//protopitagem de metodo
void letreiro();
void entradaMatriz(int push, char elemento);
void escolhaIniciar();
int validar(char jogada);

int main() {
    
    escolhaIniciar();
    letreiro();
    
}

    
void escolhaIniciar() {
    
    int resposta;
    
    printf("\tOla bem vindo a jogo da velha v0.4.1 .\n");
    printf("\tFeito em linguagem C\n\n");
    printf("\t - | - | - \n");
    printf("\t-----------\n");
    printf("\t - | - | - \n");
    printf("\t-----------\n");
    printf("\t - | - | - \n\n");
    
    
    printf("\tescolha uma das opcoes para proseguir.\n");
    printf("\nIniciar: 1\n");
    printf("Sair: 2\n");
    printf("\nOpcao: ");
    scanf("%i", &resposta);
    printf("\n");

    if(resposta == 1) {
        printf("Iniciando...\n");    
        } else if (resposta == 2) {
            printf("Saindo...\n");
            exit(0);
            } else {
                system("clear");
                printf("Opção inválida. Tente novamente.\n\n");
                return escolhaIniciar();
    }
}


void letreiro() {
    
    char xo;
    int posicao;
    int controle = 1;
    int coluna;
    int linha;
    
    printf("\t\t 1 | 2 | 3 \n");
    printf("\t\t-----------\n");
    printf("\t\t 4 | 5 | 6 \n");
    printf("\t\t-----------\n");
    printf("\t\t 7 | 8 | 9 \n\n");

    //matriz do jogo da velha
    for(linha = 0; linha < linhaQuantidade; linha++) 
        for(coluna = 0; coluna < colunaQuantidade; coluna++)
            posicaoJogo[linha][coluna] = '-';
    
    while(1) {
        if(controle %2 == 0) {
            printf("Jogador O informe a posicao.\n");
            scanf("%d", &posicao);
            controle --;
            xo = 'O';
            entradaMatriz(posicao, xo);
        } else {
            printf("Jogador x informe a posicao.\n");
            scanf("%d", &posicao);
            controle ++;
            xo = 'X';
            entradaMatriz(posicao, xo);
        }
        
        printf("\t %c | %c | %c \n", posicaoJogo[0][0], posicaoJogo[0][1], posicaoJogo[0][2]);
        printf("\t-----------\n");
        printf("\t %c | %c | %c \n", posicaoJogo[1][0], posicaoJogo[1][1], posicaoJogo[1][2]);
        printf("\t-----------\n");
        printf("\t %c | %c | %c \n", posicaoJogo[2][0], posicaoJogo[2][1], posicaoJogo[2][2]);

        
        if(validar(xo) == 1) {
            printf("parabens jogado %c venceu", xo);
            break;
        }
    }
}

void entradaMatriz(int push, char elemento) {
    
    if(1 <= push && push > 10) {
        printf("\tposicao inválida.\n\n");
        printf("\t 1 | 2 | 3 \n");
        printf("\t-----------\n");
        printf("\t 4 | 5 | 6 \n");
        printf("\t-----------\n");
        printf("\t 7 | 8 | 9 \n\n");
    }
    
    if(push >= 1 && push <= 3) {
        posicaoJogo[0][push - 1] = elemento;
    }
    
    else if(push >= 4 && push <= 6) {
        posicaoJogo[1][push - 4] = elemento;
    }
    
    else if(push >= 7 && push <= 9) {
        posicaoJogo[2][push - 7] = elemento;
    }
}

int validar(char jogada) {
    int venceu = 0;
    int valida = 0;
    int linha;
    int coluna;
    
    for(linha = 0; linha < linhaQuantidade; linha++) {
            for(coluna = 0; coluna < colunaQuantidade; coluna++) {
                if (posicaoJogo[linha][coluna] == jogada) {
                    valida ++;
                }
            }
            if(valida == 3) {
                venceu = 1;
                break;
            }
            valida = 0;
            printf("\n");
    }
    
    for(coluna = 0; coluna < colunaQuantidade; coluna++) {
            for(linha = 0; linha < linhaQuantidade; linha++) {
                if (posicaoJogo[linha][coluna] == jogada) {
                    valida ++;
                }
            }
            if(valida == 3) {
                venceu = 1;
                break;
            }
            valida = 0;
            printf("\n");
    }
    
    return venceu;
}