#include<stdio.h>
#include<stdlib.h>

struct MinHeap{
    int* array;
    int size;
    int no_of_values;
};

struct MinHeap* getMinHeap(){
    struct MinHeap* temp = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    temp->array = NULL;
    temp->size = 0;
    temp->no_of_values = 0;
    return temp;
}

void makeSpaceMinHeap(struct MinHeap* ptr){
    if(ptr->no_of_values==ptr->size){
        ptr->size++;
        int* new_array = (int*)malloc(ptr->size*sizeof(int));
        for(int i=0;i<ptr->size-1;i++){
            new_array[i] = ptr->array[i];
        }
        if(ptr->array != NULL){    free(ptr->array);    }
        ptr->array = new_array;
        new_array = NULL;
    }
}

void insertMinHeap(struct MinHeap* ptr,int key){
    makeSpaceMinHeap(ptr);
    if(ptr->no_of_values == 0){
        ptr->array[ptr->no_of_values] = key;
        ptr->no_of_values++;
    }else{
        ptr->array[ptr->no_of_values] = key;
        ptr->no_of_values++;

        int index = ptr->no_of_values-1;
        int parent = 0;
        if(index%2 == 0){ parent = (index - 2)/2;}
        else{ parent = (index - 1)/2;};

        while(ptr->array[index]<ptr->array[parent]){
            int temp = ptr->array[index];
            ptr->array[index] = ptr->array[parent];
            ptr->array[parent] = temp;
            
            if(parent == 0){ break;}
            index = parent;
            
            if(index%2 == 0){ parent = (index - 2)/2;}
            else{ parent = (index - 1)/2;};
        }

    }
}


int removeMinHeap(struct MinHeap* ptr){

    int result = ptr->array[0];
    ptr->array[0] = ptr->array[ptr->no_of_values-1];
    ptr->no_of_values--;
    int index = 0;
    int left = index*2 + 1;
    int right = index*2 + 2;
    while (left<ptr->no_of_values)
    {
        if(ptr->array[index]>ptr->array[left] && ptr->array[index]>ptr->array[right]){
            if(ptr->array[right]<ptr->array[left]){
                int temp = ptr->array[right];
                ptr->array[right] = ptr->array[index];
                ptr->array[index] = temp;
                index = right;
            }else{
                int temp = ptr->array[left];
                ptr->array[left] = ptr->array[index];
                ptr->array[index] = temp;
                index = left;    
            }
        }
        else if(ptr->array[index]>ptr->array[left]){
            int temp = ptr->array[left];
            ptr->array[left] = ptr->array[index];
            ptr->array[index] = temp;
            index = left; 

        }else if(ptr->array[index]>ptr->array[right]){
            int temp = ptr->array[right];
            ptr->array[right] = ptr->array[index];
            ptr->array[index] = temp;
            index = right;
        }else{
            break;
        }

        left = index*2 + 1;
        right = index*2 + 2;
    }
    return result;
}

void print(struct MinHeap* ptr){
    for(int i=0;i<ptr->no_of_values;i++){
        printf("%d ",ptr->array[i]);
    }
    printf("\n");
}

int main(){
    struct MinHeap* minheap = getMinHeap();
    insertMinHeap(minheap,12);
    insertMinHeap(minheap,19);
    insertMinHeap(minheap,72);
    insertMinHeap(minheap,5);
    insertMinHeap(minheap,38);
    insertMinHeap(minheap,46);
    insertMinHeap(minheap,7);
    print(minheap);
    removeMinHeap(minheap);
    print(minheap);
}