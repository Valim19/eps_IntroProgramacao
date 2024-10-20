print("Escolha um método entre m1 e m7 -")
metodo = input()
print("Insira um valor numérico para epsilon -")
epsilon = float(input())

def metodo_Machin(epsilon):
    def arctan(x, epsilon):
        term = x
        arctan_sum = term
        k = 1

        while abs(term) > epsilon:
            term = (-1) ** k * (x ** (2 * k + 1)) / (2 * k + 1)
            arctan_sum += term
            k += 1
        return arctan_sum

    parte1 = 4 * arctan(1/5, epsilon)
    parte2 = arctan(1/239, epsilon)
    pi_aprox = 4 * (parte1 - parte2)
    print(f"m1: {pi_aprox:.15f}")


def metodo_Viete(epsilon):
    def sqrt_newton(n, epsilon):
        x = n
        while abs(x * x - n) > epsilon:
            x = (x + n / x) / 2
        return x

    produto = 1.0
    term = sqrt_newton(2, epsilon)

    while abs(term - 2) > epsilon:
        produto *= term / 2
        term = sqrt_newton(2 + term, epsilon)

    pi_aprox = 2 / produto
    print(f"m2: {pi_aprox:.15f}")

def metodo_Wallis(epsilon):
    produto = 1  # Produto inicial
    numerador = 2
    denominador = 1

    pi_aprox = 2
    
    while True:
        produto *= numerador / denominador
        denominador += 2

        produto *= numerador / denominador
        numerador += 2

        pi_atual = produto * 2

        if abs(pi_atual - pi_aprox) < epsilon:
            break

        pi_aprox = pi_atual

    print(f"m3: {pi_aprox:.15f}")

def metodo_Leibniz(epsilon):
    termo = 1
    soma = 0
    k = 0

    while abs(termo) > epsilon:
        termo = (-1)**k / (2*k + 1)
        soma += termo
        k += 1
    
    pi_aprox = 4 * soma
    print(f"m4: {pi_aprox:.15f}")

def metodo_GregoryLeibniz(epsilon):
    pi_aprox = 3.0
    sinal = 1
    n = 2
    termo = 4 / (n * (n + 1) * (n + 2))
    
    while abs(termo) > epsilon:
        pi_aprox += sinal * termo
        n += 2
        termo = 4 / (n * (n + 1) * (n + 2))
        sinal *= -1
    
    print(f"m5: {pi_aprox:.15f}")


def metodo_Euler(epsilon):
    soma = 0
    n = 1
    termo = 1 / (n ** 2)

    while termo > epsilon:
        soma += termo
        n += 1
        termo = 1 / (n ** 2)
    
    pi_aprox = (6 * soma) ** 0.5
    print(f"m6: {pi_aprox:.15f}")

def metodo_MonteCarlo(epsilon, n_pontos):
    a = 22695477
    b = 1
    m = 2**32
    x = 2749
    pontos_dentro = 0

    for _ in range(n_pontos):
        x = (a * x + b) % m
        y = (a * x + b) % m

        x_coord = x / m
        y_coord = y / m

        if x_coord**2 + y_coord**2 <= 1:
            pontos_dentro += 1
    
    pi_aprox = 4 * (pontos_dentro / n_pontos)
    print(f"m7: {pi_aprox:.15f}")

if metodo == "m1":
    metodo_Machin(epsilon)
elif metodo == "m2":
    metodo_Viete(epsilon)
elif metodo == "m3":
    metodo_Wallis(epsilon)
elif metodo == "m4":
    metodo_Leibniz(epsilon)
elif metodo == "m5":
    metodo_GregoryLeibniz(epsilon)
elif metodo == "m6":
    metodo_Euler(epsilon)
elif metodo == "m7":
    print("Insira o número de pontos para o método Monte Carlo -")
    n_pontos = int(input())
    metodo_MonteCarlo(epsilon, n_pontos)
else:
    print("Você digitou algo diferente das opções disponíveis, tente novamente")
