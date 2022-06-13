#include "Interface.hpp"
using namespace std;

Interface::Interface(vector<string> vetorComplete, vector<string> vetorCorrect){
    mVetores.first = vetorComplete;
    mVetores.second = vetorCorrect;
}

pair<vector<string>, vector<string>> Interface::getPar(){
    return mVetores;
}

void Interface::limparPar(){
    mVetores.first.clear();
    mVetores.second.clear();
}
