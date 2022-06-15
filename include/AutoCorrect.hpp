#ifndef AutoCorrect_hpp
#define AutoCorrect_hpp

#include "Dados.hpp"
#include <vector>
#include <string>
#include <algorithm>

class AutoCorrect{
    private:
        std::vector<std::string> palavrasAutoCorrect;

    public:
        AutoCorrect();

        std::vector<std::string> getPalavras();

        void limparPalavras();
};

#endif