//Both Side Insert Linked List Stack

class Node{
    public:
    int key;
    Node* next{};
};

class BSILinkedListStack
{
private:
    Node* listfront{};
    Node* listend{};
public:
    void pushFront(int);
    void pushEnd(int);
    void pop();
    int peek();
    bool isEmpty();
};

void BSILinkedListStack::pushFront(int key){
    Node* temp;
    temp = new Node();
    temp->key = key;

    if(listend == nullptr){
        listfront = temp;
        listend = temp;
    }else{
        temp->next = listfront;
        listfront = temp;
    }
    temp = nullptr;    
}

void BSILinkedListStack::pushEnd(int key){
    Node* temp;
    temp = new Node();
    temp->key = key;

    if(listend == nullptr){
        listfront = temp;
        listend = temp;
    }else{
        listend->next = temp;
        listend = temp;
    }
    temp = nullptr;
};

void BSILinkedListStack::pop(){
    if(listend == nullptr){
        return;
    }else if(listend == listfront){
        Node* temp;
        temp = listend;
        listend = nullptr;
        listfront = nullptr;
        delete(temp);
    }else{
        Node* temp;
        temp = listfront;
        while (temp->next!=listend)
        {
            temp = temp->next;
        };

        Node* temp_2;
        temp_2 = listend;
        listend = temp;
        delete(temp_2);
        temp = nullptr;
        
    }
};

int BSILinkedListStack::peek(){    return listend->key;    };

bool BSILinkedListStack::isEmpty(){
    if(listend == nullptr){    return true; };
        return false;
};
