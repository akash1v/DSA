#include<iostream>
#include"Heap.cpp"
using namespace std;
int main(){

    MaxHeap* alpha = new MaxHeap(10);
    alpha->insert(132);
    alpha->insert(543);
    alpha->insert(122);
    alpha->insert(435);
    alpha->insert(541);
    alpha->insert(946);
    alpha->insert(234);
    alpha->print();
    return 0;
}