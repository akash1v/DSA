#include<iostream>
using namespace std;

class Stack
{
private:

int size = 10;
int* stack_array{}; 
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
    stack_array = new int[size];
}

Stack::Stack(int a){
    int size = a;
    stack_array = new int[size];
}

void Stack::push(int key)
{
    if(no_of_values!=size)
    {
        stack_array[no_of_values]=key;
        no_of_values++;
    };
}

int Stack::pop()
{
    if(no_of_values!=0)
    {
        no_of_values--;
        return stack_array[no_of_values];
    }
}

int Stack::peek()
{   
    if(no_of_values!=0)
    {
        return stack_array[no_of_values-1];
    }
}

bool Stack::isEmpty()
{
    return !no_of_values;
}

Stack::~Stack()
{
    delete[] stack_array;
}