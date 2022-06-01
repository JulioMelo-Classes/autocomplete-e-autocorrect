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
    Dados(std::string cidades) {
        std::string linha; 
        std::ifstream arquivo;
        arquivo.open(cidades.c_str());
        while (!arquivo.eof()) {
            getline(arquivo, linha);
            mDadosCidades.push_back(std::string(linha));
        }
        arquivo.close();
    }

    void ImprimirTeste() {
        int i = 0;
        while (i < 4) {
            std::cout << mDadosCidades[i] << std::endl;
            i++;
        }
    }
    /**
     * @brief Getter para o vetor contendo os dados das cidades.
     */
    std::vector<std::string> getDadosCidades() { return mDadosCidades; }
};

#endif