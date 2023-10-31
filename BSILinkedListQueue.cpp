//Both Side Insert Linked List Stack

class Node{
    public:
    int key;
    Node* next{};
};

class BSILinkedListQueue
{
private:
    Node* listfront{};
    Node* listend{};
public:
    void enqueueFront(int);
    void enqueueEnd(int);
    void dequeue();
    int peek();
    bool isEmpty();
};

void BSILinkedListQueue::enqueueFront(int key){
    Node* temp;
    temp = new Node();
    temp->key = key;

    if(listfront == nullptr){
        listfront = temp;
        listend = temp;
    }else{
        temp->next->next = listfront;
        listfront = temp;
    }
    temp = nullptr;

}

void BSILinkedListQueue::enqueueEnd(int key){
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

void BSILinkedListQueue::dequeue(){
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

        listfront = listfront->next;
        delete(temp);        
    }
};

int BSILinkedListQueue::peek(){    return listfront->key;    };

bool BSILinkedListQueue::isEmpty(){
    if(listend == nullptr){    return true; };
        return false;
};
