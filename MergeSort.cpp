#include"MergeSortedArray.cpp"
#include"Swap.cpp"
template<typename t>
void mergeSort(t* array,int size){

    if(size==1){ return; }
    
    if (size==2){
        if(array[0]<=array[1]){    return;    }
        
        swap(array,0,1);
        return;
    }

    int f_size = size / 2;
    int e_size = size - f_size;

    t f_half[f_size];
    t e_half[e_size];

    int i = 0;
    for (int i; i < f_size; i++){
        f_half[i] = array[i];
    };

    for(int i; i < size; i++){
        e_half[i-f_size] = array[i];
    }

    mergeSort(f_half,f_size);
    mergeSort(e_half,e_size);        

    delete[] array;
    array = mergeSortedArray(f_half,f_size,e_half,e_size);    

    delete[] f_half;
    delete[] e_half;
    return;
}