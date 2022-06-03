#include "Dados.hpp"
using namespace std;

Dados::Dados(string dados) {
    string linha;
    ifstream arquivo;
    

    arquivo.open(dados.c_str());
    while (!arquivo.eof()) {
        getline(arquivo, linha, ' ');
        unsigned long int peso = stoul(linha);
        getline(arquivo, linha);
        mDados.push_back(make_pair(peso, linha));
    }
    arquivo.close();
}

vector<pair<unsigned long int, string>> Dados::getDados() { return mDados; }

void Dados::ordenarAlfabeticamente() {
    auto lambdaAlpha = [] (const auto &x, const auto &y) { return x.second < y.second; };
    sort(mDados.begin(), mDados.end(), lambdaAlpha);
}


//  ******  Testes  *******  //////////////
//  ******  Testes  *******  //////////////
void Dados::imprimirTeste() {
    int i = 0;
    while (i < 5) {
        cout << mDados[i].first << endl;
        cout << mDados[i].second << endl;
        i++;
    }
}