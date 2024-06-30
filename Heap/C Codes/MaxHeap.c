#include<stdio.h>
#include<stdlib.h>

struct MaxHeap{
    int* array;
    int size;
    int no_of_values;
};

struct MaxHeap* getMaxHeap(int size){
    struct MaxHeap* temp = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    int* array = (int*)malloc(sizeof(int)*size);
    temp->array = array;
    array = NULL;
    temp->size = size;
    temp->no_of_values = 0;
    return temp;
}

void makespace(struct MaxHeap* ptr){
    if(ptr->no_of_values < ptr->size){
        return;
    }
    ptr->size++;
    int* new_array = (int*)malloc(ptr->size*sizeof(int));
    for(int i=0;i<ptr->size-1;i++){
        new_array[i] = ptr->array[i];
    }
    ptr->array = new_array;
    new_array = NULL;
}

void siftup(int* array,int size){
    int index = size-1;
    int parent = 0;
    parent = (index-1)/2;

    while(array[index] > array[parent]){
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;
            
        if(parent == 0){ break;}
        index = parent;
        parent = (index - 1)/2;
    };
}

void siftdown(int* array, int size){
    int index = 0;
    int left = index*2 + 1;
    int right = index*2 + 2;
    while (left < size)
    {
        if(array[index] < array[left] && array[index] < array[right]){
            if(array[right] > array[left]){
                int temp = array[right];
                array[right] = array[index];
                array[index] = temp;
                index = right;
            }else{
                int temp = array[left];
                array[left] = array[index];
                array[index] = temp;
                index = left;    
            }
        }
        else if(array[index] < array[left]){
            int temp = array[left];
            array[left] = array[index];
            array[index] = temp;
            index = left; 
        
        }
        else if(array[index] < array[right]){
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

void insertMaxHeap(struct MaxHeap* ptr,int key){
    makespace(ptr);
    ptr->array[ptr->no_of_values] = key;
    ptr->no_of_values++;
    siftup(ptr->array, ptr->no_of_values);
    
}


int removeMaxHeap(struct MaxHeap* ptr){
    int result = ptr->array[0];
    ptr->array[0] = ptr->array[ptr->no_of_values-1];
    ptr->no_of_values--;
    siftdown(ptr->array,ptr->no_of_values);
    return result;
}

void print(struct MaxHeap* ptr){
    for(int i=0;i<ptr->no_of_values;i++){
        printf("%d ",ptr->array[i]);
    }
    printf("\n");
}

int main(){
    struct MaxHeap* maxheap = getMaxHeap(5);
    insertMaxHeap(maxheap,153);
    insertMaxHeap(maxheap,190);
    insertMaxHeap(maxheap,721);
    insertMaxHeap(maxheap,50);
    insertMaxHeap(maxheap,380);
    insertMaxHeap(maxheap,461);
    insertMaxHeap(maxheap,70);
    print(maxheap);
    for(int i=0;i < 7;i++){
        removeMaxHeap(maxheap);
        print(maxheap);
    }
    return 0;
}