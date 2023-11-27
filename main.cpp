#include<iostream>
#include<math.h>
#include"PriorityLinkedList.cpp"
using namespace std;
int main(){
    LinkedList alpha;
    for (int i = 1; i < 100; i++){
        alpha.push(i);
    }
    alpha.print();
    
    return 0;
}