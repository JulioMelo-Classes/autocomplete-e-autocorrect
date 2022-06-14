#include "Interface.hpp"
using namespace std;

Interface::Interface(vector<string> vetorComplete, vector<string> vetorCorrect){
    mVetores.first = vetorComplete;
    mVetores.second = vetorCorrect;
}

void Interface::imprimirSaida(){
    int count = 0, tamanho;
    cout << "Autocomplete                  | Autocorrect" << endl;
    for (int i = 0; i < mVetores.first.size(); i++){
        count++;
        cout << mVetores.first[i];
        tamanho = 30 - mVetores.first[i].size();
        for (int j = 0; j < tamanho; j++){
            cout << ' ';
        }
        cout << "| ";
        cout << mVetores.second[i];
        cout << endl;
        if (count == 5){
            break;
        }
    }    
    cout << endl;
}


void Interface::limparPar(){
    mVetores.first.clear();
    mVetores.second.clear();
}
