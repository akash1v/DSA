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
    void enqueue(int);
    int dequeue();
    int peek();
    int len();
    bool isEmpty();
};

void Queue::enqueue(int data){
    Node* temp;
    temp = new Node();
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

int Queue::peek(){
    return listfront->info;
};

int Queue::len(){
    if(isEmpty()){
        return 0;
    }
    int count = 0;
    Node* temp = listfront;
    while(temp){
        count++;
        temp = temp->next;
    }
}

bool Queue::isEmpty(){
    if(listend == nullptr){    return true; };
        return false;
};
