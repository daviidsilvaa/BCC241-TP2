
#include "File.hpp"
#include "Bin.hpp"
#include "Solution.hpp"
#include <iostream>
#include <fstream>
#include "FirstFit.hpp"
#include "SimulatedAnnealing.hpp"
#include "RandomConstruct.hpp"
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


    // constroi solucao inicial com heuristica gulosa e estrategia firstFit
    // Solution s1 = firstFit(&(all_itens.itens), N, C, &conflict);

    // constroi solucao inicial aleatoria
    Solution s2 = randomConstruct(&(all_itens.itens), N, C, &conflict);

    time.getInit(); // obtem tempo inicial

    // Solution s3 = SimulatedAnnealing(100, 0.97, s2.bins.size(), &s2, &conflict);

    time.getFinish();  // obtem tempo final

    // cout << s3.fo << endl;

    // time.mountFile(argv[2]); // monta arquivo de saida relativo ao tempo
    time.mountFile(argv[2], &s2); // monta arquivo de saida relativo ao tempo

    // s1.mountFile(argv[2]);
    // s2.mountFile(argv[2]);

    in_file.close();

    return 0;
}
