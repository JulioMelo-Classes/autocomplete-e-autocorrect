#ifndef AutoCorrect_hpp
#define AutoCorrect_hpp

#include <algorithm>
#include <string>
#include <vector>

#include "Dados.hpp"

class AutoCorrect {
   private:
   public:
    /**
     * @brief Construtor vazio, utilizado apenas para gerar o objeto da classe.
     */
    AutoCorrect();

    /**
     * @brief Função principal do autoCorrect.
     * Calcula a distância de Edição chamando a função com esse mesmo nome, adiciona as palavras
     * e sua pontuação na Distância de Edição em um vetor e os ordena com a pontuação do menor para o maior.
     * @param entrada
     * @param palavras
     * @return Vetor contendo as palavras ordenadas pela pontuação da Distância de Edição.
     */
    std::vector<std::string> autoCorrect(std::string entrada, std::vector<std::pair<long int, std::string>> &palavras);

    /**
     * @brief Algoritmo de distância de edição utilizado dentro da função principal da classe.
     * @param entrada Palavra de entrada para o algoritmo.
     * @param tamEntrada Tamanho da palavra de entrada do algoritmo.
     * @param palavra Palavra que será testada de acordo com a distância de edição em relação a entrada.
     * @param tamPalavra Tamanho da palavra que será testada de acordo com a distância de edição em relação a entrada.
     * @return Pontuação do algoritmo de distãncia de edição.
     */
    int distEdicao(std::string entrada, int tamEntrada, std::string palavra, int tamPalavra);
};

#endif