#ifndef Dados_hpp
#define Dados_hpp

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include <sstream>
#include <cmath>

class Dados {
    private:
        std::string mArquivo; 
        std::vector<std::pair<long int, std::string>> mDados;  // Vetor de pares contendo peso e palavras.

    public:

        Dados(std::string dados);

        void verificarDados();

        void setDados();
        
        void ordenarAlfabeticamente();

        std::vector<std::string> getPalavrasComplet(std::string entrada);

        std::vector<std::string> getPalavrasCorrect(std::string entrada);

        void escreveVetorOrdenado();

        void findLowerBound(std::string &entrada);

        void imprimirTeste();
};

#endif