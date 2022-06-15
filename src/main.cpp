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

    dados.verificarDados();
    dados.setDados();
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

            vector<pair<long int, string>> palavras1, palavras2;
            vector<string> acm, acr;

            palavras1 = dados.getPalavrasComplet(sentenca);
            autoComplete.autoComplete(sentenca, palavras1);
            acm = autoComplete.getPalavras();

            palavras2 = dados.getPalavrasCorrect(sentenca);
            autoCorrect.autoCorrect(sentenca, palavras2);
            acr = autoCorrect.getPalavras();
            
            //autoComplete.autoCompleteTeste(sentenca, palavras1);

            Interface interface(acm, acr);

            interface.imprimirSaida();
            
            autoComplete.limparPalavras();
            autoCorrect.limparPalavras();
            interface.limparPar();
            break;
        }
    }

    return 0;
}