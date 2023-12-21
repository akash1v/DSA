#include"MergeSortedArray.cpp"
#include"Swap.cpp"
void mergeSort(int* array,int size){

    if(size==1){ return; }
    
    if (size==2){
        if(array[0]<=array[1]){    return;    }
        
        swap(array,0,1);
        return;
    }

    int e_size = size / 2;
    int f_size = size - e_size;

    int f_half[f_size];
    int e_half[e_size];

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