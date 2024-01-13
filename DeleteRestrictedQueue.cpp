//Both Side Insert Linked List Queue
#include"LinkedList.cpp"
class Queue{
private:
    LinkedList list;
public:
    void enqueueFront(int);
    void enqueueEnd(int);
    int dequeue();
    int peek();
    bool isEmpty();
};

void Queue::enqueueFront(int data){
    list.insert(data, 0);
}

void Queue::enqueueEnd(int data){
    list.insert(data);
};

int Queue::dequeue(){
    return list.remove(0);
};

int Queue::peek(){
    return list.at(0);
};

bool Queue::isEmpty(){
    return ! list.length();
};
