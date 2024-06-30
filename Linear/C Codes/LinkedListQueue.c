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

struct Queue{
    struct Node* front;
    struct Node* end;
    int no_of_values;
};

struct Queue* getQueue(){
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->front = NULL;
    temp->end = NULL;
    temp->no_of_values = 0;
    return temp;
}

int length(struct Queue* ptr){
    return ptr->no_of_values;
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
    ptr->no_of_values++;
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
    ptr->no_of_values--;
    return data;
}

void print(struct Queue* ptr){
    struct Node* temp;
    temp = ptr->front;
    while(temp != NULL){
        printf("%d, ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue* queue = getQueue();
    dequeue(queue);
    for(int i=1; i < 5; i++){
        enqueue(queue, i*100);
    }
    print(queue);
    printf("Length of queue : %d\n",length(queue));
    dequeue(queue);
    print(queue);
    printf("Length of queue : %d\n",length(queue));

    return 0;
}