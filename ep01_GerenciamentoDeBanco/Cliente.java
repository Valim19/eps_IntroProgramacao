public class Cliente extends Pessoa implements InterfaceCliente {
    static final int dividaMaxima = 30000;
    static final String tipo      = "C";
    private int valorContaCorrente;
    private int valorDaDivida;

    Cliente(String nome, int cpf, int valorInicial) {
        super(nome, cpf);
        valorContaCorrente = valorInicial;
        valorDaDivida = 0;
    }

    String retornaTipo() {
        return tipo;
    }

    int getValorContaCorrente() {
        return valorContaCorrente;
    }

    int getValorDaDivida() {
        return valorDaDivida;
    }

    void setValorContaCorrente(int valor) {
        valorContaCorrente = valor;
    }

    void setValorDaDivida(int valor) {
        valorDaDivida = valor;
    }

    public boolean obterEmprestimo(int valor) {
        if (valor <= 0) return false;
        else if ((valor + getValorDaDivida()) > dividaMaxima) return false;
        else {
            setValorDaDivida(valor + getValorDaDivida());
            setValorContaCorrente(valor + getValorContaCorrente());
            return true;
        }
    }

    public boolean pagarEmprestimo(int valor) {
        if (valor <= 0) return false;
        else if ((valor > getValorDaDivida()) | valor > getValorContaCorrente()) return false;
        else {
            setValorDaDivida(getValorDaDivida() - valor);
            setValorContaCorrente(getValorContaCorrente() - valor);
            return true;
        }
    }

    public boolean negativado() {
        return getValorContaCorrente() < getValorDaDivida();
    }

    public boolean realizarSaque(int valor) {
        if (valor <= 0) return false;
        else if (valor > getValorContaCorrente()) return false;
        else {
            setValorContaCorrente(getValorContaCorrente() - valor);
            return true;
        }
    }
}
