class Node{
    public:
    int key;
    Node* next{};
};

class LinkedListStack
{
private:
    Node* listfront{};
    Node* listend{};
public:
    void push(int);
    void pop();
    int peek();
    bool isEmpty();
};

void LinkedListStack::push(int key){
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

void LinkedListStack::pop(){
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

int LinkedListStack::peek(){    return listend->key;    };

bool LinkedListStack::isEmpty(){
    if(listend == nullptr){    return true; };
        return false;
};
