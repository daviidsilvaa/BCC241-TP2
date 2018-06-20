
#ifndef ITEM_HPP
#define ITEM_HPP

#include <vector>

class Item{
public:
    int id;
    int weight;
    std::vector<int> conflict;

    Item& operator=(const Item &item){
        if(this != &item){
            this->id = item.id;
            this->weight = item.weight;
            this->conflict = item.conflict;
        }

        return *this;
    }

    ~Item(){ }
};

#endif
