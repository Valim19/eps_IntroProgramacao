# Bank 110 - Exercício-Programa II - Instituto de Matemática e Estatística

VALORES_NOTAS = [100, 50, 20, 10, 5, 2, 1]

N = int(input("Digite a quantidade de caixas eletrônicos: "))
quant_notas = [[0] * 7 for _ in range(N)]

for i in range(N):
    print(f"Digite a quantidade de notas do caixa {i+1}: q100 q50 q20 q10 q5 q2 q1")
    quant_notas[i] = list(map(int, input().split()))

clientes = []
saldos = []

def deposito(cliente, notas, cn):
    global clientes, saldos
    saldo = sum(notas[i] * VALORES_NOTAS[i] for i in range(7))

    if cliente in clientes:
        i = clientes.index(cliente)
        saldos[i] += saldo
    else:
        clientes.append(cliente)
        saldos.append(saldo)

    for i in range(7):
        quant_notas[cn - 1][i] += notas[i]

    print(f"Saldo depositado: {saldo}")

def saque(cliente, valor_saque, cn):
    global clientes, saldos

    if cliente in clientes:
        idx = clientes.index(cliente)  # Usar idx para evitar conflito
        if saldos[idx] >= valor_saque:
            notas_usadas = [0] * 7
            valor_original = valor_saque

            for j in range(7):
                while valor_saque >= VALORES_NOTAS[j] and quant_notas[cn - 1][j] > 0:
                    valor_saque -= VALORES_NOTAS[j]
                    quant_notas[cn - 1][j] -= 1
                    notas_usadas[j] += 1

            if valor_saque == 0:
                saldos[idx] -= valor_original
                print(f"Saque realizado com sucesso. O seu saldo agora é {saldos[idx]}")
            else:
                print("Notas insuficientes no caixa para realizar o saque.")
                for j in range(7):
                    quant_notas[cn - 1][j] += notas_usadas[j]
        else:
            print("Saldo insuficiente.")
    else:
        print("Cliente não encontrado.")

def transferencia(cliente, valor_transferencia, cliente_credito):
    global clientes, saldos

    if cliente in clientes and cliente_credito in clientes:
        i_debito = clientes.index(cliente)
        i_credito = clientes.index(cliente_credito)

        if saldos[i_debito] >= valor_transferencia:
            saldos[i_debito] -= valor_transferencia
            saldos[i_credito] += valor_transferencia
            print("Transferência realizada com sucesso.")
        else:
            print("Saldo insuficiente para transferência.")
    else:
        print("Cliente(s) não encontrado(s).")

def relatorio():
    print("\nDados dos clientes:")
    print("Nome: saldo (R$)")
    for i in range(len(clientes)):
        print(f"{clientes[i]}: {saldos[i]}")
    print("\nRelatório de caixas:")
    print("caixa: n100 n50 n20 n10 n5 n2 n1")
    for i in range(N):
        print(f"{i+1}: {' '.join(map(str, quant_notas[i]))}")

def main():
    while True:
        operacao = int(input("Escolha a operação desejada: [1|2|3|0] "))

        if operacao == 0:
            relatorio()
            break

        cn = int(input("Digite o número do caixa: "))
        cliente = input("Digite o seu nome: ")

        if operacao == 1:
            notas = list(map(int, input("Digite a quantidade de notas para depósito: ").split()))
            deposito(cliente, notas, cn)
        elif operacao == 2:
            valor_saque = int(input("Digite o valor do saque: "))
            saque(cliente, valor_saque, cn)
        elif operacao == 3:
            valor_transferencia = int(input("Digite o valor da transferência: "))
            cliente_credito = input("Digite o nome da pessoa que será creditada: ")
            transferencia(cliente, valor_transferencia, cliente_credito)

main()
