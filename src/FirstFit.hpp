
#ifndef FIRSTFIT_HPP
#define FIRSTFIT_HPP

#include "Solution.hpp"
#include "QuickSort.hpp"
#include <vector>
using namespace std;

// algoritmo de Proxima Melhora
Solution firstFit(vector<Item> *itens, int N, int C, vector<vector<bool> > *conflict){
    Solution solution = Solution();

    // adiciona mochila inicial na solucao
    solution.addBin(Bin(0, C, N));
    solution.addBin(Bin(1, C, N));

    int itens_size = (*itens).size(); // captura quantidade de itens

    // estrutura que armazena pesos da forma maior para menor
    vector<Item> itens_ordered = (*itens);

    QuickSort(&itens_ordered, 0, itens_ordered.size()-1);

    // coloca itens um por um
    for (unsigned int i = 0; i < itens_size; i++){
        bool added = false;

        // coloca o item na primeira mochila possivel
        for(unsigned int j = 0; j < solution.bins.size(); j++){
            added = solution.bins[j].addItem(itens_ordered[i], conflict);
            if(added){
                break;
            }
        }

        // se o item nao foi adicionado, abrimos uma nova mochila para ele
        if(!added){
            solution.addBin(Bin(solution.bins.size(), C, N));
            solution.bins[solution.bins.size() - 1].addItem(itens_ordered[i], conflict);
        }

    }

    return solution;
}

#endif
