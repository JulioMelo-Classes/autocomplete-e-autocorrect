#ifndef Dados_hpp
#define Dados_hpp

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Dados {
   private:
    std::vector<std::pair<unsigned long int, std::string>> mDados;  // Vetor de pares contendo peso e palavras.

   public:
    /**
     * @brief Construtor de uma nova classe contendo os dados e manipulações dos mesmos.
     *
     * @param cidades Arquivo contendo dados de cidades
     * @param portugues Arquivo contendo dados de palavras em inglês
     * @param ingles Arquivo contendo dados de palavras em português
     */
    Dados(std::string dados);

    /**
     * @brief Getter para o vetor contendo os dados das cidades.
     */
    std::vector<std::pair<unsigned long int, std::string>> getDados();

    /**
     * @brief Função para ordenar alfabeticamente o vetor de dados
     */
    void ordenarAlfabeticamente();

    std::vector<std::string> testeAutoComplete(std::string entrada);

    void findLowerAndUpperBound(std::string &entrada);

    std::string recursive_binary_search(std::vector<std::string> vector, int begin, int end, std::string item);

    void imprimirTeste();
};

#endif