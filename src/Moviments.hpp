
#ifndef MOVIMENTS_HPP
#define MOVIMENTS_HPP

// recebe duas mochilas e troca itens entre elas
void moveItem(Bin *b1, Bin *b2){
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
        }

        // evita que entre em loop infinito
        if(i > 2*b1->itens.size() || i > 2*b2->itens.size()){
            done = true;
        }
    }
}

#endif
