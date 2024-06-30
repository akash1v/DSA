#include"MinHeap.cpp"
template<typename t>
void heapSort(t* array, int size){
    MinHeap<t> h(size);
    for (int i = 0; i < size; i++){
        h.insert(array[i]);
    }

    for (int i = 0; i < size; i++){
        array[i] = h.remove();
    }
    
}