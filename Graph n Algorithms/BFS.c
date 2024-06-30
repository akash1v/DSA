#include<stdio.h>
#include<stdlib.h>
#include"AdjointMatrix.c"
struct Queue{
    int* array;
    int no_of_values;
    int size;
};

struct Queue* getQueue(int size){
    struct Queue* temp = (struct Queue*)malloc(sizeof( struct Queue));
    temp->array = (int*)malloc(size*sizeof(int));
    temp->size = size;
    temp->no_of_values = 0;
    return temp;
}

void enqueue(struct Queue* ptr,int val){
    if(ptr->no_of_values<ptr->size){
        ptr->array[ptr->no_of_values] = val;
        ptr->no_of_values++;
    }else{
        printf("Queue is full\n");
    }
}

int dequeue(struct Queue* ptr){
    if(ptr->no_of_values == 0){
        printf("Queue is empty\n");
    }else{
        int dequeue_val = ptr->array[0];
        for(int i=0;i<ptr->no_of_values-1;i++){
            ptr->array[i] = ptr->array[i+1];
        }
        ptr->no_of_values--;
        return dequeue_val;
    }
}

void neighbours(struct Graph* grph, struct Queue* que, int vertex){
    for (int i = 0; i < grph->vertices; i++){
        if(grph->matrix[vertex][i] == 1){
            enqueue(que, i);
        }
    }
}

int inQueue(struct Queue* que, int vertex){
    for (int i = 0; i < que->no_of_values; i++){
        if(que->array[i] == vertex){
            return 1;
        }
    }
    return 0;
}

void BFS(struct Graph* grph, int vertex){
    struct Queue* que = getQueue( grph->vertices );
    struct Queue* vstd = getQueue( grph->vertices );
    enqueue(que, vertex);

    while (que->no_of_values > 0){
        int i = dequeue(que);
        if(! inQueue(vstd, i) && ! inQueue(que, i)){
            enqueue(vstd, i);
            neighbours(grph, que, i);
            printf("%d is visited\n",i);

        }
    }
}

int main(){
    struct Graph* grph = getGraph(5);
    addEdge(grph,0,1);
    addEdge(grph,0,2);
    addEdge(grph,1,3);
    addEdge(grph,2,3);
    addEdge(grph,2,4);
    addEdge(grph,4,3);
    BFS(grph,0);
    return 0;
}