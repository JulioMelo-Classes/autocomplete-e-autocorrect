#include "AutoComplete.hpp"
#include "Dados.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Dados dados(argv[1]);
    AutoComplete autoComplete;
    vector<string> palavrasComplete;
    vector<string> palavrasCorrect;
    int count1 = 0, count2 = 0;
    string sentenca;

    dados.ordenarAlfabeticamente();
    dados.escreveVetorOrdenado();

    while (true){
        cout << "------------------------------- AUTOCOMPLETE & AUTOCORRECT -------------------------------" << endl;
        cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";
        count1 = count2 = 0;
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

            cout << "Autocomplete                  | Autocorrect" << endl;

            for (auto i : autoComplete.getPalavras()){
                count1++;
                cout << i << endl;
                if (count1 == 5){
                    break;
                }
            }

            autoComplete.limparPalavras();
            break;
        }
    }

    return 0;
}