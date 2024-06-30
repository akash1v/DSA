#include"MergeSortedArray.cpp"
#include"Swap.cpp"
template<typename t>
void mergeSort(t* array,int size){

    if(size==1){ return; }

    int f_size = size / 2;
    int e_size = size - f_size;

    t f_half[f_size];
    t e_half[e_size];

    for (int i = 0; i < f_size; i++){
        f_half[i] = array[i];
    };

    for(int i = f_size; i < size; i++){
        e_half[i-f_size] = array[i];
    }

    mergeSort(f_half,f_size);
    mergeSort(e_half,e_size);        
    mergeSortedArray(array,f_half,f_size,e_half,e_size);    
    return;
}