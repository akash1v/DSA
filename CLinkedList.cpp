//circular linked list
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
        listend->next = listfront;
        new_node = nullptr;
        return;
    }

    if(at == 0){
        new_node->next = listfront;
        listfront = new_node;
        listend->next = listfront;
    }
    else if(at == length() || at == -1){
        listend->next = new_node;
        listend = new_node;
        listend->next = listfront;
    }
    else{
        for(int i=0;i<at;i++){
            Node* temp;
            temp = listfront;
            for(int i=1;i<at;i++){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            temp = nullptr;
        }
    }

    new_node = nullptr;
    delete(new_node);
    return;
    
}

int LinkedList::remove(int at = -1){

    if(!listend){    return;    }
    
    Node* temp = listfront;

    if(listfront == listend){
        listfront = nullptr;
        listend = nullptr;
    }
    else if(at == 0){
        listfront = listfront->next;
        listend->next = listfront;
    }
    else if(at == -1  || at == length()-1){
        while(temp->next!=listend){
            temp = temp->next;
        }
        listend = temp;
        temp = temp->next;
        listend->next = listfront;
    }
    else{    
        Node* temp2;
        for(int i=0;i<at;i++){
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = temp->next;
        temp2 = nullptr;
        delete(temp2);
    }

    delete(temp);

}

int LinkedList::at(int at){
    if(!listend){    return 0;   }
    Node* temp = listfront;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

int LinkedList::length(){
    int count{};
    if(listfront){
        Node* temp{};
        temp = listfront;
        do{
            count++;
            temp = temp->next;
        }while(temp != listfront);
        return count;
    }
    return 0;
}

void LinkedList::print(){
    if(listfront){
        Node* temp = listfront;
        do{
            std::cout<<temp->info<<std::endl;
            temp = temp->next;
        }while(temp != listfront);
    }
}