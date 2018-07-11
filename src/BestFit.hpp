
#ifndef BESTFIT_HPP
#define BESTFIT_HPP

#include "Solution.hpp"
#include <vector>
using namespace std;

    // ! NAO FUNCIONA ! //
    // ! NAO FUNCIONA ! //
    // ! NAO FUNCIONA ! //

// algoritmo de Melhor Melhora
Solution bestFit(Bin bin, int C){
    Solution solution = Solution();

    // adiciona mochila inicial na solucao
    solution.addBin(Bin(0, C, 0));

    int itens_size = bin.itens.size(); // captura quantidade de itens

    std::vector<int> tighests;

    // coloca itens um por um
    for (int i = 0; i < itens_size; i++){
        bool added = false, added_tighest = false;

        // elege um item aleatorio
        int i_item = rand() % bin.itens.size();

        // coloca o item na mochila mais leve
        for(unsigned int attempts = 0; (attempts < solution.bins.size()) || (added == false); attempts++){
            int tighest = 0;
            for(unsigned int i = 1; i < solution.bins.size(); i++){
                if(solution.bins[i].weight < solution.bins[tighest].weight){
                    tighest = i;
                }
            }

            for(unsigned int j = 0; j < tighests.size(); j++){
                if(tighests[j] == tighest){
                    added_tighest = true;
                } else{
                    added_tighest = false;
                }
            }

            if(added_tighest == false){
                added = solution.bins[tighest].addItem(bin.itens[i_item]);
            }
        }

        // se o item nao foi adicionado, abrimos uma nova mochila para ele
        if(!added){
            solution.addBin(Bin(solution.bins.size(), C, 0));
            solution.bins[solution.bins.size() - 1].addItem(bin.itens[i_item]);
        }
    }

    return solution;
}

#endif
