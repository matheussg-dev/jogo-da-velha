#include <stdio.h>

#define x 1
#define o 2
#define vazio 0
char posicaoJogo[3][3];


//protopitagem de metodo
void iniciar();
void letreiro();
void entradaMatriz(int push, char elemento);
void clear();


int main() {
    
    int posicao;
    int controle = 1;
    int c;
    int l;
    
    iniciar();
  
    letreiro();
    while(1) {
        if(controle %2 == 0) {
            printf("Jogador O informe a posicao.\n");
            scanf("%d", &posicao);
            controle --;
            entradaMatriz(posicao, 'O');
        }
        else {
            printf("Jogador x informe a posicao.\n");
            scanf("%d", &posicao);
            controle ++;
            entradaMatriz(posicao, 'X');
        }

        //matriz do jogo da velha
        for(l = 0; l < 3; l++) {
            for(c = 0; c < 3; c++) {
                printf ("%c", posicaoJogo[l][c]);
            }
            printf("\n");
        }
    }
}

void iniciar() {
    
    char resposta;
    
    printf("Ola bem vindo a jogo da velha v 0.1\n");
    printf("Feito em linguagem C\n\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    
    printf("\tescolha uma das opcoes para proseguir.\n");
    printf("\nIniciar: 1\n");
    printf("Sair: 2\n");
    printf("\nOpcao: ");
    scanf("%c", &resposta);
    printf("\n");

    switch (resposta) {
        
        // Adicione aqui o código para a opção Iniciar
        case '1':
            printf("Iniciando...\n");
            break;
            
        // Adicione aqui o código para a opção Sair
        case '2':
            printf("Saindo...\n");
            break;
            
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
    }

    return 0;
}

void letreiro() {
    
    //mensagem inicial
    
    printf("\t 1 | 2 | 3 \n");
    printf("\t-----------\n");
    printf("\t 4 | 5 | 6 \n");
    printf("\t-----------\n");
    printf("\t 7 | 8 | 9 \n");
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