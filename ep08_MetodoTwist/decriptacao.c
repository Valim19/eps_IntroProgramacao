#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Erro! Não foi possível abrir o arquivo %s.\n", fileName);
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha);
    }

    fclose(file);
}

void writeFile(const char *fileName) {
    FILE *file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Erro! Não foi possível abrir o arquivo %s. \n", fileName);
    }

    char *linhas[] = {
        "Esta é a primeira linha.\n",
        "Esta é a segunda  linha.\n",
        "Esta é a terceira linha.\n"
    };

    for(int i = 0; i < 3; i++) {
        fputs(linhas[i], file);
    }
        
    fclose(file);
}

void plainText() {

}

void plainCode() {

}

void cipherCode() {

}

void cipherText() {

}

int main() {
    readFile("ciphertext.txt");

    writeFile("plaintext.txt");

    return 0;
}