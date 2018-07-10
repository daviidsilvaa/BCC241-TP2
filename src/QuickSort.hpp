
#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

void QuickSort(vector<Item> *itens, int low, int high){
    int i = low, j = high;
    int pivot = (*itens)[(i + j) / 2].weight;
    Item tmp;

		while(i <= j){
			while((*itens)[i].weight > pivot && i < high){
				i++;
			}
            while((*itens)[j].weight < pivot && j > low){
				j--;
			}

            if(i <= j){
                tmp = (*itens)[i];
                (*itens)[i] = (*itens)[j];
                (*itens)[j] = tmp;
                i++;
                j--;
            }
      };

      if (low < j)
            QuickSort(itens, low, j);
      if (i < high)
            QuickSort(itens, i, high);
}

#endif
