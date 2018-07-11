
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "Bin.hpp"
#include "Solution.hpp"
// #include "BestFit.hpp"
#include "FirstFit.hpp"
#include "Moviments.hpp"
#include <iostream>
using namespace std;

#define DBL_RND (((double)rand()) / (((double)RAND_MAX)+1.0))

int fitness(Solution* s){
    return s->bins.size();
}

int Delta(Solution *s1 ,Solution* s){
    return (fitness(s1) - fitness(s));
}

void swapSolutions(Solution *s1, Solution *s2){
    Solution auxiliar;

    auxiliar = *s1;
    *s1 = *s2;
    *s2 = auxiliar;
}

Solution SimulatedAnnealing(float temp_init, float alpha, int SAMax, Solution *solution, vector<vector<bool> > *conflict){
    Solution s1, s_star;
    float temp_now = temp_init;

    s_star = s1 = (*solution);

    int iter = 0;
    while(temp_now > 10){
        // cout << "A";
        while (iter < SAMax){
            iter = iter + 1;
            // cout << __FILE__ << "\t" << __LINE__ << "\t" << endl;

            if(moveItem(&s1, conflict)){
                s1.updateFO();
            }
            // cout << __FILE__ << "\t" << __LINE__ << "\t" << endl;

            if(Delta(solution, &s1) < 0){
                (*solution) = s1;
                if(s1.fo < s_star.fo){
                    s_star = s1;
				}
				else{
					double x = DBL_RND;
					if(x < pow(M_E,(-1*Delta(&s1 , solution))/temp_init)){
                        (*solution) = s1;
                    }
				}
            }
        }
        temp_now = temp_now * alpha;
    }

    return s_star;
}
