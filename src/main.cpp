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

    while (true) {
        cout << "------------------------------- AUTOCOMPLETE & AUTOCORRECT -------------------------------" << endl;
        cout << ">>> Digite uma palavra ou parte dela, pressione Enter ou pressione Ctrl + d pra terminar: ";

        while (true) {
            getline(cin, sentenca);
            for_each(sentenca.begin(), sentenca.end(), [](char &c) { c = ::tolower(c); });

            // Validação da entrada do usuário.
            if (sentenca == " " || sentenca == "") {
                cout << ">>> Entrada inválida! Tente novamente." << endl;
                cout << endl;
                break;
            } else {
                cout << ">>> " << sentenca << endl;
            }

            vector<pair<long int, string>> palavrasAutoComplete, palavrasAutoCorrect;
            vector<string> acm, acr;

            palavrasAutoComplete = dados.getPalavrasComplete(sentenca);
            acm = autoComplete.autoComplete(palavrasAutoComplete);

            palavrasAutoCorrect = dados.getPalavrasCorrect(sentenca);
            acr = autoCorrect.autoCorrect(sentenca, palavrasAutoCorrect);

            Interface interface(acm, acr);

            interface.imprimirSaida();

            dados.limparVetor(acm);
            dados.limparVetor(acr);
            dados.limparVetor(palavrasAutoComplete);
            dados.limparVetor(palavrasAutoCorrect);
            break;
        }
    }

    return 0;
}