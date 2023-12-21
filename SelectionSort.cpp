#include"Swap.cpp"
void selectionSort(int* array,int size){
    for (int i = 0; i < size - 1; i++){
        int k = i;
        for (int j = i + 1; j < size; j++){
            if(array[j] < array[k]){
                k = j;
            }
        }
        swap(array, k, i);
    }
}