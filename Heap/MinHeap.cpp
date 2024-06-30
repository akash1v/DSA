#include<iostream>
#include"IncreaseArray.cpp"
using namespace std;

template<typename t>
class MinHeap{

private:
    t* array{};
    int size{};
    int no_of_values{};
    
    void siftup(int*, int);
    void siftdown(int*, int);

public:

    MinHeap(){};
    MinHeap(int);
    void insert(int);
    int remove();
    void print();
    ~MinHeap();
};

template<typename t>
MinHeap<t>::MinHeap(int a){
    array = new t[a];
    size = a;
}

template<typename t>
void MinHeap<t>::insert(int data){
    if(no_of_values == size){
        array = increaseArray(array,size);
        size++;
    }
    array[no_of_values] = data;
    no_of_values++;
    siftup(array, no_of_values);
}

template<typename t>
int MinHeap<t>::remove(){
    if(no_of_values == 0){    return 0;    }

    int result = array[0];
    array[0] = array[no_of_values-1];
    no_of_values--;
    siftdown(array, no_of_values);
    return result;
}


template<typename t>
void MinHeap<t>::print(){
    for(int i=0;i<no_of_values;i++){
        cout<<(array[i])<<" ";
    }
    printf("\n");
}

template<typename t>
MinHeap<t>::~MinHeap(){
    delete[] array;
}

template<typename t>
void MinHeap<t>::siftup(int* array, int size){
    int index = size-1;
    int parent = (index-1)/2;

    while(array[index]<array[parent]){
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;
            
        if(parent == 0){ break;}
        index = parent;
        parent = (index-1)/2;
    }
}

template<typename t>
void MinHeap<t>::siftdown(int* array,int size){
    int index = 0;
    int left = index*2 + 1;
    int right = index*2 + 2;

    while (left<size){
        if(array[index]>array[left] && array[index]>array[right]){
            if(array[right]<array[left]){
                int temp = array[right];
                array[right] = array[index];
                array[index] = temp;
                index = right;
            }
            else{
                int temp = array[left];
                array[left] = array[index];
                array[index] = temp;
                index = left;    
            }
        }
        else if(array[index]>array[left]){
            int temp = array[left];
            array[left] = array[index];
            array[index] = temp;
            index = left; 
        }
        else if(array[index]>array[right]){
            int temp = array[right];
            array[right] = array[index];
            array[index] = temp;
            index = right;
        }
        else{
            break;
        }
        left = index*2 + 1;
        right = index*2 + 2;
    }
}


template<typename t>
class MaxHeap{

private:
    t* array{};
    int size{};
    int no_of_values{};
    
    void siftup(int*, int);
    void siftdown(int*, int);

public:

    MaxHeap(){};
    MaxHeap(int);
    void insert(int);
    int remove();
    void print();
    ~MaxHeap();
};


template<typename t>
MaxHeap<t>::MaxHeap(int a){
    array = new t[a];
    size = a;
}

template<typename t>
void MaxHeap<t>::insert(int data){
    if(no_of_values == size){
        array = increaseArray(array,size);
        size++;
    }
    array[no_of_values] = data;
    no_of_values++;
    siftup(array, no_of_values);
}

template<typename t>
int MaxHeap<t>::remove(){
    if(no_of_values == 0){    return 0;    }
    
    int result = array[0];
    array[0] = array[no_of_values-1];
    no_of_values--;
    siftdown(array, no_of_values);
    return result;
}


template<typename t>
void MaxHeap<t>::print(){
    for(int i=0;i<no_of_values;i++){
        cout<<(array[i])<<" ";
    }
    printf("\n");
}

template<typename t>
MaxHeap<t>::~MaxHeap(){
    delete[] array;
}

template<typename t>
void MaxHeap<t>::siftup(int* array, int size){
    int index = size-1;
    int parent = (index-1)/2;

    while(array[index]>array[parent]){
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;
            
        if(parent == 0){ break;}
        index = parent;
        parent = (index-1)/2;
    }

}

template<typename t>
void MaxHeap<t>::siftdown(int* array, int size){
    int index = 0;
    int left = index*2 + 1;
    int right = index*2 + 2;
    while (left<size){
        if(array[index]<array[left] && array[index]<array[right]){
            if(array[right]>array[left]){
                int temp = array[right];
                array[right] = array[index];
                array[index] = temp;
                index = right;
            }
            else{
                int temp = array[left];
                array[left] = array[index];
                array[index] = temp;
                index = left;    
            }
        }
        else if(array[index]<array[left]){
            int temp = array[left];
            array[left] = array[index];
            array[index] = temp;
            index = left; 
        }
        else if(array[index]<array[right]){
            int temp = array[right];
            array[right] = array[index];
            array[index] = temp;
            index = right;
        }
        else{
            break;
        }
        left = index*2 + 1;
        right = index*2 + 2;
    }
}