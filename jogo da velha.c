#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define linhaQuantidade 3
#define colunaQuantidade 3
#define poicaoVazia '-'



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
    
    printf("\tOla bem vindo a jogo da velha v0.4.2 .\n");
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
    printf("\t\t 1 | 2 | 3 \n");
    printf("\t\t-----------\n");
    printf("\t\t 4 | 5 | 6 \n");
    printf("\t\t-----------\n");
    printf("\t\t 7 | 8 | 9 \n\n");

}


void letreiro() {
    
    char xo;
    int posicao;
    int controle = 1;
    int coluna;
    int linha;

    //matriz do jogo da velha
    for(linha = 0; linha < linhaQuantidade; linha++) 
        for(coluna = 0; coluna < colunaQuantidade; coluna++)
            posicaoJogo[linha][coluna] = poicaoVazia;
    
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
        printf("\t %c | %c | %c \n\n", posicaoJogo[2][0], posicaoJogo[2][1], posicaoJogo[2][2]);

        if(validar(xo) == 1) {
            printf("\tparabens jogado %c venceu\n", xo);
            break;
        }
    }
}

void entradaMatriz(int posicao, char elemento) {
    

    if(posicao >= 1 && posicao <= 3) {
        if (posicaoJogo[0][posicao - 1] != poicaoVazia) {
            printf("Essa posicao ja foi preenchida.\n");
            printf("Escolha novamente!\n\n");
            printf("\t 1 | 2 | 3 \n");
            printf("\t-----------\n");
            printf("\t 4 | 5 | 6 \n");
            printf("\t-----------\n");
            printf("\t 7 | 8 | 9 \n\n");
        } else { 
            posicaoJogo[0][posicao - 1] = elemento;
        }
    }
    
    else if(posicao >= 4 && posicao <= 6) {
        if (posicaoJogo[1][posicao - 4] != poicaoVazia) {
            printf("Essa posicao ja foi preenchida.\n");
            printf("Escolha novamente!\n\n");
            printf("\t 1 | 2 | 3 \n");
            printf("\t-----------\n");
            printf("\t 4 | 5 | 6 \n");
            printf("\t-----------\n");
            printf("\t 7 | 8 | 9 \n\n");
        } else { 
            posicaoJogo[1][posicao - 4] = elemento;
        }
    }
    
    else if(posicao >= 7 && posicao <= 9) {
        if (posicaoJogo[2][posicao - 7] != poicaoVazia) {
            printf("Essa posicao ja foi preenchida.\n");
            printf("Escolha novamente!\n\n");
            printf("\t 1 | 2 | 3 \n");
            printf("\t-----------\n");
            printf("\t 4 | 5 | 6 \n");
            printf("\t-----------\n");
            printf("\t 7 | 8 | 9 \n\n");
        } else { 
            posicaoJogo[2][posicao - 7] = elemento;
        }
    }
        
    if(1 > posicao && posicao <10) {
        printf("\tPosicao inválida.\n");
        printf("Escolha novamente!\n\n");
        printf("\t 1 | 2 | 3 \n");
        printf("\t-----------\n");
        printf("\t 4 | 5 | 6 \n");
        printf("\t-----------\n");
        printf("\t 7 | 8 | 9 \n\n");
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
    }
    
    return venceu;
}