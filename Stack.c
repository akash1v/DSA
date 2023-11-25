#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int* array;
    int no_of_values;
    int size;
};

struct Stack* getStack(int size){
    struct Stack* temp;
    int* arr = (int*)malloc(size*sizeof(int));
    temp->array = arr;
    arr = NULL;
    temp->size = size;
    temp->no_of_values = 0;
    return temp;
}

void push(struct Stack* ptr,int val){
    if(ptr->no_of_values<ptr->size){
        ptr->array[ptr->no_of_values] = val;
        ptr->no_of_values++;
    }else{
        printf("Stack is full\n");
    }
}

int pop(struct Stack* ptr){
    if(ptr->no_of_values == 0){
        printf("Stack is empty\n");
    }else{
        int pop_val = ptr->array[ptr->no_of_values-1];
        ptr->no_of_values--;
        return pop_val;
    }
}

void print(struct Stack* ptr){
    if(ptr->no_of_values != 0){
        printf("[ %d",ptr->array[0]);
        for(int i=1;i<ptr->no_of_values;i++){
            printf(", %d",ptr->array[i]);
        }
        printf(" ]");
    }
    printf("\n");
}

int main(){
    struct Stack* stack = getStack(10);
    pop(stack);
    for(int i=0;i<11;i++){
        push(stack, i*10);
    }
    print(stack);
    pop(stack);
    print(stack);
}