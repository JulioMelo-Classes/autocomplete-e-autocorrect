#include "Dados.hpp"
using namespace std;

Dados::Dados(string dados) {
    string linha;
    ifstream arquivo;
    int c_linha1 = 0, c_linha2 = 0;

    arquivo.open(dados.c_str());

    while (!arquivo.eof()) {
        c_linha1++;

        //Verifica se o arquivo existe/está aberto.
        if (arquivo.is_open() == false){
            cout << "Erro! Arquivo inexistente." << endl;
            exit(-1);
        }
        
        //Verifica se a palavra tem um peso correspondente ou se o arquivo está vazio.
        try{
            getline(arquivo, linha, ' ');
            long int peso = stol(linha);
            getline(arquivo, linha, '\n');
            linha.erase(linha.size() - 1);
            mDados.push_back(make_pair(peso, linha));
        }catch(...){
            cout << "Erro! Peso inexistente na linha " + to_string(c_linha1) + " ou arquivo \"" + dados + "\" vazio." << endl;
            exit(-1);
        } 
    }

    arquivo.close();
    
    for (auto item : mDados){
        c_linha2++;

        //Verifica se o peso é negativo.
        if (item.first > pow(100,5)){
            cout << "Erro! Peso negativo relacionado a palavra \"" + item.second +  "\"." << endl;
            exit(-1);
        }

        //Verifica se a palavra está vazia.
        if (item.second.empty()){
            cout << "Erro! Palavra vazia na linha " + to_string(c_linha2) + "." << endl;
            exit(-1);
        }
    }
}

vector<pair<long int, string>> Dados::getDados() {
    return mDados;
}

void Dados::ordenarAlfabeticamente() {
    auto lambdaAlpha = [](const auto &x, const auto &y) { return x.second < y.second; };
    sort(mDados.begin(), mDados.end(), lambdaAlpha);
}

void Dados::escreveVetorOrdenado(){
    fstream arquivo;
    arquivo.open("../data/a.txt", ios::app);
    for (auto i : mDados){
        arquivo << i.first << " " << i.second << '\n';
    }
    arquivo.close();
}

string Dados::recursive_binary_search(vector<string> vector, int begin, int end, string item) {
    /* Índice representando o meio do sub-vetor begin->end */
    int i = (begin + end) / 2;

    if (begin > end) { /* Ponto de parada. Item não está no vetor */
        return "Item não encontrado";
    }

    if (vector[i] == item) { /* Item encontrado */
        return "Achou " + vector[i];
    }

    if (vector[i] < item) {
        cout << "Direita" << endl; /* Item está no sub-vetor à direita */
        cout << vector[i] << endl;
        return recursive_binary_search(vector, i + 1, end, item);

    } else {
        cout << "Esquerda" << endl;
        cout << vector[i] << endl;
        /* vector[i] > item. Item está no sub-vetor à esquerda */
        return recursive_binary_search(vector, begin, i - 1, item);
    }
}

void Dados::imprimirTeste() {
    int i = 0;
    while (i < 5) {
        cout << "Numero: " << mDados[i].first << endl;

        cout << "Palavra: "
             << ">> " << mDados[i].second << " <<"
             << " tamanho palavra: " << mDados[i].second.size() << endl;
        i++;
    }
}

void Dados::findLowerBound(string &entrada){
    vector<string> palavras;
    pair<long int, string> par;
    int c_1 = 0;
    
    for (auto i : mDados) {
        palavras.push_back(i.second);
        //cout << i.first << " " << i.second << endl;
        for (int j = 0; j < (int)entrada.size(); j++) {
            if (entrada[j] == i.second[j]) {
                c_1++;
                if (c_1 == entrada.size()) {
                    par.first = i.first;
                    par.second = i.second;
                    break;
                }
            }
        }
        c_1 = 0;
    }



    //cout << par.first << " " << par.second << endl;
    auto low = lower_bound(mDados.begin(), mDados.end(), par,
                                [](const auto &x, const auto &y) { return x.second < y.second; });
    
    //cout << low - mDados.begin() << endl;

    auto up = upper_bound(mDados.begin(), mDados.end(), par,
                                [](const auto &x, const auto &y) { return x.second < y.second; });
    
    //cout << up - mDados.begin() << endl;
}
