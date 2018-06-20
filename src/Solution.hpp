
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "Bin.hpp"
#include <vector>

class Solution{
public:
    int fo; // numero de mochilas
    std::vector<Bin> bins; // mochilas

    Solution(){
        this->fo = this->bins.size();
    }

    // adiciona mochila na solucao
    void addBin(Bin bin){
        this->bins.push_back(bin);
        this->fo = this->bins.size();
    }

    // adiciona mochila da solucao
    void removeBin(int id){
        int i;

        for(i = 0; i < this->bins.size(); i++){
            if(id = this->bins[i].id){
                break;
            }
        }

        this->bins.erase(this->bins.begin() + i);
        this->fo = this->bins.size();
    }
};

#endif
