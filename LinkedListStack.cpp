class Node{
    public:
    int key;
    Node* next{};
};

class LinkedListStack{
private:
    Node* listfront{};
    Node* listend{};
public:
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
};

void LinkedListStack::push(int key){
    Node* temp = new Node();
    temp->key = key;

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

int LinkedListStack::pop(){
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
        temp->next = temp;
        listend->next = nullptr;   
    }
    int result = temp->key;
    delete(temp);
    return result;
};

int LinkedListStack::peek(){    return listend->key;    };

bool LinkedListStack::isEmpty(){
    if(listend == nullptr){    return true; };
    return false;
};
