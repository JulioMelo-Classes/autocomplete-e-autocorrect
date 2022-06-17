#include "AutoComplete.hpp"
using namespace std;

AutoComplete::AutoComplete(){}

vector<string> AutoComplete::autoComplete(string entrada, vector<pair<long int, string>> palavras){
    vector<string> palavrasAutoComplete;
    
    sort(palavras.begin(), palavras.end(), //Ordena pelo peso (maior para o menor).
                            [](const auto &x, const auto &y) { return x.first > y.first; });

    for (auto i : palavras){
        palavrasAutoComplete.push_back(i.second);
    }

    return palavrasAutoComplete;
}