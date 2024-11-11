# Instituto de Matemática e Estatística - Exercício-Programa I - Bank 110

def calcula_saldo(V, D, M, J):
  S = 0

  while (M > 0):
    if (M == 1):
      S += (V * J) + D
    else:
      S += (V * J) + D

    M -= 1

  return S

def conta_notas(S):
  quant_notas_cem = int(S // 100)
  S %= 100

  quant_notas_cinq = int(S // 50)
  S %= 50

  quant_notas_dez = int(S // 10)
  S %= 10

  quant_notas_dois = int(S // 2)
  S %= 2

  quant_moedas_um_real = int(S // 1)
  S %= 1

  centavos = int(S * 100)
  quant_moedas_cinq_cent = centavos // 50
  centavos %= 50

  quant_moedas_dez_cent = centavos // 10
  centavos %= 10

  quant_moedas_um_cent = centavos
  
  print(f"""
    {quant_notas_cem:d} nota(s) de 100 reais
    {quant_notas_cinq:d} nota(s) de 50 reais
    {quant_notas_dez:d} nota(s) de 10 reais
    {quant_notas_dois:d} nota(s) de 2 reais
    {quant_moedas_um_real:d} moeda(s) de 1 real
    {quant_moedas_cinq_cent:d} moeda(s) de 50 centavos
    {quant_moedas_dez_cent:d} moeda(s) de 10 centavos
    {quant_moedas_um_cent:d} moeda(s) de 1 centavo
  """)

def main():
  V = float(input("Digite o valor do depósito inicial: V "))
  D = float(input("Digite o valor dos depósitos mensais: D "))
  M = int  (input("Digite a quantidade de meses: M "))
  J = float(input("Digite a taxa de juros: J "))

  S = calcula_saldo(V, D, M, J)

  print(f"Após {M} meses, o saldo final foi de {S:.2f} reais.")

  print(f"Os {S:.2f} reais foram sacados com: ")
  conta_notas(S)

main()
