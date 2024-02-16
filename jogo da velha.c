#include <stdio.h>

#define x 1
#define o 2
#define vazio 0
char posicaoJogo[3][3];


//protopitagem de metodo
void letreiro();
void entradaMatriz(int push, char elemento);


int main() {
    
    int posicao;
    int controle = 1;
    int c;
    int l;
  
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

void letreiro() {
    
    //mensagem inicial

    printf("Ola bem vindo a jogo da velha.\n\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    
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