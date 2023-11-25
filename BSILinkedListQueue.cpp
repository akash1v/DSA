//Both Side Insert Linked List Stack

class Node
{
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
    int dequeue();
    int peek();
    bool isEmpty();
};

void BSILinkedListQueue::enqueueFront(int key)
{
    Node* temp = new Node();
    temp->key = key;
    if(listfront == nullptr)
    {
        listfront = temp;
        listend = temp;
    }
    else
    {
        temp->next->next = listfront;
        listfront = temp;
    }
    temp = nullptr;

}

void BSILinkedListQueue::enqueueEnd(int key)
{
    Node* temp = new Node();
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

int BSILinkedListQueue::dequeue()
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

int BSILinkedListQueue::peek(){    return listfront->key;    };

bool BSILinkedListQueue::isEmpty()
{
    if(listend == nullptr)
    {    
        return true;
    };
    return false;
};
