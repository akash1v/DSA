#include<iostream>
using namespace std;

class Queue{
private:
    int size = 10;
    int* array{}; 
    int nov{};
    int front{};

public:
    Queue();
    Queue(int);
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
    ~Queue();
};

Queue::Queue(){
    array = new int[size];
}

Queue::Queue(int a){
    size = a;
    array = new int[size];
}

void Queue::enqueue(int key){
    if (nov == size){    return;    }
    int k = 0;
    if(nov >= front){
        k = front + nov;
        if(k >= size){    k -= size;    }
    }else{
        k = nov;
    }
    array[k] = key;
    nov++;
}

int Queue::dequeue(){
    if(nov == 0){    return 0;    }
    if(front >= size){    front -= size;    }  
    int value = array[front++];
    nov--;
    return value;
}

int Queue::peek(){   
    if(nov!=0){
        return array[0];
    }
    return 0;
}

bool Queue::isEmpty(){
    return !nov;
}

Queue::~Queue(){
    delete[] array;
}