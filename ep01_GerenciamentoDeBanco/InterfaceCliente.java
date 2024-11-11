public interface InterfaceCliente {
    public boolean obterEmprestimo(int valor);

    public boolean pagarEmprestimo(int valor);

    public boolean negativado();

    public boolean realizarSaque(int valor);
}
