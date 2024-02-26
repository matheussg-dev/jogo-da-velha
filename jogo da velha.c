#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define linhaQuantidade 3
#define colunaQuantidade 3
#define poicaoVazia ' '
#define JogadorX 'X'
#define JogadorO 'O'

char posicaoJogo[linhaQuantidade][colunaQuantidade];
int cotagem = 0;
int jogadasPartidaTotais = 0;

void letreiro();
void escolhaIniciar();
int validar(char jogada);
void escolhajogador();
int mensagemPosicaoInvalida();
int mensagemPosicao();
int painel();

int main() {
    escolhaIniciar();
    escolhajogador();
}

    
void escolhaIniciar() {
    
    int resposta;
    
    printf("\tOla bem vindo a jogo da velha v1 .\n");
    printf("\tFeito em linguagem C\n\n");
    printf("\t\t   |   |   \n");
    printf("\t\t-----------\n");
    printf("\t\t   |   |   \n");
    printf("\t\t-----------\n");
    printf("\t\t   |   |   \n\n");
    
    printf("\tEscolha uma das opcoes para proseguir.\n");
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

void escolhajogador() {
    
    char respostaJogador;
    
    printf("\tPartidas jogadas %i.\n", cotagem);
    printf("Foram feitas %i jogadas totais.\n", jogadasPartidaTotais);
    printf("\tEscolha o Jogador.\n\n");
    printf("jogadorX: X\n");
    printf("jogadorO: O\n");
    scanf(" %c", &respostaJogador);
    printf("\n");
    
    if(respostaJogador == JogadorX) {
        printf("Jogador X escolhido.\n\n");
        letreiro(1);
    } else if (respostaJogador == JogadorO) {
        printf("Jogador O escolhido.\n\n");
        letreiro(2);
    } else {
        system("clear");
        printf("Escolha inválida. Tente novamente.\n");
        return escolhajogador();
    }
}

void letreiro(int jogador) {
    
    char elemento, xo;
    int posicao, coluna, linha, jogadasPartida = 0, novojogo;

    for(linha = 0; linha < linhaQuantidade; linha++) 
        for(coluna = 0; coluna < colunaQuantidade; coluna++)
            posicaoJogo[linha][coluna] = poicaoVazia;
            
    mensagemPosicao();

    while(1) {

        if (jogador % 2 == 0) {
            xo = JogadorO;
            elemento = 'O';
        } else {
            xo = JogadorX;
            elemento = 'X';
        }
        
        printf("Foram feitas %i jogadas.\n", jogadasPartida);
        printf("Jogador %c, é a sua vez.\n", xo);
        scanf(" %i", &posicao);

        if(posicao >= 1 && posicao <= 3) {
            if (posicaoJogo[0][posicao - 1] != poicaoVazia) {
                mensagemPosicaoInvalida();
                continue;
            } else { 
                posicaoJogo[0][posicao - 1] = elemento;
            }
        }
    
        else if(posicao >= 4 && posicao <= 6) {
            if (posicaoJogo[1][posicao - 4] != poicaoVazia) {
                mensagemPosicaoInvalida();
                continue;
            } else { 
                posicaoJogo[1][posicao - 4] = elemento;
            }
        }
    
        else if(posicao >= 7 && posicao <= 9) {
            if (posicaoJogo[2][posicao - 7] != poicaoVazia) {
                mensagemPosicaoInvalida();
                continue;
            } else { 
                posicaoJogo[2][posicao - 7] = elemento;
            }
        }
        
        if(1 > posicao || posicao > 9) {
            printf("\tPosicao inválida.\n");
            mensagemPosicao();
            continue;
        }
        
        painel();
        
        jogador ++;
        jogadasPartida ++;
        jogadasPartidaTotais ++;

        if(validar(xo) == 1) {
            printf("\tparabens jogador %c venceu.\n", xo);
            break;
        } else if(validar(xo) == 2) {
            printf("\tDeu velha.\n");
            break;
        }
    }
    printf("Voce gostaria de comecar uma nova partida.\n");
    printf("\nsim: 1\n");
    printf("nao: 2\n");
    scanf("%i", &novojogo);

    if(novojogo == 1) {
        cotagem ++;
        return escolhajogador();  
    } else if (novojogo == 2) {
        printf("Saindo...\n");
        exit(0);
    } else {
        printf("Opção inválida. Tente novamente.\n\n");
    }
}

int validar(char jogada) {
    
    int venceu = 0;
    int valida = 0;
    int linha;
    int coluna;
    
    if (posicaoJogo[0][0] == jogada && posicaoJogo[1][1] == jogada && posicaoJogo[2][2] == jogada) {
        venceu = 1;
        return 1;
    } else if (posicaoJogo[0][2] == jogada && posicaoJogo[1][1] == jogada && posicaoJogo[2][0] == jogada) {
        venceu = 1;
        return 1;
    }
    

    for (linha = 0; linha < linhaQuantidade; linha++) {
        for (coluna = 0; coluna < colunaQuantidade; coluna++) {
            if (posicaoJogo[linha][coluna] == jogada) {
                valida++;
            }
        }
        if (valida == 3) {
            venceu = 1;
            return 1;
        }
        valida = 0;
    }

    for (coluna = 0; coluna < colunaQuantidade; coluna++) {
        for (linha = 0; linha < linhaQuantidade; linha++) {
            if (posicaoJogo[linha][coluna] == jogada) {
                valida++;
            }
        }
        if (valida == 3) {
            venceu = 1;
            return 1;
        }
        valida = 0;
    }
    
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            if (posicaoJogo[linha][coluna] == ' ') {
                return 0;
            } else {
                venceu = 2;
            }
        }
    }
    return venceu;
}

int mensagemPosicao() {
    printf("\t 1 | 2 | 3 \n");
    printf("\t-----------\n");
    printf("\t 4 | 5 | 6 \n");
    printf("\t-----------\n");
    printf("\t 7 | 8 | 9 \n\n");
}

int mensagemPosicaoInvalida() {
    printf("Essa posicao ja foi preenchida.\n");
    printf("Escolha uma nova posicao.\n");
    printf("\t 1 | 2 | 3 \n");
    printf("\t-----------\n");
    printf("\t 4 | 5 | 6 \n");
    printf("\t-----------\n");
    printf("\t 7 | 8 | 9 \n\n");
}

int painel() {
    printf("\t %c | %c | %c \n", posicaoJogo[0][0], posicaoJogo[0][1], posicaoJogo[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", posicaoJogo[1][0], posicaoJogo[1][1], posicaoJogo[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n\n", posicaoJogo[2][0], posicaoJogo[2][1], posicaoJogo[2][2]);
}