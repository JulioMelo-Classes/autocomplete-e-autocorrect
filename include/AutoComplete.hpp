#ifndef AutoComplete_hpp
#define AutoComplete_hpp

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
        void setPalavras(std::string entrada, std::vector<std::pair<long int, std::string>> mDados);

        std::vector<std::string> getPalavras();

        void limparPalavras();
};

#endif