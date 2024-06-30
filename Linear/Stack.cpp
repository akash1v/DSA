#include<iostream>
using namespace std;

class Stack{
private:
    int size = 10;
    int* array{}; 
    int top = -1;

public:
    Stack();
    Stack(int);
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
    ~Stack();
};

Stack::Stack(){
    array = new int[size];
}

Stack::Stack(int a){
    int size = a;
    array = new int[size];
}

void Stack::push(int key){
    if(top!=size - 1){
        array[++top]=key;
    };
}

int Stack::pop(){
    if(top!=-1){
        int k = array[top--];
        return k;
    }
    return 0;
}

int Stack::peek(){   
    if(top!=-1){
        return array[top];
    }
    return 0;
}

bool Stack::isEmpty(){
    if(top==-1){    return true;    };
    return false;
}

Stack::~Stack(){
    delete[] array;
}