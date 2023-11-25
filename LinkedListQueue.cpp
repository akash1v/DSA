class Node
{
    public:
    int key;
    Node* next{};
};

class LinkedListQueue
{
private:
    Node* listfront{};
    Node* listend{};
public:
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
};

void LinkedListQueue::enqueue(int key)
{
    Node* temp;
    temp = new Node();
    temp->key = key;
    if(listend == nullptr)
    {
        listfront = temp;
        listend = temp;
    }else{
        listend->next = temp;
        listend = temp;
    }
    temp = nullptr;
};

int LinkedListQueue::dequeue()
{
    if(listend == nullptr)
    {
        return;
    }
    Node* temp = listfront;
    if(listend == listfront)
    {
        listend = nullptr;
        listfront = nullptr;
    }
    else
    {
        listfront = listfront->next;
    }
    int result = temp->key;
    delete(temp);
    return result;
};

int LinkedListQueue::peek(){    return listfront->key;    };

bool LinkedListQueue::isEmpty(){
    if(listend == nullptr){    return true; };
        return false;
};
