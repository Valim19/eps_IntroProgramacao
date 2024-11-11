import java.lang.*;

public class Gerente extends Pessoa implements InterfaceGerente {
    private static final String tipo = "G";
    private Cliente[] clientes;
    private int numClientes;

    Gerente(String nome, int cpf) {
        super(nome, cpf);
        clientes = new Cliente[20];
        numClientes = 0;
    }

    String retornaTipo() {
        return tipo;
    }

    void imprimirClientes() {
        Cliente atual;
        System.out.println("\tNúmero de clientes: " + numClientes);

        for (int i = 0; i < numClientes; i++) {
            atual = clientes[i];
            System.out.println( "\t" + (i + 1) + "\t" + atual.retornaTipo()
                              + "\t" + atual.nome + "\t" + atual.cpf
                              + "\t" + atual.getValorContaCorrente()
                              + "\t" + atual.getValorDaDivida() + "\t" + atual.negativado());
        }
    }

    public boolean adicionarCliente(Cliente cliente) {
        if (numClientes < 20) {
            for (Cliente c : clientes)
                if (c != null && c.cpf == cliente.cpf) return false;

            clientes[numClientes] = cliente;
            numClientes++;
            return true;
        }
        return false;
    }


    public void cobrarTodosEmprestimos() {
        for (Cliente c : clientes) {
            if (c.getValorDaDivida()== 0) {
                return;
            } else if (c.getValorContaCorrente() >= c.getValorDaDivida()) {
                c.setValorContaCorrente(c.getValorContaCorrente() - c.getValorDaDivida());
                c.setValorDaDivida(0);
            } else if (c.getValorContaCorrente() < c.getValorDaDivida()) {
                c.setValorDaDivida(c.getValorDaDivida() - c.getValorContaCorrente());
                c.setValorContaCorrente(0);
            }
        }
    }
}
