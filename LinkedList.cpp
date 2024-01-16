#include<iostream>

class Node{
    public:
    int info{};
    Node* next{};
};

class LinkedList{
private:
    Node* front{};
    Node* end{};
    int nov{};
    
public:

    LinkedList(){};
    LinkedList(LinkedList&);
    void insert(int, int);
    int remove(int);
    int at(int);
    bool search(int);
    int length();
    void print();
    ~LinkedList();
};

LinkedList::LinkedList(LinkedList& list){
    Node* temp = list.front;
    while (temp != nullptr){
        insert(temp->info,nov);
        temp = temp->next;
    }
}

void LinkedList::insert(int data, int at){

    if(at < 0 || at > nov)
        return;

    Node* new_node = new Node();
    new_node->info = data;
    
    if(nov == 0){
        front = new_node;
        end = new_node;
    }
    else if(at == 0){
        new_node->next = front;
        front = new_node;
    }
    else if(at == nov){
        end->next = new_node;
        end = new_node;
    }
    else{
        Node* temp = front;
        for(int i=1;i<at;i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        temp = nullptr;
    }
    new_node = nullptr;
    nov++;
}

int LinkedList::remove(int at){

    if(at < 0 || at > nov-1 || nov == 0)
        return 0;
    
    Node* temp = front;

    if(nov == 1){
        front = nullptr;
        end = nullptr;
    }
    else if(at == 0){
        front = front->next;
    }
    else if(at == nov-1){

        while(temp->next!=end)
            temp = temp->next;

        end = temp;
        temp = temp->next;
        end->next = nullptr;
    }
    else{
        
        Node* temp2;
        for(int i=0;i<at;i++){
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = temp->next;
        temp2 = nullptr;
    }
    int i = temp->info;
    delete(temp);
    nov--;
    return i;
}

int LinkedList::at(int at){
    if(at < 0 || at > nov-1 || nov == 0)
        return 0;

    Node* temp = front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

bool LinkedList::search(int data){
    Node* temp = front;
    while(temp){

        if(temp->info == data)
            return true;
        
        temp = temp->next;
    }
    return false;
}

int LinkedList::length(){
    return nov;
}

void LinkedList::print(){
    Node* temp = front;
    while (temp){
        std::cout<<temp->info<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

LinkedList::~LinkedList(){
    while (nov){
        remove(0);
    }
}