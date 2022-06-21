#ifndef Interface_hpp
#define Interface_hpp

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Interface {
   private:
    std::vector<std::string> mVetorComplete;  //>! Vetor contendo as palavras do autoComplete que irão ser exibidas.
    std::vector<std::string> mVetorCorrect;   //>! Vetor contendo as palavras do autoCorrect que irão ser exibidas.

   public:
    /**
     * @brief Construtor da classe que recebe as palavras do autoComplete e autoCorrect.
     * @param vetorComplete Vetor com as palavras do autoComplete.
     * @param vetorCorrect Vetor com as palavras do autoCorrect.
     */
    Interface(std::vector<std::string> vetorComplete, std::vector<std::string> vetorCorrect);

    /**
     * @brief Imprime todas as palavras contidas nos 2 atributos dessa classe (ordenadas por maior relevância).
     * Caso não contenha mais palavras em algum dos vetores, será imprimido um espaço vazio
     * até que o outro vetor seja imprimido por completo.
     */
    void imprimirSaida();
};

#endif