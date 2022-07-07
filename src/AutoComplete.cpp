#include "AutoComplete.hpp"
using namespace std;

AutoComplete::AutoComplete() {}

vector<string> AutoComplete::autoComplete(vector<pair<long int, string>> &palavras) {
    vector<string> palavrasAutoComplete;

    sort(palavras.begin(), palavras.end(),  // Ordena pelo peso (maior para o menor).
         [](const auto &x, const auto &y) { return x.first > y.first; });

    for (int i = 0; i < 5; i++) {
        if (i == palavras.size() - 1) {
            break;
        }
        palavrasAutoComplete.push_back(palavras[i].second);
    }

    return palavrasAutoComplete;
}