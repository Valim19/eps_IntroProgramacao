/* 

#include <stdio.h>

#define A 22695477
#define B 1
#define M 4294967296

void congruenciaLinear(int numeroDeJogadas, int *x0, int jogada, int *vitorias, int *derrotas, int *empates, int pedra, int papel, int tesoura) {
    double x1;

    if (numeroDeJogadas < 10) {
        x1 = ((A * (*x0)) + B) % M;
        double valor_normalizado = (double)x1 / M;

        if(valor_normalizado >= 0 && valor_normalizado < 1.0 / 3.0) {
            if(jogada == 1) {
                printf("pedra EMPATE\n");
                (*empates)++;
            } else if(jogada == 2) {
                printf("pedra JOGADOR\n");
                (*vitorias)++;
            } else {
                printf("pedra PC\n");
                (*derrotas)++;
            }
        } else if (valor_normalizado >= 1.0 / 3.0 && valor_normalizado < 2.0 / 3.0) {
            if(jogada == 1) {
                printf("papel PC\n");
                (*derrotas)++;
            } else if(jogada == 2) {
                printf("papel EMPATE\n");
                (*empates)++;
            } else {
                printf("papel JOGADOR\n");
                (*vitorias)++;
            }
        } else {
            if(jogada == 1) {
                printf("tesoura JOGADOR\n");
                (*vitorias)++;
            } else if(jogada == 2) {
                printf("tesoura PC\n");
                (*derrotas)++;
            } else {
                printf("tesoura EMPATE\n");
                (*empates)++;
            }
        }

        *x0 = (int)x1;
    } else {
        double estatisticaPedra   = (double) pedra / numeroDeJogadas;
        double estatisticaPapel   = (double) papel / numeroDeJogadas;
        double estatisticaTesoura = (double) tesoura / numeroDeJogadas;

        if(estatisticaPedra > estatisticaPapel && estatisticaPedra > estatisticaTesoura) {
            printf("papel PC\n");
            (*derrotas)++;
        } else if(estatisticaPapel > estatisticaPedra && estatisticaPapel > estatisticaTesoura) {
            printf("tesoura PC\n");
            (*derrotas)++;
        } else if(estatisticaTesoura > estatisticaPedra && estatisticaTesoura > estatisticaPapel) {
            printf("pedra PC\n");
            (*derrotas)++;
        } else {
            congruenciaLinear(numeroDeJogadas, x0, jogada, vitorias, derrotas, empates, pedra, papel, tesoura);
        }
    }
}

void exibirEstatisticas(int totalJogos, int vitorias, int derrotas, int empates) {
    printf("\nEstatísticas do Jogo:\n");
    printf("Vitórias do Jogador: %d\n", vitorias);
    printf("Derrotas do Jogador: %d\n", derrotas);
    printf("Empates: %d\n", empates);

    double perc_vitorias = (vitorias / (double)totalJogos) * 100.0;
    double perc_derrotas = (derrotas / (double)totalJogos) * 100.0;
    double perc_empates = (empates / (double)totalJogos) * 100.0;

    printf("Porcentagem de Vitórias: %.1f%%\n", perc_vitorias);
    printf("Porcentagem de Derrotas: %.1f%%\n", perc_derrotas);
    printf("Porcentagem de Empates: %.1f%%\n", perc_empates);

    if (vitorias > derrotas) {
        printf("Vencedor Geral: JOGADOR\n");
    } else if (derrotas > vitorias) {
        printf("Vencedor Geral: PC\n");
    } else {
        printf("Vencedor Geral: EMPATE\n");
    }
}

void logicaDoJogo(int x0) {
    int jogada;
    int numeroDeJogadas = 0;
    int vitorias = 0, derrotas = 0, empates = 0;
    int pedra = 0, papel = 0, tesoura = 0;
    int boolean = 1;

    printf("Bem-vinde ao jogo de Jokenpô!\n");
    printf("Escolha sua jogada: 0 (fim de jogo), 1 (pedra), 2 (papel), 3 (tesoura)\n");

    while (boolean) {
        printf("Sua jogada: ");
        scanf("%d", &jogada);

            switch (jogada) {
                case 0:
                    printf("Fim de Jogo.\n");
                    boolean = 0;
                    break;
                case 1:
                    printf("pedra\n");
                    pedra++;
                    break;
                case 2:
                    printf("papel\n");
                    papel++;
                    break;
                case 3:
                    printf("tesoura\n");
                    tesoura++;
                    break;
                default:
                    printf("Faça a jogada novamente, dentro dos limites estabelecidos.\n");
                    break;
            }

            printf("%d\n", pedra);
            printf("%d\n", papel);
            printf("%d\n", tesoura);

        congruenciaLinear(numeroDeJogadas, &x0, jogada, &vitorias, &derrotas, &empates, pedra, papel, tesoura);
        numeroDeJogadas++;
    }

    exibirEstatisticas(numeroDeJogadas, vitorias, derrotas, empates);
}

int main() {
    int x0 = 8;

    logicaDoJogo(x0);

    return 0;
}
*/


// NÃO FUNCIONA
#include <stdio.h>

#define A 22695477
#define B 1
#define M 4294967296

// Função para gerar próximo número pseudo-aleatório usando congruência linear
int gerarNumeroAleatorio(int *x0) {
    *x0 = (A * (*x0) + B) % M;
    return *x0;
}

// Função para escolher a jogada do computador nas primeiras 10 jogadas
int escolherJogadaAleatoria(int *x0) {
    int aleatorio = gerarNumeroAleatorio(x0);
    double valor_normalizado = (double) aleatorio / M;

    if (valor_normalizado < 1.0 / 3.0)
        return 1; // Pedra
    else if (valor_normalizado < 2.0 / 3.0)
        return 2; // Papel
    else
        return 3; // Tesoura
}

// Função para determinar e imprimir o resultado de uma jogada
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

// Função para calcular a jogada do computador a partir da 11ª rodada com base em probabilidades condicionais
int calcularJogadaProbabilistica(int historico[3][3], int ultimaJogada, int *x0) {
    int total = historico[ultimaJogada - 1][0] + historico[ultimaJogada - 1][1] + historico[ultimaJogada - 1][2];
    
    if (total == 0) {
        return escolherJogadaAleatoria(x0);  // Escolha aleatória se não houver histórico
    }

    double probPedra = (double) historico[ultimaJogada - 1][0] / total;
    double probPapel = (double) historico[ultimaJogada - 1][1] / total;
    double probTesoura = (double) historico[ultimaJogada - 1][2] / total;

    if (probPedra > probPapel && probPedra > probTesoura)
        return 2;  // Papel ganha de pedra
    else if (probPapel > probPedra && probPapel > probTesoura)
        return 3;  // Tesoura ganha de papel
    else if (probTesoura > probPedra && probTesoura > probPapel)
        return 1;  // Pedra ganha de tesoura
    else
        return escolherJogadaAleatoria(x0);  // Escolha aleatória em caso de empate nas probabilidades
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

        // Atualizar histórico
        if (ultimaJogada != 0) {
            historico[ultimaJogada - 1][jogadaHumana - 1]++;
        }
        ultimaJogada = jogadaHumana;
    }

    exibirEstatisticas(vitorias, derrotas, empates, numeroDeJogadas);
}

int main() {
    int x0 = 8;  // Semente inicial

    logicaDoJogo(x0);

    return 0;
}
