#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100  // Aumentado para suportar palavras maiores

// Estrutura para armazenar palavras e suas chaves
typedef struct {
    char *word;
    char *key;
} Word;

// Função para comparar caracteres para ordenação
int compare_chars(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

// Função para comparar palavras pela chave
int compare_keys(const void *a, const void *b) {
    return strcmp(((Word *)a)->key, ((Word *)b)->key);
}

// Função para comparar palavras alfabeticamente
int compare_words(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Função que gera uma "chave" ordenando as letras da palavra
void generate_key(const char *word, char *key) {
    strcpy(key, word);
    qsort(key, strlen(key), sizeof(char), compare_chars);
}

// Programa principal
int main() {
    FILE *file = fopen("dicionario.txt", "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int capacity = 1000;  // Capacidade inicial
    Word *words = malloc(capacity * sizeof(Word));
    if (!words) {
        perror("Falha ao alocar memória");
        return 1;
    }

    int word_count = 0;
    char buffer[MAX_LEN];

    // Leitura do arquivo
    while (fscanf(file, "%s", buffer) != EOF) {
        if (word_count == capacity) {
            capacity *= 2;
            words = realloc(words, capacity * sizeof(Word));
            if (!words) {
                perror("Falha ao realocar memória");
                return 1;
            }
        }

        words[word_count].word = strdup(buffer);
        words[word_count].key = malloc(strlen(buffer) + 1);
        generate_key(buffer, words[word_count].key);
        word_count++;
    }
    fclose(file);

    // Ordenação das palavras pelas chaves
    qsort(words, word_count, sizeof(Word), compare_keys);

    // Identificação do maior grupo de anagramas
    int max_group_size = 0;
    int max_group_start = 0;
    int current_group_size = 1;

    for (int i = 1; i < word_count; i++) {
        if (strcmp(words[i].key, words[i - 1].key) == 0) {
            current_group_size++;
            if (current_group_size > max_group_size) {
                max_group_size = current_group_size;
                max_group_start = i - current_group_size + 1;
            }
        } else {
            current_group_size = 1;
        }
    }

    // Coleta e ordenação do maior grupo de anagramas
    char **anagrams = malloc(max_group_size * sizeof(char *));
    if (!anagrams) {
        perror("Falha ao alocar memória para anagramas");
        return 1;
    }

    for (int i = 0; i < max_group_size; i++) {
        anagrams[i] = words[max_group_start + i].word;
    }
    qsort(anagrams, max_group_size, sizeof(char *), compare_words);

    // Impressão dos resultados
    for (int i = 0; i < max_group_size; i++) {
        printf("%s\n", anagrams[i]);
    }

    // Liberação de memória
    for (int i = 0; i < word_count; i++) {
        free(words[i].word);
        free(words[i].key);
    }
    free(words);
    free(anagrams);

    return 0;
}
