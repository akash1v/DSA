#include"Swap.cpp"
template<typename t>
void bubbleSort(t * array, int size){
    for (int i = 1; i < size ; i++){
        for(int j = 0; j < size - i; j++){
            if(array[j] > array[j+1]){
                swap(array, j, j+1);
            }
        }
    }  
}