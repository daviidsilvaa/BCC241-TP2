
#include "Bin.hpp"
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int lFind(string str){
    if(str.find(" ") > str.size()){
        return str.size();
    }

    return str.find(" ");
}

Bin readInstanceFile(ifstream *in_file, int *N, int *C, vector<vector<bool> > *conflict){
    Bin bin = Bin(0, *C, 0);
    vector<Item> itens;
    string line;

    getline(*in_file, line);

    int lf = line.find(" "), ls;

    *N = atoi(line.substr(0, lf).c_str());

    // instancia matriz de conflito
    (*conflict) = vector<vector<bool> >(*N);
    for(unsigned int i = 0; i < *N; i++){
        (*conflict)[i] = vector<bool>(*N);
    }

    for(unsigned int i = 0; i < *N; i++){
        for(unsigned int j = 0; j < *N; j++){
            (*conflict)[i][j] = false;
        }
    }

    lf = line.find(" ");
    ls = line.size();

    *C = atoi(line.substr(lf, ls - 1).c_str());
    line.erase();

    Item item_tmp;

    for(unsigned int i = 0; i < *N; i++){
        // recebe a linha do item
        getline(*in_file, line);

        lf = lFind(line);
        item_tmp.id = atoi(line.substr(0, lf+1).c_str()) - 1;
        line.erase(0, lf+1);

        lf = lFind(line);
        item_tmp.weight = atoi(line.substr(0, lf+1).c_str());
        line.erase(0, lf+1);

        // cout << item_tmp.id << "\t" << item_tmp.weight << "\t";

        while(!line.empty()){
            lf = lFind(line);
            int aux = atoi(line.substr(0, lf).c_str());

            (*conflict)[i][(aux-1)] = true;
            (*conflict)[(aux-1)][i] = true;

            line.erase(0, lf+1);
        }

        bin.itens.push_back(item_tmp);
    }

    return bin;
}
