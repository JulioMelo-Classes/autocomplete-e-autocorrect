#include "AutoCorrect.hpp"

using namespace std;

AutoCorrect::AutoCorrect(){}

void AutoCorrect::autoCorrect(string entrada, vector<pair<long int, string>> palavras){
    for (auto i : palavras){
        if (i.second[0] == entrada[0]){
            palavrasAutoCorrect.push_back(i.second);
        }
    }
}

std::vector<std::string> AutoCorrect::getPalavras(){
    return palavrasAutoCorrect;
}

void AutoCorrect::limparPalavras(){
    palavrasAutoCorrect.clear();
}
