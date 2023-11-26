#include<iostream>
using namespace std;

class Queue{
private:

int size = 10;
int* queue_array{}; 
int no_of_values{};

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
    queue_array = new int[size];
}

Queue::Queue(int a){
    size = a;
    queue_array = new int[size];
}

void Queue::enqueue(int key){
    if(no_of_values!=size){
        queue_array[no_of_values] = key;
        no_of_values++;
    }

}

int Queue::dequeue(){
    if(no_of_values!=0){   
        int value = queue_array[0];
        for(int i=0;i<no_of_values;i++){
            queue_array[i]=queue_array[i+1];
        }
        no_of_values--;
        return value;
    }
}

int Queue::peek(){   
    if(no_of_values!=0){
        return queue_array[0];
    }
}

bool Queue::isEmpty(){
    return !no_of_values;
}

Queue::~Queue(){
    delete[] queue_array;
}