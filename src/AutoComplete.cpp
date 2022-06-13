#include "AutoComplete.hpp"
using namespace std;

void AutoComplete::setPalavras(string entrada, vector<pair<long int, string>> mDados) {
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
        count = 0;
    }
}

std::vector<std::string> AutoComplete::getPalavras(){
    return palavrasAutoComplete;
}

void AutoComplete::limparPalavras(){
    palavrasAutoComplete.clear();
}