//Double Headed Linked List
#include<iostream>

class Node{
    public:
    int info{};
    Node* next{};
    Node* prev{};
};

class DHLList{
private:
    Node* front{};
    Node* end{};
    int nov;

public:

    DHLList(){};
    DHLList(DHLList &);
    void insert(int, int);
    int remove(int);
    int at(int);
    bool search(int);
    int length();
    void print();
    ~DHLList();
};

DHLList::DHLList(DHLList & obj){
    Node* temp = obj.front;
    while (temp){
        insert(temp->info, nov);
    }
}

void DHLList::insert(int data,int at){

    if(at < 0 || at > nov){    return;    }

    Node* new_node = new Node();
    new_node->info = data;
    
    if(nov == 0){
        front = new_node;
        end = new_node;
    }
    else if(at  == 0){
        front->prev = new_node;
        new_node->next = front;
        front = new_node;
    }
    else if(at == nov){
        new_node->prev = end;
        end->next = new_node;
        end = new_node;
    }
    else{
        Node* temp;
        temp = front;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = new_node;
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev = new_node;
    }
    new_node = nullptr;
    nov++;
}

int DHLList::remove(int at){    

    if(at < 0 || at > nov-1 || nov == 0){    return 0;    }

    Node* temp = front;
    if(nov == 1){
        end = nullptr;
        front = nullptr;
    }
    else if(at == 0){
        front = front->next;
        front->prev = nullptr;
    }
    else if(at == length()-1){
        temp = end;
        end = end->prev;
        end->next = nullptr;
    }
    else{
        temp = front;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev  = temp->prev;
    }
    int result = temp->info;
    delete(temp);
    nov--;
    return result;
}

int DHLList::at(int at){   
    Node* temp = front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

bool DHLList::search(int a){
    Node* temp = front;
    for (int i = 0; i < nov; i++){
        if(temp->info == a){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int DHLList::length(){
    return nov;
}

void DHLList::print(){
    Node* temp = front;
    for(int i=0; i < nov;i++){
        std::cout<<temp->info<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

DHLList::~DHLList(){
    while(nov){
        remove(0);
    }
    
}