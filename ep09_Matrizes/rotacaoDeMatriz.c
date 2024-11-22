#include <stdio.h>
#include <stdlib.h>

void criaMatriz(int n) {
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Digite %d números para preencher a sua matriz: \n", n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Escreva um número maior ou igual a 1: ");
    scanf("%d", &n);

    criaMatriz(n);

    return 0;
}