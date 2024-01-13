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
    void insert(int, int);
    int remove(int);
    int at(int);
    bool search(int);
    int length();
    void print();
};

void LinkedList::insert(int data, int at = -1){
    Node* new_node = new Node();
    new_node->info = data;

    if(!end){
        front = new_node;
        end = new_node;
    }
    else if(at == 0){
        new_node->next = front;
        front = new_node;
    }
    else if(at == nov || at == -1){
        end->next = new_node;
        end = new_node;
    }
    else if(at>0 && at<nov){
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
    return;
    
}

int LinkedList::remove(int at = -1){

    if(!end){    return 0;    }
    
    Node* temp = front;

    if(front == end){
        front = nullptr;
        end = nullptr;
    }
    else if(at == 0){
        front = front->next;
    }
    else if(at == nov-1 || at == -1){
        while(temp->next!=end){
            temp = temp->next;
        }
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
    if(!end){    return 0;   }
    Node* temp = front;
    if(at < 0 || at > nov-1){
        return 0;
    }
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

bool LinkedList::search(int data){
    Node* temp = front;
    while(temp!=nullptr){
        if(temp->info == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int LinkedList::length(){
    return nov;
}

void LinkedList::print(){
    if(front){
        Node* temp = front;
        do{
            std::cout<<temp->info<<"  ";
            temp = temp->next;
        }while(temp);

    }
}