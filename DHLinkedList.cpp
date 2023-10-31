//Double Headed Linked List
#include<iostream>

class DHLinkedListNode{
    public:
    int info{};
    DHLinkedListNode* next{};
    DHLinkedListNode* prev{};
};

class DHLinkedList
{
    private:
    DHLinkedListNode* ll_front{};
    DHLinkedListNode* ll_back{};

    public:
    void insert(int, int);
    void remove(int);
    int at(int);
    int length();
    void print();

};

void DHLinkedList::insert(int key, int at=-1)
{
    DHLinkedListNode* new_node;
    new_node = new DHLinkedListNode();
    new_node->info = key;
        
    if(!ll_back){
        ll_front = new_node;
        ll_back = new_node;
        new_node = nullptr;
        delete(new_node);
        return;
    }
    
    if(at  == 0){
        ll_front->prev = new_node;
        new_node->next = ll_front;
        ll_front = new_node;
    }
    else if(at == -1 || at == length()){
        new_node->prev = ll_back;
        ll_back->next = new_node;
        ll_back = new_node;
    }
    else{

        DHLinkedListNode* temp;
        temp = ll_front;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }

        temp->prev->next = new_node;
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev = new_node;

    }

    new_node = nullptr;
    delete(new_node);
    return;
}

void DHLinkedList::remove(int at=-1)
{
    DHLinkedListNode* temp;
    
    if(!ll_back){
        return;
    }
    else if(ll_front == ll_back){
        temp = ll_back;
        ll_back = nullptr;
        ll_front = nullptr;
        delete(temp);
        return;
    }

    if(at == 0){
        temp = ll_front;
        ll_front = ll_front->next;
        ll_front->prev = nullptr;
    }else if(at == -1 || at == length()-1){
        temp = ll_back;
        ll_back = ll_back->prev;
        ll_back->next = nullptr;
    }else{
        temp = ll_front;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev  = temp->prev;
    }
    delete(temp);
}

int DHLinkedList::at(int at)
{   
    DHLinkedListNode* temp;
    temp = ll_front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

int DHLinkedList::length()
{   int count{};
    if(ll_front){
        DHLinkedListNode* temp{};
        temp = ll_front;
        do{
            count++;
            temp = temp->next;
        }while(temp!=nullptr);
        return count;
    }
    return 0;
}

void DHLinkedList::print()
{
    if(ll_front){
        DHLinkedListNode* temp{};
        temp = ll_front;
        do{
            std::cout<<temp->info<<std::endl;
            temp = temp->next;
        }while(temp!=nullptr);
    }
}
