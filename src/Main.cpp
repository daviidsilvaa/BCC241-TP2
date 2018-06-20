
#include "Bin.hpp"
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "FirstFit.hpp"
#include "BestFit.hpp"
using namespace std;

int ReadInstanceFile(ifstream *in_file, int *N, int *C){
    Bin bin = Bin(0, *C, 0);
    vector<Item> itens;
    string line;
    int i_;

    getline(*in_file, line);

    *N = atoi(line.substr(0, line.find(" ")).c_str());
    bin.conflict = vector< vector<int> >(*N);

    *C = atoi(line.substr(line.find(" "), line.size() - 1).c_str());

    Item item_tmp;
    int i_tmp;

    for(int i = 0; i < *N; i++){
        // recebe a linha do item
        getline(*in_file, line);

        item_tmp.id = atoi(line.substr(0, line.find(" ")).c_str());
        line.erase(0, line.find(" ")+1);
        item_tmp.weight = atoi(line.substr(0, line.find(" ")).c_str());
        line.erase(0, line.find(" ")+1);

        while(!line.empty()){
            // cout << line.size()<<endl;
            item_tmp.conflict.push_back(atoi(line.substr(0, line.find(" ")).c_str()));

            int aux;
             if(line.find("\0")< line.find(" "))
                aux = line.find("\0");
            else
                aux = line.find(" ");

            line.erase(0, aux+1);
        }

        bin.itens.push_back(item_tmp);

        for(int j = 0; j < item_tmp.conflict.size(); j++){
            bin.conflict[item_tmp.conflict[j]].push_back(item_tmp.id);
        }

        item_tmp.conflict.clear();
    }

    cout << bin.itens[*N-1].id << bin.itens[*N-1].weight << endl;
}

int main(int argc, char **argv){
    int N, C;
    ifstream in_file;

    in_file.open(argv[1]);

    ReadInstanceFile(&in_file, &N, &C);

    in_file.close();

    return 0;
}
