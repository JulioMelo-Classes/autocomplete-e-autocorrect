#ifndef Dados_hpp
#define Dados_hpp

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Dados {
   private:
    std::string mArquivo;                                  //<! Variável contendo o arquivo de dados.
    std::vector<std::pair<long int, std::string>> mDados;  //<! Vetor de pares contendo pesos e palavras do arquivo lido.

   public:
    /**
     * @brief Construtor da classe.
     * @param dados Arquivo contendo o conteúdo a ser utilizado no programa.
     */
    Dados(std::string dados);

    /**
     * @brief Abre o arquivo e percorre o mesmo afim de procurar um erro de entrada
     * definido no programa. Caso encontre irá encerrar o programa e mostrar o erro respectivo.
     */
    void verificarDados();

    /**
     * @brief Abre o arquivo e conforme lê registra os dados no mDados, tanto para
     * peso como palavra em seu respectivo lugar no vetor de pares.
     */
    void setDados();

    /**
     * @brief Ordena o vetor mDados alfabeticamente usando uma função lambda junto do std::sort.
     */
    void ordenarAlfabeticamente();

    /**
     * @brief Filtra as palavras de acordo com as funções upper_bound() e lower_bound().
     * Utiliza esse "recorte" do código e adiciona em um vetor com esses valores.
     * @param entrada
     * @return Retorna o vetor de pares com os pesos e palavras que atendem as condições.
     */
    std::vector<std::pair<long int, std::string>> getPalavrasComplete(std::string entrada);

    /**
     * @brief Filtra as palavras que são maiores que 2, que tem o mesmo tamanho de caracteres
     * da entrada e o tamanho da entrada +1.
     * @param entrada Entrada do usuário usada para buscar outras palavras do autoCorrect.
     * @return Retorna o vetor de pares com os pesos e palavras que atendem as condições.
     */
    std::vector<std::pair<long int, std::string>> getPalavrasCorrect(std::string entrada);

    void escreveVetorOrdenado();

    /**
     * @brief Limpa os valores do vetor.
     * @param vetor Vetor que será limpo.
     */
    void limparVetor(std::vector<std::string> vetor);

    /**
     * @brief Limpa os valores do vetor.
     * @param vetor Vetor de pares <long int, string> que será limpo.
     */
    void limparVetor(std::vector<std::pair<long int, std::string>> vetor);
};

#endif