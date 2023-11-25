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

struct Stack
{
    struct Node* front;
    struct Node* end;
};

struct Stack* getStack(){
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->front = NULL;
    temp->end = NULL;
    return temp;
}

int length(struct Stack* ptr){
    int count=0;
    if(ptr->front != NULL){
        struct Node* temp;
        temp = ptr->front;
        do{
            count++;
            temp = temp->next;
        }while(temp != NULL);
        return count;
    }
    return count;
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
    return data;
}

void print(struct Stack* ptr){
    if(ptr->front != NULL){
        printf("[ %d",ptr->front->data);
        struct Node* temp;
        temp = ptr->front->next;
        while(temp != NULL){
            printf(", %d",temp->data);
            temp = temp->next;
        }
        printf(" ]");
    }
    printf("\n");
}

int main(){
    struct Stack* stack = getStack();
    pop(stack);
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    print(stack);
    pop(stack);
    print(stack);
}