#ifndef Interface_hpp
#define Interface_hpp

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Interface{
    private:
        std::vector<std::string> mVetorComplete;
        std::vector<std::string> mVetorCorrect;

    public:
        Interface(std::vector<std::string> vetorComplete, std::vector<std::string> vetorCorrect);

        void imprimirSaida();
};

#endif