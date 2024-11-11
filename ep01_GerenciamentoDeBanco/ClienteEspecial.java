public class ClienteEspecial extends Cliente {
    static final int dividaMaxima = 50000;
    static final String tipo      = "CE";

    ClienteEspecial(String nome, int cpf, int valorInicial) {
        super(nome, cpf, valorInicial);
    }

    String retornaTipo() {
        return tipo;
    }

    @Override
    public boolean obterEmprestimo(int valor) {
        return super.obterEmprestimo(valor);
    }
}
