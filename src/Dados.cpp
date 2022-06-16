#include "Dados.hpp"
using namespace std;

Dados::Dados(string dados) {
    mArquivo = dados;
}

void Dados::verificarDados() {
    string linha, tipoDeErro;
    ifstream arquivo;
    int c_linha1 = 0, c_linha2 = 0;

    arquivo.open(mArquivo.c_str());
    // Verifica se o arquivo existe/está aberto.
    if (!arquivo.is_open()) {
        cout << "Erro! Arquivo inexistente." << endl;
        exit(-1);
    }

    pair<string, string> dadosErro;
    while (!arquivo.eof()) {
        c_linha1++;

        try {
            getline(arquivo, linha, ' ');
            long int peso = stol(linha);
            getline(arquivo, linha, '\n');
            linha.erase(linha.size() - 1);
            for (auto caractere : linha) {
                if (!(caractere >= 'a' && caractere <= 'z') && !(caractere == ' ')) {
                    dadosErro.first = "Caractere inválido ";
                    dadosErro.second = caractere;
                    dadosErro.second.append(" ");
                    throw dadosErro;
                }
            }
            // Verifica se o peso é negativo.
            if (peso <= 0) {
                dadosErro.first = "Peso negativo ";
                dadosErro.second = '\0';
                throw dadosErro;
            }
            // Verifica se a palavra está vazia.
            if (linha.empty()) {
                dadosErro.first = "Palavra vazia ";
                dadosErro.second = '\0';
                throw dadosErro;
            }

        } catch (pair<string, string> err) {
            cout << "Erro! " << err.first << err.second << "na linha " + to_string(c_linha1) << '.' << endl;
            exit(-1);
        }
    }
    arquivo.close();
}

void Dados::setDados() {
    string linha;
    ifstream arquivo;

    arquivo.open(mArquivo.c_str());

    while (!arquivo.eof()) {
        getline(arquivo, linha, ' ');
        long int peso = stol(linha);
        getline(arquivo, linha, '\n');
        linha.erase(linha.size() - 1);
        mDados.push_back(make_pair(peso, linha));
    }

    arquivo.close();
}

void Dados::ordenarAlfabeticamente() {
    sort(mDados.begin(), mDados.end(),
         [](const auto &x, const auto &y) { return x.second < y.second; });
}

vector<pair<long int, string>> Dados::getPalavrasComplet(string entrada) {
    vector<pair<long int, string>> palavras;
    int count = 0;
    for (auto i : mDados) {
        for (int j = 0; j < (int)entrada.size(); j++) {
            if (entrada[j] == i.second[j]) {
                count++;
                if (count == entrada.size()) {
                    palavras.push_back(i);
                    break;
                }
            }
        }
        count = 0;
    }
    return palavras;
}

vector<pair<long int, string>> Dados::getPalavrasCorrect(string entrada) {
    vector<pair<long int, string>> palavras;
    for (auto i : mDados) {
        if (((i.second.size() == (entrada.size() + 1)) && (i.second.size() > 2)) || ((i.second.size() == (entrada.size())) && (i.second.size() > 2))) {
            palavras.push_back(i);
        }
    }
    return palavras;
}

void Dados::escreveVetorOrdenado() {
    fstream arquivo;
    arquivo.open("../data/palavrasOrdAlf.txt", ios::app);
    for (auto i : mDados) {
        arquivo << i.first << " " << i.second << '\n';
    }
    arquivo.close();
}

void Dados::limparVetor(vector<string> vetor){
    vetor.clear();
}