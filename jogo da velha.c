#include <stdio.h>
#include <stdlib.h>

#define x 1
#define o 2

char posicaoJogo[3][3];

//protopitagem de metodo
void mensagemIniciar();
void letreiro();
void entradaMatriz(int push, char elemento);
void escolhaIniciar();


int main() {
    
    mensagemIniciar();
    escolhaIniciar();
    letreiro();
    
}

void mensagemIniciar() {
    
    printf("Ola bem vindo a jogo da velha v0.2.1 .\n");
    printf("Feito em linguagem C\n\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n\n");
    
}
    
void escolhaIniciar() {
    
    int resposta;
    
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
    
    int posicao;
    int controle = 1;
    int coluna;
    int linha;
    
    printf("\t 1 | 2 | 3 \n");
    printf("\t-----------\n");
    printf("\t 4 | 5 | 6 \n");
    printf("\t-----------\n");
    printf("\t 7 | 8 | 9 \n");
    
    while(1) {
        if(controle %2 == 0) {
            printf("Jogador O informe a posicao.\n\n");
            scanf("%d", &posicao);
            controle --;
            entradaMatriz(posicao, 'O');
        } else {
            printf("Jogador x informe a posicao.\n\n");
            scanf("%d", &posicao);
            controle ++;
            entradaMatriz(posicao, 'X');
        }

        //matriz do jogo da velha
        for(linha = 0; linha < 3; linha++) {
            for(coluna = 0; coluna < 3; coluna++) {
                printf ("%c", posicaoJogo[linha][coluna]);
            }
            printf("\n");
        }
    }
}

void entradaMatriz(int push, char elemento) {
    if (push == 1) {
        posicaoJogo[0][0] = elemento;
    }
    
    if (push == 2) {
        posicaoJogo[0][1] = elemento;
    }
    
    if (push == 3) {
        posicaoJogo[0][2] = elemento;
    }
    
    if (push == 4) {
        posicaoJogo[1][0] = elemento;
    }
    
    if (push == 5) {
        posicaoJogo[1][1] = elemento;
    }
    
    if (push == 6) {
        posicaoJogo[1][2] = elemento;
    }
    
    if (push == 7) {
        posicaoJogo[2][0] = elemento;
    }
    
    if (push == 8) {
        posicaoJogo[2][1] = elemento;
    }
    
    if (push == 9) {
        posicaoJogo[2][2] = elemento;
    }
}