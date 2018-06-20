
#ifndef BIN_HPP
#define BIN_HPP

#include "Item.hpp"
#include <vector>

class Bin{
public:
    int id; // identificador
    int capacity; // capacidade
    int weight; // peso atual
    std::vector<Item> itens; // itens guardados na mochila
    std::vector<std::vector<int> > conflict; // id's dos itens que nao podem estar aqui

    Bin(int id, int capacity, int weight){
        this->id = id;
        this->capacity = capacity;
        this->weight = weight;
    }

    Bin& operator=(const Bin &bin){
        if(this != &bin){
            this->id = bin.id;
            this->capacity = bin.capacity;
            this->weight = bin.weight;
            this->itens = bin.itens;
            this->conflict = bin.conflict;
        }

        return *this;
    }

    ~Bin(){ }

    // adiciona item na mochia
    // retorna true se adicionou, false caso contrario
    bool addItem(Item item){
        if(!(this->verifyConflict(item) || ((item.weight + this->weight) > capacity))){
            return false;
        }

        this->itens.push_back(item);
        this->weight += item.weight;

        for(int j = 0; j < item.conflict.size(); j++){
            this->conflict[item.conflict[j]].push_back(item.id);
        }

        return true;
    }

    // false caso nao tenha conflito
    bool verifyConflict(Item item){
        return !(conflict[item.id].size() == 0);
    }

    // remove item da mochia
    void removeItem(int i){
        for(int h = 0; h < this->itens[i].conflict.size(); h++){
            int i_conflict = -1;
            for(int j = 0; j < this->conflict[this->itens[i].conflict[h]].size(); j++){
                if(this->conflict[this->itens[i].conflict[h]][j] == i){
                    i_conflict = j;
                    break;
                }
            }
            if(i_conflict != -1){
                this->conflict[this->itens[i].conflict[h]].erase(this->conflict[this->itens[i].conflict[h]].begin() + i_conflict);
            }
        }

        this->weight -= this->itens[i].weight;
        this->itens.erase(this->itens.begin() + i);
    }
};

#endif
