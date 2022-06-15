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

        std::vector<std::string> getPalavras();

        void limparPalavras();
};

#endif