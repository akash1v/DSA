#include<iostream>
using namespace std;

class MinHeap{
private:
    int* array;
    int size{};
    int no_of_values{};
    bool min{};
    
    void makeSpaceMinHeap();
    void siftupMin(int*, int);
    void siftupMax(int*, int);
    void siftdownMin(int*, int);
    void siftdownMax(int*, int);

public:
    MinHeap(){};
    MinHeap(int);
    void insert(int);
    int remove();
    void print();
    ~MinHeap();
};

MinHeap::MinHeap(int a){
    array = new int[a];
    size = a;
}

void MinHeap::makeSpaceMinHeap(){
    if(no_of_values == size){
        size++;
        int* new_array = new int[size];
        for(int i=0; i<no_of_values; i++){
            new_array[i] = array[i];
        }
        if(array){
            delete[] array;
        }
        array = new_array;
        new_array = nullptr;
    }
}

void MinHeap::insert(int data){
    makeSpaceMinHeap();
    if(no_of_values == 0){
        array[no_of_values] = data;
        no_of_values++;
    }
    else{
        array[no_of_values] = data;
        no_of_values++;
        siftupMin(array, no_of_values);
    }
}

int MinHeap::remove(){
    if(no_of_values > 0){
        int result = array[0];
        array[0] = array[no_of_values-1];
        no_of_values--;
        siftdownMin(array, no_of_values);
        return result;
    }
    return 0;
}

void MinHeap::print(){
    for(int i=0;i<no_of_values;i++){
        cout<<(array[i])<<" ";
    }
    printf("\n");
}

MinHeap::~MinHeap(){
    delete[] array;
}

void MinHeap::siftdownMin(int* array,int size){
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

void MinHeap::siftupMin(int* array, int size){
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


#include<iostream>
using namespace std;

class MaxHeap{
private:
    int* array;
    int size{};
    int no_of_values{};

    void makeSpaceMaxHeap();
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

MaxHeap::MaxHeap(int a){
    array = new int[a];
    size = a;
}

void MaxHeap::makeSpaceMaxHeap(){
    if(no_of_values == size){
        size++;
        int* new_array = new int[size];
        for(int i=0; i<size-1; i++){
            new_array[i] = array[i];
        }
        if(array){
            delete[] array;
        }
        array = new_array;
        new_array = nullptr;
    }
}

void MaxHeap::insert(int data){
    makeSpaceMaxHeap();
    if(no_of_values == 0){
        array[no_of_values] = data;
        no_of_values++;
    }
    else{
        array[no_of_values] = data;
        no_of_values++;
        siftup(array,no_of_values);
    }

}

int MaxHeap::remove(){
    if(no_of_values>0){
        int result = array[0];
        array[0] = array[no_of_values-1];
        no_of_values--;
        siftdown(array, no_of_values);
        return result;
    }
    return 0;
}

void MaxHeap::print(){
    for(int i=0;i<no_of_values;i++){
        cout<<(array[i])<<" ";
    }
    printf("\n");
}

MaxHeap::~MaxHeap(){
    delete[] array;
}

void MinHeap::siftupMax(int* array, int size){
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

void MinHeap::siftdownMax(int* array, int size){
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