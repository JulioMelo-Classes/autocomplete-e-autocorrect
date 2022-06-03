#include "Dados.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Dados dados(argv[1]);
    string sentenca;
    dados.ordenarAlfabeticamente();
    // dados.imprimirTeste();


    cout << "--------------------------------------------------------------------" << endl;
    cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar:" << endl;
    while(true){
        cout << ">>> ";
        getline(cin, sentenca);
        if (sentenca == " "){ break; }
        cout << "Autocomplete                  | Autocorrect" << endl;
        

        dados.testeAutoComplete(sentenca);
    }

    cout << "\n FIM DO CÓDIGO \n";
    return 0;
}