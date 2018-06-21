
// recebe duas mochilas e troca itens entre elas
bool moveItem(Bin *b1, Bin *b2){
    bool moved = false;

    srand(0);
    bool done = false;
    int i = 0;

    // enquanto a troca for invalida
    while (!done){
        int i_item = rand() % b1->itens.size();

        if(b2->capacity <= (b2->weight + b1->itens[i_item].weight)){
            b2->addItem(b1->itens[i_item]);
            b1->removeItem(i_item);

            done = true;
            moved = true;
        }

        // evita que entre em loop infinito
        if(i > 2*b1->itens.size() || i > 2*b2->itens.size()){
            done = true;
        }
    }

    return moved;
}

bool moveNItens(){
    
}

bool unifyBins(vector<Bin> *bins){
    int bin1, bin2;
    if(bins->size() > 2){
        bin1 = 0;
        bin2 = 1;
    } else{
        return false;
    }

    // define mochila de menor peso como sendo a de i bin1
    if(bins[bin1]->weight > bins[bin2]->weight){
        bin1 = 1;
        bin2 = 0;
    }

    for(int i = 2; i < bins->size(); i++){
        if(bins[i]->weight < bins[bin2]){
            if(bins[i]->weight < bins[bin1]){
                bin2 = bin1;
                bin1 = i;
            } else {
                bin2 = i;
            }
        }
    }

    // verifica se a duas menores podem compor uma unica
    if(bins[bin1]->weight + bins[bin2]->weight <= bins[bin1]->capacity){
        for(int i = 0; i < bins[bin2]->itens.size(); i++){
            bins[bin1]->addItem(bins[bin2]->itens[i]);
        }

        bins->erase(bins->begin() + bin2);

        return true;
    }

    return false;
}
