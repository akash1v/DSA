#include<iostream>

class Node{
    public:
    int info{};
    Node* next{};
};

class LinkedList{
private:
    Node* listfront{};
    Node* listend{};
    int no_of_values{};
    
public:
    void insert(int, int);
    int remove(int);
    int at(int);
    int length();
    void print();
};

void LinkedList::insert(int data, int at = -1){
    Node* new_node = new Node();
    new_node->info = data;

    if(!listend){
        listfront = new_node;
        listend = new_node;
        new_node = nullptr;
        no_of_values++;
        return;
    }

    if(at == 0){
        new_node->next = listfront;
        listfront = new_node;
    }
    else if(at == no_of_values || at == -1){
        listend->next = new_node;
        listend = new_node;
    }
    else if(at>0 && at<no_of_values){
        Node* temp = listfront;
        for(int i=1;i<at;i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        temp = nullptr;
    }

    new_node = nullptr;
    no_of_values++;
    return;
    
}

int LinkedList::remove(int at = -1){

    if(!listend){    return 0;    }
    
    Node* temp = listfront;

    if(listfront == listend){
        listfront = nullptr;
        listend = nullptr;
    }
    else if(at == 0){
        listfront = listfront->next;
    }
    else if(at == no_of_values-1 || at == -1){
        while(temp->next!=listend){
            temp = temp->next;
        }
        listend = temp;
        temp = temp->next;
        listend->next = nullptr;
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
    no_of_values--;
    return i;
}

int LinkedList::at(int at){
    if(!listend){    return 0;   }
    Node* temp = listfront;
    if(at < 0 || at > no_of_values-1){
        return 0;
    }
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

int LinkedList::length(){
    return no_of_values;
}

void LinkedList::print(){
    if(listfront){
        Node* temp = listfront;
        do{
            std::cout<<temp->info<<"  ";
            temp = temp->next;
        }while(temp);

    }
}