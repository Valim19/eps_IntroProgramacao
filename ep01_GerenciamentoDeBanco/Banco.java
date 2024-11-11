public class Banco {
    private Gerente[] gerentes;
    private int numGerentes;

    Banco() {
        gerentes = new Gerente[10];
        numGerentes = 0;
    }

    void imprimir(){
        System.out.println("#########################################################################");
        System.out.println("Imprimindo informacoes do banco.");
        System.out.println("Ha " + numGerentes + " gerente(s) neste banco.");
        Gerente ger;
        for (int g = 0; g < numGerentes; g++){
            ger = gerentes[g];
            System.out.println("Gerente: " + ger.nome + "\tCPF: " + ger.cpf);
            ger.imprimirClientes();
        }
        System.out.println("#########################################################################");
    }

    boolean adicionarGerente(Gerente gerente){
        if (numGerentes < 20 ) {
            for (Gerente g : gerentes)
                if (g!= null && g.cpf == gerente.cpf) return false;

            gerentes[numGerentes] = gerente;
            numGerentes++;
            return true;
        }

        return false;
    }
}
