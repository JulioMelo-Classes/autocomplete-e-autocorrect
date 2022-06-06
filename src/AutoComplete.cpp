#include "AutoComplete.hpp"

using namespace std;

vector<string> AutoComplete::testeAutoComplete(string entrada, vector<pair<unsigned long int, string>> mDados) {
    int count = 0;
    for (auto i : mDados) {
        for (int j = 0; j < (int)i.second.size(); j++) {
            if (entrada[j] == i.second[j]) {
                count++;
                if (count == entrada.size()) {
                    palavrasAutoComplete.push_back(i.second);
                    break;
                }
            }
        }
        if (palavrasAutoComplete.size() == 5) {
            break;
        }
        count = 0;
    }
    for (auto xx : palavrasAutoComplete) {
        cout << xx << " | ";
    }
    cout << endl;
    palavrasAutoComplete.clear();
    // TESTE COM CLEAR PARA TESTAR NOVAS ENTRADAS
    return palavrasAutoComplete;
}