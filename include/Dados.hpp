#ifndef Dados_hpp
#define Dados_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Dados {
   private:
    std::vector<std::string> mDadosCidades;

   public:
   /**
    * @brief Construtor de uma nova classe contendo os dados e manipulações dos mesmos.
    * @param cidades Arquivo contendo dados de cidades.
    */
    Dados(std::string cidades);

    /**
     * @brief Getter para o vetor contendo os dados das cidades.
     */
    std::vector<std::string> getDadosCidades();

    //  ******  Testes  *******  //////////////
    void ImprimirTeste();
};

#endif