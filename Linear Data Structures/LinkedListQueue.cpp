#include"LinkedList.cpp"
class Queue{
private:
    LinkedList list;    
public:
    void enqueue(int);
    int dequeue();
    int peek();
    void print();
    int len();
    bool isEmpty();
};

void Queue::enqueue(int data){
    list.insert(data,list.length());
};

int Queue::dequeue(){
    return list.remove(0);
};

int Queue::peek(){
    return list.at(0);
};

void Queue::print(){
    list.print();
}
int Queue::len(){
    return list.length();
}

bool Queue::isEmpty(){
    return ! list.length();
};
