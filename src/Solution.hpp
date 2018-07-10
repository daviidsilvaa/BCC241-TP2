
#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "Bin.hpp"
#include <vector>
#include <fstream>
using namespace std;

class Solution{
public:
    int fo; // numero de mochilas
    vector<Bin> bins; // mochilas

    Solution(){
        this->fo = this->bins.size();
    }

    // adiciona mochila na solucao
    void addBin(Bin bin){
        this->bins.push_back(bin);
        this->fo = this->fo + 1;
    }

    // adiciona mochila da solucao
    void removeBin(int id){
        unsigned int i;

        for(i = 0; i < this->bins.size(); i++){
            if(id == this->bins[i].id){
                break;
            }
        }

        this->bins.erase(this->bins.begin() + i);
        this->fo = this->bins.size();
    }

    void print(){
        cout << this->fo << endl;
        for(unsigned int i = 0; i < this->bins.size(); i++){
            cout << this->bins[i].itens.size() << "\t";
            for(unsigned int j = 0; j < this->bins[i].itens.size(); j++){
                cout << this->bins[i].itens[j].id << "\t";
            }
            cout << endl;
        }
    }

    void mountFile(char *path){
        ofstream file;

        file.open(path);

        file << this->fo;
        file << endl;
        for(unsigned int i = 0; i < this->bins.size(); i++){
            file << this->bins[i].itens.size();
            file << " ";
            for(unsigned int j = 0; j < this->bins[i].itens.size(); j++){
                file << this->bins[i].itens[j].id;
                file << " ";
            }
            file << endl;
        }

        file.close();
    }
};

#endif
