
#include "File.hpp"
#include "Bin.hpp"
#include "Solution.hpp"
#include <iostream>
#include <fstream>
// #include "FirstFit.hpp"
#include "BestFit.hpp"
using namespace std;



int main(int argc, char **argv){
    int N, C;
    ifstream in_file;

    in_file.open(argv[1]);

    // le arquivo de entrada
    Bin all_itens = readInstanceFile(&in_file, &N, &C);

    // monta solucao inicial
    // Solution s1 = bestFit(all_itens, C);

    in_file.close();

    return 0;
}
