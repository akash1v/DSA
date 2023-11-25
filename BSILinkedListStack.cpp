//Both Side Insert Linked List Stack

class Node
{
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
    int pop();
    int peek();
    bool isEmpty();
};

void BSILinkedListStack::pushFront(int key){
    Node* temp;
    temp = new Node();
    temp->key = key;

    if(listend == nullptr)
    {
        listfront = temp;
        listend = temp;
    }
    else
    {
        temp->next = listfront;
        listfront = temp;
    }
    temp = nullptr;    
}

void BSILinkedListStack::pushEnd(int key)
{
    Node* temp;
    temp = new Node();
    temp->key = key;

    if(listend == nullptr)
    {
        listfront = temp;
        listend = temp;
    }
    else
    {
        listend->next = temp;
        listend = temp;
    }
    temp = nullptr;
};

int BSILinkedListStack::pop(){
    if(listend == nullptr)
    {
        return 0;
    }
    Node* temp = listfront;
    if(listend == listfront)
    {
        listend = nullptr;
        listfront = nullptr;
    }
    else
    {
        while (temp->next!=listend)
        {
            temp = temp->next;
        };
        listend = temp;
        temp = temp->next;
        listend->next = nullptr;
    }
    int result = temp->key;
    delete(temp);
    return temp->key;
};

int BSILinkedListStack::peek(){    return listend->key;    };

bool BSILinkedListStack::isEmpty()
{
    if(listend == nullptr)
    {
        return true;
    };
        return false;
};
