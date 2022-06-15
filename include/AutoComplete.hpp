#ifndef AutoComplete_hpp
#define AutoComplete_hpp

#include "Dados.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class AutoComplete {
    private:
        std::vector<std::string> palavrasAutoComplete;

    public:
        AutoComplete();

        void autoComplete(std::string entrada, std::vector<std::pair<long int, std::string>> palavras);

        void autoCompleteTeste(std::string entrada, std::vector<std::pair<long int, std::string>> palavras);

        std::vector<std::string> getPalavras();

        void limparPalavras();
};

#endif