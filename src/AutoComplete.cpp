#include "AutoComplete.hpp"
using namespace std;

AutoComplete::AutoComplete(){}

std::vector<std::string> AutoComplete::getPalavras(){
    return palavrasAutoComplete;
}

void AutoComplete::limparPalavras(){
    palavrasAutoComplete.clear();
}