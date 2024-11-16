#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void cipherCode(const char *ciphertext, int *ciphercode, int n) {
    for (int i = 0; i < n; i++) {
        if (ciphertext[i] == '_') ciphercode[i] = 0;
        else if (ciphertext[i] == '.') ciphercode[i] = 27;
        else ciphercode[i] = ciphertext[i] - 'a' + 1;
    }
}

void plainCodeToText(const int *plaincode, char *plaintext, int n) {
    for (int i = 0; i < n; i++) {
        if (plaincode[i] == 0) plaintext[i] = '_';
        else if (plaincode[i] == 27) plaintext[i] = '.';
        else plaintext[i] = 'a' + plaincode[i] - 1;
    }
    plaintext[n] = '\0';
}

void decrypt(const int *ciphercode, int *plaincode, int n, int k) {
    for (int i = 0; i < n; i++) {
        int index = (k * i) % n;
        plaincode[index] = (ciphercode[i] + i) % 28;
        if (plaincode[index] < 0) plaincode[index] += 28;
    }
}

void readFile(const char *fileName, char *content) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro! Não foi possível abrir o arquivo %s.\n", fileName);
        exit(1);
    }
    fgets(content, MAX_SIZE, file);
    fclose(file);
}

void writeFile(const char *fileName, const char *content) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Erro! Não foi possível abrir o arquivo %s.\n", fileName);
        exit(1);
    }
    fprintf(file, "%s", content);
    fclose(file);
}

#define MAX_DICTIONARY_WORDS 10000

int loadDictionary(const char *fileName, char dictionary[][50], int maxWords) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro! Não foi possível abrir o arquivo do dicionário %s.\n", fileName);
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%49s", dictionary[count]) == 1 && count < maxWords) {
        count++;
    }
    fclose(file);
    return count;
}

bool isWordInDictionary(const char *word, char dictionary[][50], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isMessageValid(const char *message, char dictionary[][50], int dictSize) {
    char word[50];
    int pos = 0, wordLen = 0;

    while (message[pos] != '\0') {
        if (message[pos] == '_' || message[pos] == '.') {
            if (wordLen > 0) {
                word[wordLen] = '\0';
                if (!isWordInDictionary(word, dictionary, dictSize)) {
                    return false;
                }
                wordLen = 0;
            }
        } else {
            word[wordLen++] = message[pos];
        }
        pos++;
    }

    if (wordLen > 0) {
        word[wordLen] = '\0';
        if (!isWordInDictionary(word, dictionary, dictSize)) {
            return false;
        }
    }

    return true;
}

void plainText(const char *ciphertext, const char *outputFileName, int n) {
    int ciphercode[MAX_SIZE];
    int plaincode[MAX_SIZE];
    char plaintext[MAX_SIZE];
    char dictionary[MAX_DICTIONARY_WORDS][50];

    int dictSize = loadDictionary("dicionario.txt", dictionary, MAX_DICTIONARY_WORDS);

    cipherCode(ciphertext, ciphercode, n);

    for (int k = 1; k <= 300; k++) {
        if (gcd(k, n) != 1) continue;

        decrypt(ciphercode, plaincode, n, k);
        plainCodeToText(plaincode, plaintext, n);

        if (isMessageValid(plaintext, dictionary, dictSize)) {
            writeFile(outputFileName, plaintext);
            return;
        }
    }

    printf("Não foi possível descriptografar a mensagem.\n");
}


int main() {
    char ciphertext[MAX_SIZE];
    readFile("ciphertext.txt", ciphertext);

    int n = strlen(ciphertext);
    plainText(ciphertext, "plaintext.txt", n);

    return 0;
}
