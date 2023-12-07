#include<iostream>
#include"DHLinkedList.cpp"

class Graph{
private:
    int vertices{};
    int ** matrix{};

public:
    Graph(int);
    void addEdge(int, int);
    void removeEdge(int, int);
    void traverseUsingDFS(int);
    void traverseUsingBFS(int);
};

Graph::Graph(int a){
    vertices = a;
    matrix = new int*[a]{};
    for (int i = 0; i < a; i++){
        matrix[i] = new int[a]{};
    }
}

void Graph::addEdge(int x,int y){
    matrix[x][y] = 1;
}

void Graph::removeEdge(int x, int y){
    matrix[x][y] = 0;
}

void Graph::traverseUsingDFS(int start){
    LinkedList* stack = new LinkedList();
    LinkedList* visited = new LinkedList();
    stack->insert(start);
    while (stack->length()){
        int x = stack->remove();
        if(!stack->search(x) && !visited->search(x)){
            visited->insert(x);
            for (int i = 0; i < vertices; i++){
                if(matrix[x][i] == 1){
                    stack->insert(i);
                }
            }
            std::cout<<x<<" is visited"<<std::endl;
        }
    }

}

void Graph::traverseUsingBFS(int start){
    LinkedList* queue = new LinkedList();
    LinkedList* visited = new LinkedList();
    queue->insert(start);
    while (queue->length()){
        int x = queue->remove(0);
        if(! queue->search(x) && ! visited->search(x)){
            visited->insert(x);
            for (int i = 0; i < vertices; i++){
                if(matrix[x][i] == 1){
                    queue->insert(i);
                }
            }
            std::cout<<x<<" is visited"<<std::endl;
        }
    }
}