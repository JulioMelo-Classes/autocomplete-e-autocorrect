#ifndef AutoCorrect_hpp
#define AutoCorrect_hpp

#include "Dados.hpp"
#include <vector>
#include <string>
#include <algorithm>

class AutoCorrect{
    private:

    public:
        AutoCorrect();

        std::vector<std::string> autoCorrect(std::string entrada, std::vector<std::pair<long int, std::string>> palavras);

        int distEdicao(std::string entrada, int tamEntrada, std::string palavra, int tamPalavra);

};

#endif