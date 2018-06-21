
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "Bin.hpp"
#include "Solution.hpp"
#include "BestFit.hpp"
#include "FirstFit.hpp"

#define DBL_RND (((double)rand()) / (((double)RAND_MAX)+1.0))

int fitness(Solution* s){
    return s->bins.size();
}

int Delta(Solution *s_ ,Solution* s){
    return (fitness(s_) - fitness(s));
}

void swapSolutions(Solution *s1, Solution *s2){
    Solution auxiliar;

    auxiliar = *s1;
    *s1 = *s2;
    *s2 = auxiliar;
}

int SimulatedAnnealing(float temp_init, float temp_final, int SAMax, Solution *s){

    Solution s_,sStar;

	swapSolutions(&sStar,s);
	int iter = 0;

    while(temp_init < temp_final){
        while (iter < SAMax){
            iter = iter + 1;
			int index = rand()%s->bins.size();
            s_ = firstFit(s->bins[index].itens,s->bins[index].capacity);//Gera um vizinho qualquer

            if(Delta(&s_ , s) < 0){
                swapSolutions(s,&s_);
                if(fitness(&s_) < fitness(&sStar)){
                    swapSolutions(&sStar,&s_);
				}
				else{
					double x = DBL_RND;
					if(x < pow(M_E,(-1*Delta(&s_ , s))/temp_init)) swapSolutions(s,&s_);
				}
            }
        }
    }
}
