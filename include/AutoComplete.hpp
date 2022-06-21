#ifndef AutoComplete_hpp
#define AutoComplete_hpp

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Dados.hpp"

class AutoComplete {
   public:
    /**
     * @brief Construtor vazio, utilizado apenas para gerar o objeto da classe.
     */
    AutoComplete();

    /**
     * @brief Função que ordena as palavras filtradas pelo upper_bound e lower_bound de acordo
     * com as palavras que contém o maior peso até o menor peso.
     * @param palavras Vetor de pesos e palavras filtradas pelo upper_bound e lower_bound.
     * @return Vetor de pares contendo as palavras em ordenação decrescente pelo peso.
     */
    std::vector<std::string> autoComplete(std::vector<std::pair<long int, std::string>> palavras);
};

#endif