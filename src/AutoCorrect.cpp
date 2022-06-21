#include "AutoCorrect.hpp"

using namespace std;

AutoCorrect::AutoCorrect() {}

vector<string> AutoCorrect::autoCorrect(string entrada, vector<pair<long int, string>> palavras) {
    vector<pair<string, int>> palavrasDistancia;
    vector<string> palavrasAutoCorrect;

    sort(palavras.begin(), palavras.end(),  // Ordena pelo peso (maior para o menor).
         [](const auto &x, const auto &y) { return x.first > y.first; });

    for (auto i : palavras) {
        int distancia = distEdicao(entrada, entrada.size(), i.second, i.second.size());  // Calcula a distância de edição.
        palavrasDistancia.push_back(make_pair(i.second, distancia));                     // Cria um par <palavra, dist. de edição>.
    }

    sort(palavrasDistancia.begin(), palavrasDistancia.end(),  // Ordena pela distância de edição (menor para o maior).
         [](const auto &x, const auto &y) { return x.second < y.second; });

    for (int i = 0; i < 5; i++) {
        if (i == palavrasDistancia.size() - 1) {
            break;
        }
        palavrasAutoCorrect.push_back(palavrasDistancia[i].first);
    }

    return palavrasAutoCorrect;
}

int AutoCorrect::distEdicao(string entrada, int tamEntrada, string palavra, int tamPalavra) {
    if (tamEntrada == 0) {
        return tamPalavra;
    }

    if (tamPalavra == 0) {
        return tamEntrada;
    }

    int count;

    if (entrada[tamEntrada - 1] == palavra[tamPalavra - 1]) {
        count = 0;
    } else {
        count = 1;
    }

    return min(min(distEdicao(entrada, tamEntrada - 1, palavra, tamPalavra) + 1,       // exclusão
                   distEdicao(entrada, tamEntrada, palavra, tamPalavra - 1) + 1),      // inserção
               distEdicao(entrada, tamEntrada - 1, palavra, tamPalavra - 1) + count);  // substituição
}
