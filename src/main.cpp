#include "AutoComplete.hpp"
#include "Dados.hpp"


using namespace std;

int main(int argc, char *argv[]) {
    Dados dados(argv[1]);
    AutoComplete autoComplete;
    string sentenca;
    vector<string> a;
    dados.ordenarAlfabeticamente();
    //dados.escreveVetorOrdenado();

    while (true) {
        cout << "--------------------------------------------------------------------" << endl;
        cout << " ** Programa de autocompletar e autocorreção ** " << endl;
        cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";
        getline(cin, sentenca);
        for_each(sentenca.begin(), sentenca.end(), [](char & c) {c = ::tolower(c);});

        cout << ">>> " << sentenca <<  endl;

        if (sentenca == " " || sentenca == "") {
            cout << "Entrada inválida, digite novamente." << endl;
            continue;
        }

        cout << "Autocomplete                  | Autocorrect" << endl;

        // a = dados.testeAutoComplete(sentenca);
        // dados.imprimirTeste();
        autoComplete.testeAutoComplete(sentenca, dados.getDados());
        

        // cout << dados.recursive_binary_search(a, 0, a.size(), sentenca) << endl;
        dados.findLowerBound(sentenca);
    }

    cout << "\n FIM DO CÓDIGO \n";
    return 0;
}