#ifndef Dados_hpp
#define Dados_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Dados {
   private:
    std::vector<std::string> mDadosCidades; // Vetor contendo dados de cidades
    std::vector<std::string> mDadosIngles; // Vetor contendo dados de palavras em inglês
    std::vector<std::string> mDadosPortugues; // Vetor contendo dados de palavras em português

   public:
   /**
    * @brief Construtor de uma nova classe contendo os dados e manipulações dos mesmos.
    * 
    * @param cidades Arquivo contendo dados de cidades
    * @param portugues Arquivo contendo dados de palavras em inglês
    * @param ingles Arquivo contendo dados de palavras em português
    */
    Dados(std::string cidades, std::string ingles, std::string portugues);

    /**
     * @brief Getter para o vetor contendo os dados das cidades.
     */
    std::vector<std::string> getDadosCidades();

    //  ******  Testes  *******  //////////////
    void ImprimirTeste();
};

#endif