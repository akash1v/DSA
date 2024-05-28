#include<stdio.h>
#include"AdjointMatrix.c"
#include"Queue.c"

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