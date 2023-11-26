//circular linked list
#include<iostream>

class CLinkedListNode{
    public:
    int info{};
    CLinkedListNode* next{};
};

class CLinkedList{
    private:
    CLinkedListNode* ll_front{};
    CLinkedListNode* ll_back{};

    public:
    void insert(int, int);
    int remove(int);
    int at(int);
    int length();
    void print();

};

void CLinkedList::insert(int key, int at = -1){
    CLinkedListNode* new_node = new CLinkedListNode();
    new_node->info = key;

    if(!ll_back){
        ll_front = new_node;
        ll_back = new_node;
        ll_back->next = ll_front;
        new_node = nullptr;
        return;
    }

    if(at == 0){
        new_node->next = ll_front;
        ll_front = new_node;
        ll_back->next = ll_front;
    }
    else if(at == length() || at == -1){
        ll_back->next = new_node;
        ll_back = new_node;
        ll_back->next = ll_front;
    }
    else{
        for(int i=0;i<at;i++){
            CLinkedListNode* temp;
            temp = ll_front;
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

int CLinkedList::remove(int at = -1){

    if(!ll_back){    return;    }
    
    CLinkedListNode* temp = ll_front;

    if(ll_front == ll_back){
        ll_front = nullptr;
        ll_back = nullptr;
    }
    else if(at == 0){
        ll_front = ll_front->next;
        ll_back->next = ll_front;
    }
    else if(at == -1  || at == length()-1){
        while(temp->next!=ll_back){
            temp = temp->next;
        }
        ll_back = temp;
        temp = temp->next;
        ll_back->next = ll_front;
    }
    else{    
        CLinkedListNode* temp_2;
        for(int i=0;i<at;i++){
            temp_2 = temp;
            temp = temp->next;
        }

        temp_2->next = temp->next;
        temp_2 = nullptr;
        delete(temp_2);
    }

    delete(temp);

}

int CLinkedList::at(int at){
    if(!ll_back){    return 0;   }
    CLinkedListNode* temp = ll_front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

int CLinkedList::length(){
    int count{};
    if(ll_front){
        CLinkedListNode* temp{};
        temp = ll_front;
        do{
            count++;
            temp = temp->next;
        }while(temp != ll_front);
        return count;
    }
    return 0;
}

void CLinkedList::print(){
    if(ll_front){
        CLinkedListNode* temp = ll_front;
        do{
            std::cout<<temp->info<<std::endl;
            temp = temp->next;
        }while(temp != ll_front);
    }
}