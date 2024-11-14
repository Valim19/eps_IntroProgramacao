#include <stdio.h>

#define A 22695477
#define B 1
#define M 4294967296

int gerarNumeroAleatorio(int *x0) {
    *x0 = (A * (*x0) + B) % M;
    return *x0;
}

int escolherJogadaAleatoria(int *x0) {
    int aleatorio = gerarNumeroAleatorio(x0);
    double valor_normalizado = (double) aleatorio / M;

    if (valor_normalizado < 1.0 / 3.0)
        return 1;
    else if (valor_normalizado < 2.0 / 3.0)
        return 2;
    else
        return 3;
}

void determinarResultado(int jogadaHumana, int jogadaComputador, int *vitorias, int *derrotas, int *empates) {
    const char *opcoes[] = {"", "pedra", "papel", "tesoura"};
    printf("%s ", opcoes[jogadaComputador]);

    if (jogadaHumana == jogadaComputador) {
        printf("EMPATE\n");
        (*empates)++;
    } else if ((jogadaHumana == 1 && jogadaComputador == 3) || (jogadaHumana == 2 && jogadaComputador == 1) || (jogadaHumana == 3 && jogadaComputador == 2)) {
        printf("JOGADOR\n");
        (*vitorias)++;
    } else {
        printf("PC\n");
        (*derrotas)++;
    }
}

int calcularJogadaProbabilistica(int historico[3][3], int ultimaJogada, int *x0) {
    int total = historico[ultimaJogada - 1][0] + historico[ultimaJogada - 1][1] + historico[ultimaJogada - 1][2];
    
    if (total == 0) {
        return escolherJogadaAleatoria(x0);
    }

    double probPedra = (double) historico[ultimaJogada - 1][0] / total;
    double probPapel = (double) historico[ultimaJogada - 1][1] / total;
    double probTesoura = (double) historico[ultimaJogada - 1][2] / total;

    if (probPedra > probPapel && probPedra > probTesoura)
        return 2;
    else if (probPapel > probPedra && probPapel > probTesoura)
        return 3;
    else if (probTesoura > probPedra && probTesoura > probPapel)
        return 1;
    else
        return escolherJogadaAleatoria(x0);
}

void exibirEstatisticas(int vitorias, int derrotas, int empates, int totalJogos) {
    printf("%d %d %d\n", vitorias, derrotas, empates);
    printf("%.1f%% %.1f%% %.1f%%\n",
           (vitorias / (double)totalJogos) * 100,
           (derrotas / (double)totalJogos) * 100,
           (empates / (double)totalJogos) * 100);

    if (vitorias > derrotas) {
        printf("JOGADOR\n");
    } else if (derrotas > vitorias) {
        printf("PC\n");
    } else {
        printf("EMPATE\n");
    }
}

void logicaDoJogo(int x0) {
    int jogadaHumana;
    int vitorias = 0, derrotas = 0, empates = 0;
    int numeroDeJogadas = 0;
    int historico[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int ultimaJogada = 0;

    printf("Bem-vindo ao jogo de Jokenpô!\n");
    printf("Escolha sua jogada: 0 (fim de jogo), 1 (pedra), 2 (papel), 3 (tesoura)\n");

    while (1) {
        printf("Sua jogada: ");
        scanf("%d", &jogadaHumana);

        if (jogadaHumana == 0) {
            printf("Fim de Jogo.\n");
            break;
        } else if (jogadaHumana < 1 || jogadaHumana > 3) {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        int jogadaComputador;
        if (numeroDeJogadas < 10) {
            jogadaComputador = escolherJogadaAleatoria(&x0);
        } else {
            jogadaComputador = calcularJogadaProbabilistica(historico, ultimaJogada, &x0);
        }

        determinarResultado(jogadaHumana, jogadaComputador, &vitorias, &derrotas, &empates);
        numeroDeJogadas++;

        if (ultimaJogada != 0) {
            historico[ultimaJogada - 1][jogadaHumana - 1]++;
        }

        ultimaJogada = jogadaHumana;
    }

    exibirEstatisticas(vitorias, derrotas, empates, numeroDeJogadas);
}

int main() {
    int x0 = 8;

    logicaDoJogo(x0);

    return 0;
}
