
#ifndef BIN_HPP
#define BIN_HPP

#include "Item.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Bin{
public:
    int id; // identificador
    int capacity; // capacidade
    int weight; // peso atual
    std::vector<Item> itens; // itens guardados na mochila

    Bin(int _id, int C, int N){
        this->id = _id;
        this->capacity = C;
        this->weight = 0;
    }

    Bin& operator=(const Bin &bin){
        if(this != &bin){
            this->id = bin.id;
            this->capacity = bin.capacity;
            this->weight = bin.weight;
            this->itens = bin.itens;
        }

        return *this;
    }

    ~Bin(){ }

    // adiciona item na mochia
    // retorna true se adicionou, false caso contrario
    bool addItem(Item item, vector<vector<bool> > *conflict){

        for(unsigned int j = 0; j < (*conflict).size(); j++){ // tem conflito?
            if((*conflict)[j][item.id] == true){
                for(unsigned int i = 0; i < this->itens.size(); i++){
                    if(this->itens[i].id == j){
                        return false;
                    }
                }
            }
        }
        if((item.weight + this->weight) > this->capacity){ // tem capacidade?
            return false;
        }

        this->itens.push_back(item);
        this->weight += item.weight;

        return true;
    }

    // remove item da mochia
    void removeItem(int i){
        this->weight -= this->itens[i].weight;
        this->itens.erase(this->itens.begin() + i);
    }
};

#endif
