//Both Side Insert Linked List Stack
#include"LinkedList.cpp"
class Stack{
private:
    LinkedList<int> list;
public:
    void pushFront(int);
    void pushEnd(int);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::pushFront(int data){
    list.insert(data, list.length());
}

void Stack::pushEnd(int data){
    list.insert(data, 0);
};

int Stack::pop(){
    return list.remove(0);
};

int Stack::peek(){
    return list.at(0);
};

bool Stack::isEmpty(){
    return ! list.length();
};
