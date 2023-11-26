#include<iostream>

class LinkedListNode{
    public:
    int info{};
    LinkedListNode* next{};
};

class LinkedList{
private:
    LinkedListNode* ll_front{};
    LinkedListNode* ll_back{};
    int no_of_values{};
    
public:
    void insert(int, int);
    int remove(int);
    int at(int);
    int length();
    void print();
};

void LinkedList::insert(int key, int at = -1){
    LinkedListNode* new_node = new LinkedListNode();
    new_node->info = key;

    if(!ll_back){
        ll_front = new_node;
        ll_back = new_node;
        new_node = nullptr;
        no_of_values++;
        return;
    }

    if(at == 0){
        new_node->next = ll_front;
        ll_front = new_node;
    }
    else if(at == no_of_values || at == -1){
        ll_back->next = new_node;
        ll_back = new_node;
    }
    else if(at>0 && at<no_of_values){
        LinkedListNode* temp = ll_front;
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

    if(!ll_back){    return 0;    }
    
    LinkedListNode* temp = ll_front;

    if(ll_front == ll_back){
        ll_front = nullptr;
        ll_back = nullptr;
    }
    else if(at == 0){
        ll_front = ll_front->next;
    }
    else if(at == no_of_values-1 || at == -1){
        while(temp->next!=ll_back){
            temp = temp->next;
        }
        ll_back = temp;
        temp = temp->next;
        ll_back->next = nullptr;
    }
    else{
        
        LinkedListNode* temp_2;
        for(int i=0;i<at;i++){
            temp_2 = temp;
            temp = temp->next;
        }

        temp_2->next = temp->next;
        temp_2 = nullptr;
    }
    int i = temp->info;
    delete(temp);
    no_of_values--;
    return i;
}

int LinkedList::at(int at){
    if(!ll_back){    return 0;   }
    LinkedListNode* temp = ll_front;
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
    if(ll_front){
        LinkedListNode* temp = ll_front;
        do{
            std::cout<<temp->info<<"  ";
            temp = temp->next;
        }while(temp);

    }
}