#include "AutoCorrect.hpp"

using namespace std;

AutoCorrect::AutoCorrect(){}

std::vector<std::string> AutoCorrect::getPalavras(){
    return palavrasAutoCorrect;
}

void AutoCorrect::limparPalavras(){
    palavrasAutoCorrect.clear();
}
