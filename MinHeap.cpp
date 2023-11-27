#include<iostream>
using namespace std;

class MinHeap{
private:
    int* array;
    int size{};
    int no_of_values{};

    void makeSpaceMinHeap();

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

void MinHeap::insert(int data){
    makeSpaceMinHeap();
    if(no_of_values == 0){
        array[no_of_values] = data;
        no_of_values++;
    }
    else{
        array[no_of_values] = data;
        no_of_values++;
        int index = no_of_values-1;
        int parent = 0;
        if(index%2 == 0){
            parent = (index - 2)/2;
        }
        else{
            parent = (index - 1)/2;
        };

        while(array[index]<array[parent]){
            int temp = array[index];
            array[index] = array[parent];
            array[parent] = temp;
            
            if(parent == 0){ break;}
            index = parent;
            
            if(index%2 == 0){ parent = (index - 2)/2;}
            else{ parent = (index - 1)/2;};
        }
    }
}

int MinHeap::remove(){
    int result = array[0];
    array[0] = array[no_of_values-1];
    no_of_values--;
    int index = 0;
    int left = index*2 + 1;
    int right = index*2 + 2;
    while (left<no_of_values){
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
    return result;
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