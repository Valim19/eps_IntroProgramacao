print("Olá, estamos prestes a começarmos a nossa partida de NIM!")

def computadorEscolheJogada(n, m):
    for quantidade_retirada in range(1, m + 1):
        if (n - quantidade_retirada) % (m + quantidade_retirada) == 0:
            return quantidade_retirada

    return min(m, n)

def usuarioEscolheJogada(n, m):
  quantidade_retirada = int(input(f"Insira o número de peças que quer retirar, até no máximo {m} "))

  while quantidade_retirada < 1 or quantidade_retirada > m or quantidade_retirada > n:
    print("Quantidade de peças inválida, tente novamente")
    quantidade_retirada = int(input(f"Insira o número de peças que quer retirar, até no máximo {m} "))
  
  return quantidade_retirada

def partida():
  n = int(input("Escolha o número de peças do tabuleiro "))
  m = int(input("Escolha um número de peças máximas que podem ser retiradas "))

  if n % (m + 1) == 0:
    print("Você começa!")
    jogada_atual = "usuario"
  else:
    print("O computador começa")
    jogada_atual = "computador"

  while n > 0:
    if jogada_atual == "usuario":
      jogada = usuarioEscolheJogada(n, m)
      print(f"Você retirou {jogada} peça(s)")
      jogada_atual = "computador"
    else:
      jogada = computadorEscolheJogada(n, m)
      print(f"O computador retirou {jogada} peça(s)")
      jogada_atual = "usuario"

    n -= jogada
    print(f"Restam {n} peças no tabuleiro")

  if jogada_atual == "computador":
    print("Parabéns, você ganhou!")
  else:
    print("Que pena, o computador te venceu.")

partida()
