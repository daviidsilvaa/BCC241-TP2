
#ifndef RANDOMCONSTRUCT_HPP
#define RANDOMCONSTRUCT_HPP

#include "Solution.hpp"
#include <vector>
using namespace std;


Solution randomConstruct(vector<Item> *itens, int N, int C, vector<vector<bool> > *conflict){
    srand(0);

    Solution solution = Solution();

    // adiciona mochila inicial na solucao
    solution.addBin(Bin(0, C, N));

    int itens_size = (*itens).size(); // captura quantidade de itens

    vector<Item> itens_copy = (*itens); // copia dos itens

    // coloca itens um por um
    for (unsigned int i = 0; i < itens_size; i++){
        bool added = false;

        int i_item = rand() % itens_copy.size();

        // coloca o item na primeira mochila possivel
        for(unsigned int j = 0; j < solution.bins.size(); j++){
            added = solution.bins[j].addItem(itens_copy[i], conflict);
            if(added){
                break;
            }
        }

        // se o item nao foi adicionado, abrimos uma nova mochila para ele
        if(!added){
            solution.addBin(Bin(solution.bins.size(), C, N));
            solution.bins[solution.bins.size() - 1].addItem(itens_copy[i], conflict);
        }

    }

    return solution;
}

#endif
