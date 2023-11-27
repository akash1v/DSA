class Node{
    public:
    int info{};
    Node* next{};
    Node* prev{};
};

class Stack{
private:
    Node* listfront{};
    Node* listend{};
public:
    void push(int);
    int pop();
    int peek();
    int len();
    bool isEmpty();
};

void Stack::push(int data){
    Node* new_node = new Node();
    new_node->info = data;
    if(!listend){
        listfront = new_node;
        listend = new_node;
        new_node = nullptr;
        return;
    }
    new_node->prev = listend;
    listend->next = new_node;
    listend = new_node;
    new_node = nullptr;
};

int Stack::pop(){
    if(!listend){    return;    }
    if(listfront == listend){
        listend = nullptr;
        listfront = nullptr;
    }
    Node* temp = listend;
    listend = listend->prev;
    listend->next = nullptr;
    int result = temp->info;
    delete(temp);
    return result;
};

int Stack::peek(){
    return listend->info;
};

int Stack::len(){
    if(isEmpty()){
        return 0;
    }
    int count = 0;
    Node* temp = listfront;
    while (temp){
        count++;
        temp = temp->next;
    }
    
}

bool Stack::isEmpty(){
    if(listend == nullptr){    return true; };
    return false;
};