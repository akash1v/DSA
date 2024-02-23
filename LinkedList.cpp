#pragma once
#include<iostream>
template<typename t>
class Node{
    public:
    t info{};
    Node<t>* next{};

    Node(t data){    info = data;    }
};

template<typename t>
class LinkedList{
private:
    Node<t>* front{};
    Node<t>* end{};
    int nov{};
    
public:

    LinkedList(){};
    LinkedList(LinkedList<t>&);
    void insert(t, int);
    t remove(int);
    t at(int);
    int search(t);
    int length();
    void print();
    ~LinkedList();
};

template<typename t>
LinkedList<t>::LinkedList(LinkedList<t>& list){
    Node<t>* temp = list.front;
    while (temp != nullptr){
        insert(temp->info,nov);
        temp = temp->next;
    }
}

template<typename t>
void LinkedList<t>::insert(t data, int at){

    if(at < 0 || at > nov)
        return;

    Node<t>* new_node = new Node(data);
    
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
        Node<t>* temp = front;
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

template<typename t>
t LinkedList<t>::remove(int at){

    if(at < 0 || at > nov-1 || nov == 0)
        return 0;
    
    Node<t>* temp = front;

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
        
        Node<t>* temp2;
        for(int i=0;i<at;i++){
            temp2 = temp;
            temp = temp->next;
        }

        temp2->next = temp->next;
        temp2 = nullptr;
    }
    t result = temp->info;
    delete(temp);
    nov--;
    return result;
}

template<typename t>
t LinkedList<t>::at(int at){
    if(at < 0 || at > nov-1 || nov == 0)
        return 0;

    Node<t>* temp = front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

template<typename t>
int LinkedList<t>::search(t data){
    Node<t>* temp = front;
    for (int i = 0; i < nov; i++)
    {
        if(temp->info == data){
            return i;
        }
        temp = temp->next;
    }
    
    return -1;
}

template<typename t>
int LinkedList<t>::length(){
    return nov;
}

template<typename t>
void LinkedList<t>::print(){
    Node<t>* temp = front;
    while (temp){
        std::cout<<temp->info<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

template<typename t>
LinkedList<t>::~LinkedList(){
    while (nov){
        remove(0);
    }
}