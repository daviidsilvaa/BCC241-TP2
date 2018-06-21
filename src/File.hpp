
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

Bin readInstanceFile(ifstream *in_file, int *N, int *C){
    Bin bin = Bin(0, *C, 0);
    vector<Item> itens;
    string line;

    getline(*in_file, line);

    int lf = line.find(" "), ls;

    *N = atoi(line.substr(0, lf).c_str());

    bin.conflict = vector< vector<int> >(*N);

    lf = line.find(" ");
    ls = line.size();

    *C = atoi(line.substr(lf, ls - 1).c_str());
    // cout << *N << "\t" << *C << endl;
    line.erase();

    Item item_tmp;

    for(int i = 0; i < *N; i++){
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

            // cout << aux - 1 << "\t";
            item_tmp.conflict.push_back(aux-1);

            line.erase(0, lf+1);
        }
        // cout << endl;

        bin.itens.push_back(item_tmp);

        for(unsigned int j = 0; j < item_tmp.conflict.size(); j++){
            bin.conflict[item_tmp.conflict[j]].push_back(item_tmp.id);
        }

        item_tmp.conflict.clear();
    }

    // cout << bin.weight << endl;

    return bin;
}
