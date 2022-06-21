#include "Interface.hpp"
using namespace std;

Interface::Interface(vector<string> vetorComplete, vector<string> vetorCorrect) {
    mVetorComplete = vetorComplete;
    mVetorCorrect = vetorCorrect;
}

void Interface::imprimirSaida() {
    int limiteFix = mVetorComplete.size();

    vector<pair<string, string>> palavras;
    cout << "--------------------------------------------" << endl;
    cout << "Autocomplete                | Autocorrect" << endl;
    cout << "↓ ————————————————————————— | ↓ ————————————" << endl;

    for (int i = 0; i < 5; i++) {
        if (limiteFix == i) {
            mVetorComplete.push_back("  ");
            limiteFix++;
        }
    }

    for (int i = 0; i < (int)mVetorCorrect.size(); i++) {
        cout << mVetorComplete[i];
        cout << setw(30 - mVetorComplete[i].size());
        cout << "| " << mVetorCorrect[i] << endl;
    }

    cout << endl;
}