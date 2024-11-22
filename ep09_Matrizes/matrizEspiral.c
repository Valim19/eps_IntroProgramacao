#include <stdio.h>
#include <stdlib.h>

void preencherEspiral(int **matriz, int n) {
    int x = (n % 2 == 0) ? (n / 2) - 1 : n / 2;

    int y = (n % 2 == 0) ? (n / 2) - 1 : n / 2;

    int num = 1;
    matriz[x][y] = num++;

    int passo = 1;
    while (num <= n * n) {
        for (int i = 0; i < passo && num <= n * n; i++) {
            matriz[x][++y] = num++;
        }
        for (int i = 0; i < passo && num <= n * n; i++) {
            matriz[++x][y] = num++;
        }
        passo++;

        for (int i = 0; i < passo && num <= n * n; i++) {
            matriz[x][--y] = num++;
        }

        for (int i = 0; i < passo && num <= n * n; i++) {
            matriz[--x][y] = num++;
        }
        passo++;
    }
}

void imprimirMatriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite um número inteiro positivo para a dimensão da matriz (n): ");
    scanf("%d", &n);

    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)calloc(n, sizeof(int));
    }

    preencherEspiral(matriz, n);
    imprimirMatriz(matriz, n);

    return 0;
}
