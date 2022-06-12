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
        std::vector<std::string> testeAutoComplete(std::string entrada, std::vector<std::pair<long int, std::string>> mDados);
};

#endif