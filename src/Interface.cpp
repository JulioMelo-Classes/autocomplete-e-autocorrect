#include "Interface.hpp"
using namespace std;

Interface::Interface(vector<string> vetorComplete, vector<string> vetorCorrect){
    mVetorComplete = vetorComplete;
    mVetorCorrect = vetorCorrect;
}

void Interface::imprimirSaida(){
    int count = 0, tamanho;
    cout << "Autocomplete                  | Autocorrect" << endl;

    for (int i = 0; i < mVetorCorrect.size(); i++){
        count++;
        try {
            cout << mVetorComplete[i];
            tamanho = 30 - mVetorComplete[i].size();
        } catch (...) {
            tamanho = 30;
        }

        for (int j = 0; j < tamanho; j++){
            cout << ' ';
        }
        cout << "| ";

        try {
            cout << mVetorCorrect[i];
        } catch (...) {
            cout << "";
        }
        cout << endl;

        if (count == 5){
            break;
        }
    }    
    cout << endl;
}

