#include<iostream>
#include"LinkedList.cpp"

template<typename t>
class Stack{
private:
    LinkedList<t> list;
public:
    void push(int);
    t pop();
    t peek();
    int len();
    bool isEmpty();
};

template<typename t>
void Stack<t>::push(int data){
    list.insert(data, 0);
};

template<typename t>
t Stack<t>::pop(){
    return list.remove(0);
};

template<typename t>
t Stack<t>::peek(){
    return list.at(0);
};

template<typename t>
int Stack<t>::len(){
    return list.length();    
}

template<typename t>
bool Stack<t>::isEmpty(){
    return ! list.length();
};