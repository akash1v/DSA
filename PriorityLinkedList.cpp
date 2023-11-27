#include<iostream>

class Node{
public:
    int info{};
    int priority{};
    Node* next{};
    Node* prev{};
};

class LinkedList{
private:
    Node* listfront{};
    Node* listend{};

public:
    int no_of_values{};

private:
    void normalIndex(int &);

public:
    void insert(int, int);
    void push(int,int);
    int remove(int);
    int at(int);
    int len();
    void print();

};

void LinkedList::normalIndex(int & index){
    while(index<0 || index>=no_of_values){
        if(index<0){   index = index+no_of_values;   }
        if(index>=no_of_values){   index = index-no_of_values;   }
    }
}

void LinkedList::insert(int data, int priority){
    Node* new_node = new Node();
    new_node->info = data; 
    new_node->priority = priority;
    if(!listend){
        listfront = new_node;
        listend = new_node;
        new_node = nullptr;
        no_of_values++;
        return;
    }    

    if(priority < listfront->priority){
        listfront->prev = new_node;
        new_node->next = listfront;
        listfront = new_node;
    }
    else if(priority > listend->priority){
        new_node->prev = listend;
        listend->next = new_node;
        listend = new_node;
    }
    else{
        Node* temp;
        temp = listfront;
        for(int i=0; priority >= temp->priority; i++){
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

void LinkedList::push(int data, int index=-1){
    Node* new_node = new Node();
    new_node->info = data; 
    new_node->priority = 0;
    if(!listend){
        listfront = new_node;
        listend = new_node;
        new_node = nullptr;
        no_of_values++;
        return;
    }    
    if(index < 0 || index > no_of_values){
        normalIndex(index);
        index++;
    }

    if(index == 0){
        new_node->priority = listfront->priority;
        listfront->prev = new_node;
        new_node->next = listfront;
        listfront = new_node;
    }
    else if(index == no_of_values){
        new_node->priority = listend->priority;
        new_node->prev = listend;
        listend->next = new_node;
        listend = new_node;
    }
    else{
        Node* temp;
        temp = listfront;
        for(int i=0; i < index; i++){
            temp = temp->next;
        }
        new_node->priority = temp->priority;
        temp->prev->next = new_node;
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev = new_node;
    }
    new_node = nullptr;
    no_of_values++;
    return;

}

int LinkedList::remove(int index){    
    if(!listend){    return;    }
    Node* temp = listfront;
    if(listfront == listend){
        listend = nullptr;
        listfront = nullptr;
    }
    normalIndex(index);
    if(index == 0){
        listfront = listfront->next;
        listfront->prev = nullptr;
    }
    else if(index == no_of_values - 1){
        temp = listend;
        listend = listend->prev;
        listend->next = nullptr;
    }
    else{
        temp = listfront;
        for(int i=0;i<index;i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev  = temp->prev;
    }
    int result = temp->priority;
    delete(temp);
    no_of_values--;
    return result;
}

int LinkedList::at(int index){   
    Node* temp;
    temp = listfront;
    normalIndex(index);
    for(int i=0;i<index;i++){
        temp = temp->next;
    }
    return temp->info;
}

int LinkedList::len(){
    return no_of_values;
}

void LinkedList::print(){
    Node* temp = listfront;
    for(int i=0; i < no_of_values;i++){
        std::cout<<temp->priority<<"  ";
        temp = temp->next;
    }
}
