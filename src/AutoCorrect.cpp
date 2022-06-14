#include "AutoCorrect.hpp"

using namespace std;

AutoCorrect::AutoCorrect(){}

void AutoCorrect::setPalavras(string entrada, vector<pair<long int, string>> mDados) {
    int count = 0;
    vector<string> palavras;

    sort(mDados.begin(), mDados.end(), [](const auto &x, const auto &y) { return x.first < y.first; });

    for (auto i : mDados) {
        if (i.second.size() == entrada.size()){
            palavras.push_back(i.second);
        }
    }

    for (auto j : palavras){
        if (entrada[0] == j[0]){
            palavrasAutoCorrect.push_back(j);
        }
    }
}

std::vector<std::string> AutoCorrect::getPalavras(){
    return palavrasAutoCorrect;
}

void AutoCorrect::limparPalavras(){
    palavrasAutoCorrect.clear();
}
