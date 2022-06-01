#include "Dados.hpp"
using namespace std;

Dados::Dados(string cidades, string ingles, string portugues) {
    string linha;
    ifstream arquivo;
    
    arquivo.open(cidades.c_str());
    while (!arquivo.eof()) {
        getline(arquivo, linha);
        mDadosCidades.push_back(string(linha));
    }
    arquivo.close();

    arquivo.open(ingles.c_str());
    while (!arquivo.eof()) {
        getline(arquivo, linha);
        mDadosIngles.push_back(string(linha));
    }
    arquivo.close();

    arquivo.open(portugues.c_str());
    while (!arquivo.eof()) {
        getline(arquivo, linha);
        mDadosPortugues.push_back(string(linha));
    }
    arquivo.close();
}

vector<string> Dados::getDadosCidades() { return mDadosCidades; }

void Dados::ImprimirTeste() {
    int i = 0;
    while (i < 2) {
        cout << mDadosCidades[i] << endl;
        cout << mDadosIngles[i] << endl;
        cout << mDadosPortugues[i] << endl;
        i++;
    }
}