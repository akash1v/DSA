#include<iostream>
#include"LinkedList.cpp"
class Stack{
private:
    LinkedList list;
public:
    void push(int);
    int pop();
    int peek(int);
    int len();
    bool isEmpty();
};

void Stack::push(int data){
    list.insert(data, 0);
};

int Stack::pop(){
    return list.remove(0);
};

int Stack::peek(int a){
    return list.at(a);
};

int Stack::len(){
    return list.length();    
}

bool Stack::isEmpty(){
    return ! list.length();
};