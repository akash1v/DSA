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

struct Queue
{
    struct Node* front;
    struct Node* end;
};

struct Queue* getQueue(){
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->front = NULL;
    temp->end = NULL;
    return temp;
}

int length(struct Queue* ptr){
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

void enqueue(struct Queue* ptr,int val){
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

int dequeue(struct Queue*ptr){

    if(ptr->front == NULL){
        printf("Queue is empty\n");
        return 0;
    }

    struct Node* temp;
    temp = ptr->front;

    if(ptr->front == ptr->end){
        ptr->front = NULL;
        ptr->end = NULL;
    }
    else{
        ptr->front = ptr->front->next;
    }
    int data = temp->data;
    free(temp);
    return data;
}

void print(struct Queue* ptr){
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
    struct Queue* queue = getQueue();
    dequeue(queue);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    print(queue);
    dequeue(queue);
    print(queue);
}