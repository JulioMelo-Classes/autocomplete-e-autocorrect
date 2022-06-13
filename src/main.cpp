#include "AutoComplete.hpp"
#include "Dados.hpp"
#include "Interface.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Dados dados(argv[1]);
    AutoComplete autoComplete;

    int count, tamanho;
    string sentenca;

    dados.ordenarAlfabeticamente();
    dados.escreveVetorOrdenado();

    while (true) {
        cout << "------------------------------- AUTOCOMPLETE & AUTOCORRECT -------------------------------" << endl;
        cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";

        count = 0;

        while (true) {
            getline(cin, sentenca);
            for_each(sentenca.begin(), sentenca.end(), [](char & c) {c = ::tolower(c);});

            if (sentenca == " " || sentenca == "") {
                cout << ">>> Entrada inválida! Tente novamente." << endl;
                break;
            } else {
                cout << ">>> " << sentenca <<  endl;
            }

            autoComplete.setPalavras(sentenca, dados.getDados());

            Interface interface(autoComplete.getPalavras(), autoComplete.getPalavras());

            cout << "Autocomplete                  | Autocorrect" << endl;

            for (int i = 0; i < interface.getPar().first.size(); i++){
                count++;
                cout << interface.getPar().first[i];
                tamanho = 30 - interface.getPar().first[i].size();
                for (int j = 0; j < tamanho; j++){
                    cout << ' ';
                }
                cout << "| ";
                cout << interface.getPar().second[i];
                cout << endl;
                if (count == 5){
                    break;
                }
            }    
            cout << endl;

            autoComplete.limparPalavras();
            interface.limparPar();
            break;
        }
    }

    return 0;
}