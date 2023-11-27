//Both Side Insert Linked List Stack

class Node{
    public:
    int info;
    Node* next{};
};

class Queue{
private:
    Node* listfront{};
    Node* listend{};
public:
    void enqueueFront(int);
    void enqueueEnd(int);
    int dequeue();
    int peek();
    bool isEmpty();
};

void Queue::enqueueFront(int data){
    Node* temp = new Node();
    temp->info = data;
    if(listfront == nullptr){
        listfront = temp;
        listend = temp;
    }
    else{
        temp->next->next = listfront;
        listfront = temp;
    }
    temp = nullptr;

}

void Queue::enqueueEnd(int data){
    Node* temp = new Node();
    temp->info = data;
    if(listend == nullptr){
        listfront = temp;
        listend = temp;
    }else{
        listend->next = temp;
        listend = temp;
    }
    temp = nullptr;
};

int Queue::dequeue(){
    if(listend == nullptr){
        return;
    }
    Node* temp = listfront;
    if(listend == listfront){
        listend = nullptr;
        listfront = nullptr;
    }
    else{
        listfront = listfront->next;
    }
    int result = temp->info;
    delete(temp);
    return result;
};

int Queue::peek(){    return listfront->info;    };

bool Queue::isEmpty(){
    if(listend == nullptr){    
        return true;
    };
    return false;
};
