#include <stdio.h>

#define x 1
#define o 2
#define vazio 0

int main() {
    
    int start;
    int l;
    int c;
    char posiçaoJogo[3][3];

    //mensagem inicial

    printf("Ola bem vindo a jogo da velha.\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    printf("\t-----------\n");
    printf("\t   |   |   \n");
    
    printf("Aperte qualquer tecla para iniciar.\n");
    scanf("%i", &start);
    
    printf("\t 1 | 2 | 3 \n");
    printf("\t-----------\n");
    printf("\t 4 | 5 | 6 \n");
    printf("\t-----------\n");
    printf("\t 7 | 8 | 9 \n");

    //matriz do jogo da velha
    for(l = 0; l < 3; l++) {
        for(c = 0; c < 3; c++) {
            posiçaoJogo[l][c] = ' ';
        }
    }
    
    //imprimir a matriz
    for(l = 0; l < 3; l++) {
        for(c = 0; c < 3; c++) {
            printf("%c", posiçaoJogo[l][c]);
        }
        printf("\n");
    }
    
    return(0);
}