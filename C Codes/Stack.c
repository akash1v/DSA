#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int* array;
    int top;
    int size;
};

struct Stack* getStack(int size){
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->array = (int*)malloc(size*sizeof(int));
    temp->size = size;
    temp->top = -1;
    return temp;
}

void push(struct Stack* ptr,int val){
    if(ptr->top < ptr->size - 1){
        ptr->top++;
        ptr->array[ptr->top] = val;
    }else{
        printf("Stack is full\n");
    }
}

int pop(struct Stack* ptr){
    if(ptr->top < 0){
        printf("Stack is empty\n");
    }else{
        int pop_val = ptr->array[ptr->top];
        ptr->top--;
        return pop_val;
    }
}

void printStack(struct Stack* ptr){
    for(int i=0;i <= ptr->top;i++){
        printf("%d, ",ptr->array[i]);
    }
    printf("\n");
}

// int main(){
//     struct Stack* stack = getStack(10);
//     pop(stack);
//     for(int i=0;i<12;i++){
//         push(stack, i*100);
//     }
//     printStack(stack);
//     pop(stack);
//     printStack(stack);
// }