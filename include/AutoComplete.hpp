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
    public:
        AutoComplete();

        std::vector<std::string> autoComplete(std::string entrada, std::vector<std::pair<long int, std::string>> palavras);

        void autoCompleteTeste(std::string entrada, std::vector<std::pair<long int, std::string>> palavras);
};

#endif