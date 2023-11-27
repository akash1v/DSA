#include<iostream>
#include<math.h>
#include"BTree.cpp"
using namespace std;
int main(){
    BTree alpha(2);
    for (int i = 1; i < 100; i++){
        alpha.insert(i);
    }
    for (int i = 0; i < 1000; i++)
    {
        cout<<alpha.search(i);
    }
    
    return 0;
}