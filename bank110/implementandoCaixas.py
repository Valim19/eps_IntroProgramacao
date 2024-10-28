# Bank 110 - Exercício-Programa II - Instituto de Matemática e Estatística

def deposito(cliente, notas, cn):
    print("Hello")

def saque(cliente, valor_saque, cn):
    print("World")

def transferencia(cliente, valor_transferencia, cliente_credito):
    print("Goodbye")

def main():
    N = int(input("Digite a quantidade de caixas eletrônicos: "))
    quant_notas = [[0]*7 for _ in range(N)]

    for i in range(N):
        print(f"Digite a quantidade de notas do caixa {i+1}: q100 q50 q20 q10 q5 q2 q1")

        for j in range(7):
            quant_notas[i][j] = int(input())

    operacao = int(input("Escolha a operação desejada: [1|2|3] "))
    cn = int(input("Digite o número do caixa: "))
    cliente = input("Digite o seu nome: ")

    if (operacao == 1):
        notas = [0]*7

        print("Digite a quantidade de notas para depósito: ")
        for i in range(7):
            notas[i] = int(input())

        deposito(cliente, notas, cn)

    elif (operacao == 2):
        valor_saque = int(input("Digite o valor do saque: "))

        saque(cliente, valor_saque, cn)

    else:
        valor_transferencia = int(input("Digite o valor da transferência: "))
        cliente_credito = int(input("Digite o nome da pessoa que será creditada: "))

        transferencia(cliente, valor_transferencia, cliente_credito)

main()