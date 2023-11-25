#include<iostream>
#include"AVLTree.cpp"

int main(){
    AVLTree alpha;
    for (int i = 1; i < 1024; i++)
    {
        alpha.insert(i);
    }
    cout<<alpha.height()<<endl;
    return 0;    
}