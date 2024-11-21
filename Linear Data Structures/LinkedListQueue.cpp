#include"LinkedList.cpp"

template<typename t>
class Queue{
private:
    LinkedList<t> list;    
public:
    void enqueue(int);
    int dequeue();
    int peek();
    void print();
    int len();
    bool isEmpty();
};

template<typename t>
void Queue<t>::enqueue(int data){
    list.insert(data,list.length());
};

template<typename t>
int Queue<t>::dequeue(){
    return list.remove(0);
};

template<typename t>
int Queue<t>::peek(){
    return list.at(0);
};

template<typename t>
void Queue<t>::print(){
    list.print();
}

template<typename t>
int Queue<t>::len(){
    return list.length();
}

template<typename t>
bool Queue<t>::isEmpty(){
    return ! list.length();
};
