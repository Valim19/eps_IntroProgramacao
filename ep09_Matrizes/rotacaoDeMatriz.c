#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int **matriz, int n){
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void rotacionaMatriz(int **matriz, int n) {
    int **temp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        temp[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = matriz[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(temp[i]);
    }
    free(temp);

    imprimeMatriz(matriz, n);
}


int** criaMatriz(int n) {
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

    imprimeMatriz(matriz, n);

    return matriz;
}

int main() {
    int n;
    printf("Escreva um número maior ou igual a 1: ");
    scanf("%d", &n);

    int **matriz = criaMatriz(n);

    rotacionaMatriz(matriz, n);

    return 0;
}