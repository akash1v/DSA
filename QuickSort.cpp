#include"Swap.cpp"
template<typename t>
void quickSort(t* array, int l, int h){

    if(h - l < 1){    return;    }

    int m = l;

    for(int i = l; i <= h; i++){
        if(array[i] < array[h]){
            swap(array, m, i);
            m++;
        }
    }
    swap(array, m, h);
    quickSort(array, l, m-1);
    quickSort(array, m+1, h);
}

template<typename t>
void quickSort(t* array, int size){
    quickSort(array, 0, size - 1);
}