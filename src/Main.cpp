
#include "File.hpp"
#include "Bin.hpp"
#include "Solution.hpp"
#include <iostream>
#include <fstream>
#include "FirstFit.hpp"
#include "Time.hpp"
using namespace std;

int main(int argc, char **argv){
    int N, C;
    ifstream in_file;
    Time time = Time();

    in_file.open(argv[1]);

    vector<vector<bool> > conflict;

    // le arquivo de entrada
    Bin all_itens = readInstanceFile(&in_file, &N, &C, &conflict);

    time.getInit(); // obtem tempo inicial

    // monta solucao inicial
    Solution s1 = firstFit(&(all_itens.itens), N, C, &conflict);

    // cout << "Tempo total gasto: " << time_span2.count() << "s" << endl;

    time.getFinish();  // obtem tempo final
    time.mountFile(argv[2]); // monta arquivo de saida relativo ao tempo

    s1.mountFile(argv[2]);

    in_file.close();

    return 0;
}
