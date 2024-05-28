#include<stdio.h>
#include"AdjointMatrix.c"
#include"Stack.c"

void neighbours(struct Graph* grph, struct Stack* stck, int vertex){
    for (int i = 0; i < grph->vertices; i++){
        if(grph->matrix[vertex][i] == 1){
            push(stck, i);
        }
    }
}

int inStack(struct Stack* stck, int vertex){
    for (int i = 0; i < stck->top + 1; i++){
        if(stck->array[i] == vertex){
            return 1;
        }
    }
    return 0;
}

void DFS(struct Graph* grph, int vertex){
    struct Stack* stck = getStack( grph->vertices );
    struct Stack* vstd = getStack( grph->vertices );
    push(stck, vertex);

    while (stck->top >= 0){
        int i = pop(stck);
        if(! inStack(vstd, i) && ! inStack(stck, i)){
            push(vstd, i);
            neighbours(grph, stck, i);
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
    DFS(grph,0);
    return 0;
}