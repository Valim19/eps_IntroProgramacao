#include <stdio.h>

#define TAMANHO 3

void imprimeTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("[%c]", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int executaJogo(char tabuleiro[TAMANHO][TAMANHO]) {
  int turno = 0;
  int linha, coluna;
  char primeiroJogador = 'X', segundoJogador = 'O';
  char jogada;

  while (1) {
    jogada = (turno == 0) ? primeiroJogador : segundoJogador;
    printf("Jogador %c, insira sua jogada (linha e coluna): ", jogada);
    scanf("%d %d", &linha, &coluna);

    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
      tabuleiro[linha][coluna] = jogada;

      imprimeTabuleiro(tabuleiro);

      // Verificar linhas, colunas e diagonais para encontrar um vencedor
      for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
          return (tabuleiro[i][0] == 'X') ? 1 : 2;
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
          return (tabuleiro[0][i] == 'X') ? 1 : 2;
        }
      }

      if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return (tabuleiro[0][0] == 'X') ? 1 : 2;
      }
      if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return (tabuleiro[0][2] == 'X') ? 1 : 2;
      }

      int cheio = 1;
      for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
          if (tabuleiro[i][j] == ' ') {
            cheio = 0;
            break;
          }
        }
        if (!cheio) break;
      }

      if (cheio) return 3;

      turno = 1 - turno;
    } else {
        printf("Posição inválida! Tente novamente.\n");
    }
  }
  return 4; // Jogo em andamento
}

int verificaStatus(char tabuleiro[TAMANHO][TAMANHO]) {
  int estadoDoJogo = executaJogo(tabuleiro);

  switch (estadoDoJogo) {
    case 0:
      printf("Jogo não iniciado, o tabuleiro está vazio!\n");
      break;
    case 1:
      printf("Jogo encerrado 1: o primeiro jogador ganhou!\n");
      break;
    case 2:
      printf("Jogo encerrado 2: o segundo jogador ganhou!\n");
      break;
    case 3:
      printf("Jogo encerrado 3: empate! Nenhum dos jogadores ganhou.\n");
      break;
    case 4:
      printf("Jogo já iniciado e em andamento.\n");
      break;
  }

  return estadoDoJogo;
}

int main() {
  char tabuleiro[TAMANHO][TAMANHO] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };

  verificaStatus(tabuleiro);
}

