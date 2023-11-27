#include<iostream>
using namespace std;

class Stack{
private:
    int size = 10;
    int* array{}; 
    int no_of_values{};

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
    if(no_of_values!=size){
        array[no_of_values]=key;
        no_of_values++;
    };
}

int Stack::pop(){
    if(no_of_values!=0){
        no_of_values--;
        return array[no_of_values];
    }
}

int Stack::peek(){   
    if(no_of_values!=0){
        return array[no_of_values-1];
    }
}

bool Stack::isEmpty(){
    return !no_of_values;
}

Stack::~Stack(){
    delete[] array;
}