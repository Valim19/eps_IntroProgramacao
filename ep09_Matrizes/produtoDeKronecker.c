#include <stdio.h>
#include <stdlib.h>

void imprimeMatriz(int **matriz, int linha, int coluna){
    printf("\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int** criaMatriz(int linha, int coluna) {
    int **matriz = (int **)malloc(linha * sizeof(int *));

    for (int i = 0; i < linha; i++) {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
    }

    printf("Digite %d números para preencher a sua matriz: \n", linha * coluna);

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    imprimeMatriz(matriz, linha, coluna);

    return matriz;
}

void lerDimensoes(const char *nomeMatriz, int *linhas, int *colunas) {
    printf("Escreva um número maior ou igual a 1 para ser a linha da matriz %s: ", nomeMatriz);
    scanf("%d", linhas);

    printf("Escreva um número maior ou igual a 1 para ser a coluna da matriz %s: ", nomeMatriz);
    scanf("%d", colunas);
}

void multiplicacaoKronecker(int** matriz1, int** matriz2, int m, int n, int p, int q) {
    int linha = m*p;
    int coluna = n*q;
    
    int **matriz3 = (int **)malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++) {
        matriz3[i] = (int *)malloc(coluna * sizeof(int));
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < p; k++) {
                for(int l = 0; l < q; l++){
                    matriz3[i * p + k][j * q + l] = matriz1[i][j] * matriz2[k][l];
                }
            }
        }
    }

    imprimeMatriz(matriz3, linha, coluna);
}

int main() {
    int n, m, p, q;

    lerDimensoes("matriz1", &m, &n);
    lerDimensoes("matriz2", &p, &q);


    int **matriz1 = criaMatriz(m, n);
    int **matriz2 = criaMatriz(p, q);

    multiplicacaoKronecker(matriz1, matriz2, m, n, p, q);

    return 0;
}