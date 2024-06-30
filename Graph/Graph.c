#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int vertices;
    int** matrix;
};

struct Graph* getGraph(int vertices){
    struct Graph* temp = (struct Graph*)malloc(sizeof(struct Graph));
    temp->vertices = vertices;
    temp->matrix = (int**)malloc(sizeof(int*)*vertices);
    for (int i = 0; i < vertices; i++){
        temp->matrix[i] = (int*)malloc(sizeof(int)*vertices);
    }
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            temp->matrix[i][j] = 0;
        }
    }   
    return temp;
}

void addEdge(struct Graph* ptr,int x,int y){
    if(x < ptr->vertices && y < ptr->vertices){
        ptr->matrix[x][y] = 1;
    }
}

void removeEdge(struct Graph* ptr,int x,int y){
    if(x < ptr->vertices && y < ptr->vertices){
        ptr->matrix[x][y] = 0;
    }
}

void print(struct Graph* ptr){
    
    printf("   ");
    for (int i = 0; i < ptr->vertices; i++){
        printf("%d  ",i);
    }
    printf("\n");
    for (int i = 0; i < ptr->vertices; i++){
        printf("%d  ",i);
        for (int j = 0; j < ptr->vertices; j++){
            printf("%d  ",ptr->matrix[i][j]);
        }
        printf("\n");
    }
}

// int main(){
//     struct Graph* grph = getGraph(5);
//     addEdge(grph,0,1);
//     addEdge(grph,0,2);
//     addEdge(grph,1,3);
//     addEdge(grph,2,3);
//     addEdge(grph,2,4);
//     addEdge(grph,4,3);
//     print(grph);
//     return 0;
// }