#include "Interface.hpp"
using namespace std;

Interface::Interface(vector<string> vetorComplete, vector<string> vetorCorrect) {
    mVetorComplete = vetorComplete;
    mVetorCorrect = vetorCorrect;
}

void Interface::imprimirSaida() {
    vector<pair<string, string>> palavras;
    cout << "Autocomplete                | Autocorrect" << endl;

    for (int i = 0; i < mVetorComplete.size(); i++) {
        if (mVetorComplete[i].empty()) {
            palavras.push_back(make_pair("                            ", mVetorCorrect[i]));
        } else {
            palavras.push_back(make_pair(mVetorComplete[i], mVetorCorrect[i]));
        }
    }

    for (auto i : palavras) {
        if (i.first[0] != ' ') {
            cout << i.first;
            cout << setw(30 - i.first.size());
            cout << "| " << i.second << endl;
        } else {
            cout << i.first;
            cout << "| " << i.second << endl;
        }
    }
    cout << endl;
}