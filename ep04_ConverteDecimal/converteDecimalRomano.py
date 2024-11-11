"""
  Teclado recebe um número inteiro e devolve --> print() um número em algarismos romanos
  
    I - 1
    V - 5
    X - 10
    L - 50
    C - 100
    D - 500
    M - 1000
""" 

n = int(input())

algarismoRomano = ""

if 0 < n <= 3999:
  milhar = n // 1000
  n %= 1000

  centena = n // 100
  n %= 100

  dezena = n // 10
  unidade = n % 10

  algarismoRomano += 'M' * milhar
    
  if centena == 9:
    algarismoRomano += 'CM'
  elif centena >= 5:
    algarismoRomano += 'D' + 'C' * (centena - 5)
  elif centena == 4:
    algarismoRomano += 'CD'
  else:
    algarismoRomano += 'C' * (milhar)

  if dezena == 9:
    algarismoRomano += 'XC'
  elif dezena >= 5:
    algarismoRomano += 'L' + 'X' * (dezena - 5)
  elif dezena == 4:
    algarismoRomano += 'XL'
  else:
    algarismoRomano += 'X' * dezena

  if unidade == 9:
    algarismoRomano += 'IX'
  elif unidade >= 5:
    algarismoRomano += 'V' + 'I' * (unidade - 5)
  elif unidade == 4:
    algarismoRomano += 'IV'
  else:
    algarismoRomano += 'I' * unidade

  print(algarismoRomano)
else:
  print("O número que você digitou está fora do intervalo permitido")
