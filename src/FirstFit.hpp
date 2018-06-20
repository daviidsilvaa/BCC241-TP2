
#include "Solution.hpp"
#include <vector>
using namespace std;

// algoritmo de Proxima Melhora
Solution firstFit(vector<Item> itens, int C){
    Solution solution = Solution();

    // adiciona mochila inicial na solucao
    solution.addBin(Bin(0, C, 0));

    int itens_size = itens.size(); // captura quantidade de itens

    // coloca itens um por um
    for (int i = 0; i < itens_size; i++){
        bool added = false;
        // elege um item aleatorio
        int i_item = rand() % itens.size();

        // coloca o item na primeira mochila possivel
        for(int i = 0; i < solution.bins.size() || (added == false); i++){
            added = solution.bins[i].addItem(itens[i_item]);
        }

        // se o item nao foi adicionado, abrimos uma nova mochila para ele
        if(!added){
            solution.addBin(Bin(solution.bins.size(), C, 0));
            solution.bins[solution.bins.size() - 1].addItem(itens[i_item]);
        }
    }

    return solution;
}
