#include<iostream>
#include"Graph.cpp"
using namespace std;
int main(){
    Graph* grph = new Graph(7);
    grph->addEdge(0,1);
    grph->addEdge(0,2);
    grph->addEdge(1,3);
    grph->addEdge(2,3);
    grph->addEdge(2,4);
    grph->addEdge(4,3);
    grph->addEdge(4,6);
    grph->addEdge(3,5);
    grph->addEdge(5,6);
    grph->traverseUsingDFS(0);
    grph->traverseUsingBFS(0);
    return 0;
}