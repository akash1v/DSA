#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* getNode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
}

struct Stack{
    struct Node* front;
    struct Node* end;
    int no_of_values;
};

struct Stack* getStack(){
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->front = NULL;
    temp->end = NULL;
    temp->no_of_values = 0;
    return temp;
}

int length(struct Stack* ptr){
    return ptr->no_of_values;
}

void push(struct Stack* ptr,int val){
    struct Node* new_node;
    new_node = getNode(val);

    if(ptr->front == NULL){
        ptr->front = new_node;
        ptr->end = new_node;
    }
    else{
        ptr->end->next = new_node;
        ptr->end = new_node;
    }
    new_node = NULL;
    ptr->no_of_values++;
    return;
}

int pop(struct Stack*ptr){

    if(ptr->front == NULL){
        printf("Stack is empty\n");
        return 0;
    }

    struct Node* temp;
    temp = ptr->front;

    if(ptr->front == ptr->end){
        ptr->front = NULL;
        ptr->end = NULL;
    }
    else{
        while(temp->next!=ptr->end){
            temp = temp->next;
        }
        ptr->end = temp;
        temp = temp->next;
        ptr->end->next = NULL;
    }
    int data = temp->data;
    free(temp);
    ptr->no_of_values--;
    return data;
}

void print(struct Stack* ptr){
    struct Node* temp;
    temp = ptr->front;
    while(temp != NULL){
    printf("%d, ",temp->data);
            temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Stack* stack = getStack();
    pop(stack);
    for (int i = 0; i < 10; i++){
    push(stack, i*100);
    }
    print(stack);
    printf("Length of stack : %d\n",length(stack));
    pop(stack);
    print(stack);
    printf("Length of stack : %d\n",length(stack));
    return 0;
}