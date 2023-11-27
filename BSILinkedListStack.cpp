//Both Side Insert Linked List Stack

class Node{
    public:
    int info;
    Node* next{};
};

class Stack{
private:
    Node* listfront{};
    Node* listend{};
public:
    void pushFront(int);
    void pushEnd(int);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::pushFront(int data){
    Node* temp;
    temp = new Node();
    temp->info = data;

    if(listend == nullptr){
        listfront = temp;
        listend = temp;
    }
    else{
        temp->next = listfront;
        listfront = temp;
    }
    temp = nullptr;    
}

void Stack::pushEnd(int data){
    Node* temp;
    temp = new Node();
    temp->info = data;

    if(listend == nullptr){
        listfront = temp;
        listend = temp;
    }
    else{
        listend->next = temp;
        listend = temp;
    }
    temp = nullptr;
};

int Stack::pop(){
    if(listend == nullptr){
        return 0;
    }
    Node* temp = listfront;
    if(listend == listfront){
        listend = nullptr;
        listfront = nullptr;
    }
    else{
        while (temp->next!=listend){
            temp = temp->next;
        };
        listend = temp;
        temp = temp->next;
        listend->next = nullptr;
    }
    int result = temp->info;
    delete(temp);
    return temp->info;
};

int Stack::peek(){    return listend->info;    };

bool Stack::isEmpty(){
    if(listend == nullptr){
        return true;
    };
        return false;
};
