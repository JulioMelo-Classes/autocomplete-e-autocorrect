#include "AutoComplete.hpp"
using namespace std;

AutoComplete::AutoComplete(){}

void AutoComplete::autoComplete(string entrada, vector<pair<long int, string>> palavras){
    
    sort(palavras.begin(), palavras.end(), 
                            [](const auto &x, const auto &y) { return x.first > y.first; });

    for (auto i : palavras){
        palavrasAutoComplete.push_back(i.second);
    }
}

void AutoComplete::autoCompleteTeste(string entrada, vector<pair<long int, string>> palavras){
    vector<string> palavras_;

    sort(palavras.begin(), palavras.end(), 
                            [](const auto &x, const auto &y) { return x.first > y.first; });

    for (auto i : palavras){
        cout << i.first << endl;
        cout << i.second << endl;
    }
}

vector<string> AutoComplete::getPalavras(){
    return palavrasAutoComplete;
}

void AutoComplete::limparPalavras(){
    palavrasAutoComplete.clear();
}