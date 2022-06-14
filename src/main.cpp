#include "AutoComplete.hpp"
#include "AutoCorrect.hpp"
#include "Dados.hpp"
#include "Interface.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Dados dados(argv[1]);
    AutoComplete autoComplete;
    AutoCorrect autoCorrect;
    string sentenca;

    dados.ordenarAlfabeticamente();
    dados.escreveVetorOrdenado();

    while (true) {
        cout << "------------------------------- AUTOCOMPLETE & AUTOCORRECT -------------------------------" << endl;
        cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";

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
            autoCorrect.setPalavras(sentenca, dados.getDados());

            Interface interface(autoComplete.getPalavras(), autoCorrect.getPalavras());

            interface.imprimirSaida();
            
            autoComplete.limparPalavras();
            autoCorrect.limparPalavras();
            interface.limparPar();
            break;
        }
    }

    return 0;
}