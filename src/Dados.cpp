#include "Dados.hpp"
using namespace std;

#include <sstream>
#include <iterator>

Dados::Dados(string dados) {
    string linha;
    ifstream arquivo;

    arquivo.open(dados.c_str());
    while (!arquivo.eof()) {
        getline(arquivo, linha);
        
        vector<string> words{};
        char delimiter = ' ';
        istringstream iss(linha);
        copy(std::istream_iterator<string>(iss),
            std::istream_iterator<string>(),
            std::back_inserter(words));

        unsigned long int peso = stoul(words[0]);
        mDados.push_back(make_pair(peso, words[1]));
    }
    arquivo.close();
}

vector<pair<unsigned long int, string>> Dados::getDados() { return mDados; }

void Dados::ordenarAlfabeticamente() {
    auto lambdaAlpha = [] (const auto &x, const auto &y) { return x.second < y.second; };
    sort(mDados.begin(), mDados.end(), lambdaAlpha);
}

vector<string> Dados::testeAutoComplete(string entrada) {
    vector<string> palavrasAutoComplete;
    int count = 0;
    for (auto i : mDados) {
        for (int j = 0; j < (int)i.second.size(); j++) {
            if (entrada[j] == i.second[j]) {
                count++;
                if (count == entrada.size()) {
                    palavrasAutoComplete.push_back(i.second);
                    break;
                }
            }
        }
        if (palavrasAutoComplete.size() == 4) {
            break;
        }
        count = 0;
    }
    return palavrasAutoComplete;
}

void Dados::findLowerAndUpperBound(string &entrada){
    int count = 0, c = 0;
    auto prc_info = lower_bound(mDados.begin(), mDados.end(), entrada,
                    [](pair<int, string> const & x, string d) { return x.second == d; });


    for (auto i : mDados) {
        c++;
        for (int j = 0; j < (int)entrada.size(); j++) {
            if (entrada[j] == i.second[j]) {
                count++;
                if (count == entrada.size()) {
                    cout << i.second << endl;
                    cout << c << endl;
                    break;
                }
            }
        }
        count = 0;
    }             
}

string Dados::recursive_binary_search(vector<string> vector, int begin, int end, string item){
    /* Índice representando o meio do sub-vetor begin->end */
    int i = (begin + end) / 2;

    if (begin > end) {  /* Ponto de parada. Item não está no vetor */
        return "Item não encontrado";
    }

    if (vector[i] == item) {  /* Item encontrado */
        return  "Achou " + vector[i];
    }

    if (vector[i] < item) {
        cout << "Direita" << endl;  /* Item está no sub-vetor à direita */
        cout << vector[i] << endl;
        return recursive_binary_search(vector, i + 1, end, item);

    } else {
        cout << "Esquerda" << endl;
        cout << vector[i] << endl;
        /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}    



















//  ******  Testes  *******  //////////////
void Dados::imprimirTeste() {
    int i = 0;
    while (i < 5) {
        cout << mDados[i].first << endl;
        cout << mDados[i].second << endl;
        i++;
    }
}