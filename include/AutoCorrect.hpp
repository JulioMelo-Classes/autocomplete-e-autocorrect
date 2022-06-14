#ifndef AutoCorrect_hpp
#define AutoCorrect_hpp

#include <vector>
#include <string>
#include <algorithm>

class AutoCorrect{
    private:
        std::vector<std::string> palavrasAutoCorrect;

    public:
        AutoCorrect();

        void setPalavras(std::string entrada, std::vector<std::pair<long int, std::string>> mDados);

        std::vector<std::string> getPalavras();

        void limparPalavras();
};

#endif