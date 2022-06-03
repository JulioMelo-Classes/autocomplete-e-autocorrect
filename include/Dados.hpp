#ifndef Dados_hpp
#define Dados_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Dados {
   private:
    std::vector<std::pair<unsigned long int, std::string>> mDados;  // Vetor contendo dados de peso e palavras


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


    //  ******  Testes  *******  //////////////
    //  ******  Testes  *******  //////////////
    void imprimirTeste();
    void testeAutoComplete(std::string entrada) {
        std::vector<std::string> palavrasAutoComplete;
        int count = 0;
        for (auto i : mDados) {
            for (int j = 0; j < i.second.size(); j++) {
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
        if (palavrasAutoComplete.size() == 0) {
            std::cout << "Nenhuma palavra com esse prefixo" << std::endl;
        } else {
            for (auto i : palavrasAutoComplete) {
                std::cout << i << std::endl;
            }
        }
    }
};

#endif