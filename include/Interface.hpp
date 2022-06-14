#ifndef Interface_hpp
#define Interface_hpp

#include <vector>
#include <string>
#include <iostream>

class Interface{
    private:
        std::pair<std::vector<std::string>, std::vector<std::string>> mVetores;

    public:
        Interface(std::vector<std::string> vetorComplete, std::vector<std::string> vetorCorrect);

        std::pair<std::vector<std::string>, std::vector<std::string>> getPar();

        void imprimirSaida();

        void limparPar();
};

#endif