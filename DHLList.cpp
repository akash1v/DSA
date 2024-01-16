//Double Headed Linked List
#include<iostream>

template<typename t>
class Node{
public:
    t info{};
    Node<t>* next{};
    Node<t>* prev{};

    Node(t data){    info = data;    }
};

template<typename t>
class DHLList{
private:
    Node<t>* front{};
    Node<t>* end{};
    int nov;

public:

    DHLList(){};
    DHLList(DHLList<t> &);
    void insert(t, int);
    t remove(int);
    t at(int);
    int search(t);
    int length();
    void print();
    ~DHLList();
};

template<typename t>
DHLList<t>::DHLList(DHLList & obj){
    Node<t>* temp = obj.front;
    while (temp){
        insert(temp->info, nov);
    }
}

template<typename t>
void DHLList<t>::insert(t data,int at){

    if(at < 0 || at > nov){    return;    }

    Node<t>* new_node = new Node(data);
    
    if(nov == 0){
        front = new_node;
        end = new_node;
    }
    else if(at  == 0){
        front->prev = new_node;
        new_node->next = front;
        front = new_node;
    }
    else if(at == nov){
        new_node->prev = end;
        end->next = new_node;
        end = new_node;
    }
    else{
        Node<t>* temp;
        temp = front;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = new_node;
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev = new_node;
    }
    new_node = nullptr;
    nov++;
}

template<typename t>
t DHLList<t>::remove(int at){    

    t result{};

    if(at < 0 || at > nov-1 || nov == 0){    return result;    }

    Node<t>* temp = front;
    if(nov == 1){
        end = nullptr;
        front = nullptr;
    }
    else if(at == 0){
        front = front->next;
        front->prev = nullptr;
    }
    else if(at == length()-1){
        temp = end;
        end = end->prev;
        end->next = nullptr;
    }
    else{
        temp = front;
        for(int i=0;i<at;i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev  = temp->prev;
    }
    result = temp->info;
    delete(temp);
    nov--;
    return result;
}

template<typename t>
t DHLList<t>::at(int at){   
    Node<t>* temp = front;
    for(int i=0;i<at;i++){
        temp = temp->next;
    }
    return temp->info;
}

template<typename t>
int DHLList<t>::search(t a){
    Node<t>* temp = front;
    for (int i = 0; i < nov; i++){
        if(temp->info == a){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

template<typename t>
int DHLList<t>::length(){
    return nov;
}

template<typename t>
void DHLList<t>::print(){
    Node<t>* temp = front;
    for(int i=0; i < nov;i++){
        std::cout<<temp->info<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

template<typename t>
DHLList<t>::~DHLList(){
    while(nov){
        remove(0);
    }    
}