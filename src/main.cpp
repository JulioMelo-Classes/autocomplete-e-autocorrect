#include "Dados.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "--------------------------------------------------------------------" << endl;

    Dados dados(argv[1], argv[2], argv[3]);
    dados.ImprimirTeste();

   



    cout << "\n FIM DO CÓDIGO \n";
    return 0;
}