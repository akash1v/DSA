#include"MergeSortedArray.cpp"
int medianOfSortedArray(int* a, int a_s, int* b, int b_s){
    int* temp = mergeSortedArray(a, a_s, b, b_s);
    int k = (temp[0] + temp[a_s + b_s - 1])/2;
    delete[] temp;
    return k;
}