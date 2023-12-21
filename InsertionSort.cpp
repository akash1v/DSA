#include"Swap.cpp"
void insertionSort(int * array, int size){
    for (int i = 1; i < size; i++){
        for (int j = i; j > 0; j--){
            if (array[j] < array[j-1]){
                swap(array, j, j-1);
            }
            else{
                break;
            }          
        }       
    }
}