//Double Headed Circular Linked List
#include<iostream>

class DHCLinkedListNode{
    public:
    int info{};
    DHCLinkedListNode* next{};
    DHCLinkedListNode* prev{};
};

class DHCLinkedList
    {
    private:
    DHCLinkedListNode* ll_front{};
    DHCLinkedListNode* ll_back{};

    DHCLinkedListNode* nodeAt(int &);
    void normalizeAt(int &);

    public:
    void insert(int, int);
    void remove(int);
    int at(int);
    int length();
    void print();

};

DHCLinkedListNode *DHCLinkedList::nodeAt(int &a)
{   
    DHCLinkedListNode* temp{};
    if(a>=0){
        temp = ll_front;
        for(int i=0;i<a;i++){
            temp = temp->next;
        }
    }else{
        temp = ll_back;
        for(int i=-1;i>a;i--){
            temp = temp->prev;
        }
    }
    return temp;
}

void DHCLinkedList::normalizeAt(int &at){
    while(at>=length()){    at=at-length();   };
    while(at<=-length()){   at=at+length();    };
}

void DHCLinkedList::insert(int key, int at=-1)
{
    DHCLinkedListNode* new_node;
    new_node = new DHCLinkedListNode();
    new_node->info = key;
        
    if(!ll_back){
        ll_front = new_node;
        ll_back = new_node;
        ll_front->prev = ll_back;
        ll_back->next = ll_front;
        new_node = nullptr;
        delete(new_node);
        return;
    }
    
    normalizeAt(at);

    if(at == -1){
        new_node->next = ll_front;
        ll_front->prev = new_node;
        new_node->prev = ll_back;
        ll_back->next = new_node;
        ll_back = new_node;
    }
    else{
        if(at<0){   at = at+1;  }
        DHCLinkedListNode* temp;
        temp = nodeAt(at);
        if(temp == ll_front){
            ll_back->next = new_node;
            new_node->prev = ll_back;
            new_node->next = ll_front;
            ll_front->prev = new_node;
            ll_front = new_node;
        }else{
            new_node->next = temp;
            new_node->prev = temp->prev;
            temp->prev = new_node;
            new_node->prev->next = new_node;
        }
    }

    new_node = nullptr;
    delete(new_node);
    return;
}

void DHCLinkedList::remove(int at=-1)
{
    DHCLinkedListNode* temp;
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

    normalizeAt(at);
    temp = nodeAt(at);

    if(temp == ll_front){
        ll_front = ll_front->next;
        ll_front->prev = ll_back;
        ll_back->next = ll_front;
    }else if(temp == ll_back){
        ll_back = ll_back->prev;
        ll_back->next = ll_front;
        ll_front->prev = ll_back;
    }else{
        temp->prev->next = temp->next;
        temp->next->prev  = temp->prev;
    }
    delete(temp);
}

int DHCLinkedList::at(int at)
{
    if(!ll_back){    return 0;   }
    normalizeAt(at);
    return nodeAt(at)->info;
}

int DHCLinkedList::length()
{   int count{};
    if(ll_front){
        DHCLinkedListNode* temp{};
        temp = ll_front;
        do{
            count++;
            temp = temp->next;
        }while(temp!=ll_front);
        return count;
    }
    return 0;
}

void DHCLinkedList::print()
{
    if(ll_front){
        DHCLinkedListNode* temp{};
        temp = ll_front;
        do{
            std::cout<<temp->info<<std::endl;
            temp = temp->next;
        }while(temp!=ll_front);
    }
}
