//Double Headed Linked List
#include<iostream>

class Node{
    public:
    int info{};
    Node* next{};
    Node* prev{};
};

class LinkedList{
private:
    Node* listfront{};
    Node* listend{};
    int no_of_values;

public:
    void insert(int, int);
    int remove(int);
    int at(int);
    int length();
    void print();
};

void LinkedList::insert(int data,int at = -1){
    Node* new_node = new Node();
    new_node->info = data;
    if(!listend){
        listfront = new_node;
        listend = new_node;
        new_node = nullptr;
        no_of_values++;
        return;
    }
    if(at  == 0){
        listfront->prev = new_node;
        new_node->next = listfront;
        listfront = new_node;
    }
    else if(at == -1 || at == no_of_values){
        new_node->prev = listend;
        listend->next = new_node;
        listend = new_node;
    }
    else{
        Node* temp;
        temp = listfront;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = new_node;
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev = new_node;
    }
    new_node = nullptr;
    no_of_values++;
    return;
}

int LinkedList::remove(int at=-1){    
    if(!listend){    return;    }
    Node* temp = listfront;
    if(listfront == listend){
        listend = nullptr;
        listfront = nullptr;
    }
    if(at == 0){
        listfront = listfront->next;
        listfront->prev = nullptr;
    }
    else if(at == -1 || at == length()-1){
        temp = listend;
        listend = listend->prev;
        listend->next = nullptr;
    }
    else{
        temp = listfront;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev  = temp->prev;
    }
    int result = temp->info;
    delete(temp);
    no_of_values--;
    return result;
}

int LinkedList::at(int at){   
    Node* temp;
    temp = listfront;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

int LinkedList::length(){
    return no_of_values;
}

void LinkedList::print(){
    Node* temp = listfront;
    for(int i=0; i < no_of_values;i++){
        std::cout<<temp->info<<"  ";
        temp = temp->next;
    }
}
