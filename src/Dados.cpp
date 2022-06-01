#include "Dados.hpp"
using namespace std;

Dados::Dados(string cidades) {
    string linha;
    ifstream arquivo;
    arquivo.open(cidades.c_str());
    while (!arquivo.eof()) {
        getline(arquivo, linha);
        mDadosCidades.push_back(string(linha));
    }
    arquivo.close();
}

/**
 * @brief Getter para o vetor contendo os dados das cidades.
 */
vector<string> Dados::getDadosCidades() { return mDadosCidades; }

void Dados::ImprimirTeste() {
    int i = 0;
    while (i < 4) {
        cout << mDadosCidades[i] << endl;
        i++;
    }
}