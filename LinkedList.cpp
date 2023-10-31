#include<iostream>

class LinkedListNode{
    public:
    int info{};
    LinkedListNode* next{};
};

class LinkedList
    {
    private:
    LinkedListNode* ll_front{};
    LinkedListNode* ll_back{};

    public:
    void insert(int, int);
    void remove(int);
    int at(int);
    int length();
    void print();

};

void LinkedList::insert(int key, int at = -1)
{
    LinkedListNode* new_node;
    new_node = new LinkedListNode();
    new_node->info = key;

    if(!ll_back){
        ll_front = new_node;
        ll_back = new_node;

        new_node = nullptr;
        delete(new_node);
        return;
    }

    if(at == 0){
        new_node->next = ll_front;
        ll_front = new_node;
    }
    else if(at == length() || at == -1){
        ll_back->next = new_node;
        ll_back = new_node;
    }
    else{
        for(int i=0;i<at;i++){
            LinkedListNode* temp;
            temp = ll_front;
            for(int i=1;i<at;i++){
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;
            temp = nullptr;
            delete(temp);
        }
    }

    new_node = nullptr;
    delete(new_node);
    return;
    
}

void LinkedList::remove(int at = -1)
{

    if(!ll_back){
        return;
    }
    
    LinkedListNode* temp;
    temp = ll_front;

    if(ll_front == ll_back){
        ll_front = nullptr;
        ll_back = nullptr;
    }
    else if(at == 0){
        ll_front = ll_front->next;
    }
    else if(at == -1  || at == length()-1){
        while(temp->next!=ll_back){
            temp = temp->next;
        }
        ll_back = temp;
        temp = temp->next;
        ll_back->next = nullptr;

    }else{
        
        LinkedListNode* temp_2;
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

int LinkedList::at(int at)
{
    if(!ll_back){    return 0;   }
    LinkedListNode* temp;
    temp = ll_front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

int LinkedList::length()
{
    int count{};
    if(ll_front){
        LinkedListNode* temp{};
        temp = ll_front;
        do{
            count++;
            temp = temp->next;
        }while(temp);
        return count;
    }
    return 0;
}

void LinkedList::print()
{
    if(ll_front){
        LinkedListNode* temp{};
        temp = ll_front;
        do{
            std::cout<<temp->info<<std::endl;
            temp = temp->next;
        }while(temp);

    }
}