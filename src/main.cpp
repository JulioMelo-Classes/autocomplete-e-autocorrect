#include "Dados.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Dados dados(argv[1]);
    string sentenca;
    vector<string> a;
    dados.ordenarAlfabeticamente();
    // dados.imprimirTeste();

    cout << "--------------------------------------------------------------------" << endl;
    
    while(true){
        cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";
        getline(cin, sentenca);
        cout << ">>> " << sentenca << endl;
        
        if (sentenca == " "){ break; }

        cout << "Autocomplete                  | Autocorrect" << endl;
        
        
        a = dados.testeAutoComplete(sentenca);
        for (auto i : dados.testeAutoComplete(sentenca)){ cout << i << endl; }
        cout << dados.recursive_binary_search(a, 0, a.size(), sentenca) << endl;
        //dados.findLowerAndUpperBound(sentenca);
    }

    cout << "\n FIM DO CÓDIGO \n";
    return 0;
}