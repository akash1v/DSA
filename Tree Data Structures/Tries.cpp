#include<iostream>
using namespace std;
class Node{
public:
    char data{};
    Node** array{};
    int array_size{};
    int no_of_values{};

    Node(char i){
        data = i;
    };
};

class Tries{
private:
    Node* root_node = new Node(' ');

    int search(Node*, char);
    int insert(Node*, char);
    void print(Node*);
    Node** increaseArray(Node**, int, int);

public:
    void insert(char*);
    void print();
};



Node** Tries::increaseArray(Node** array, int size, int ifactor=1){
    Node** new_array = new Node*[size + ifactor]{};
    for (int i = 0; i < size; i++){
        new_array[i] = array[i];
    }
    delete[] array;
    return new_array;
}

int Tries::search(Node* ptr, char i){
    if(!ptr){return -1;}

    for(int i=0; i < ptr->array_size; i++){
        if(ptr->array[i]->data == i){
            return i;
        }
    }
    return -1;
};

void Tries::insert(char* str){
    Node* temp = root_node;
    int i=0;
    char c = str[i];
    while(c!='\0'){
        int j = search(temp,c);
        if(j != -1){
            temp = temp->array[j];
        }else{
            break;
        }
        i++;
        c = str[i];
    }

    while (c!='\0'){
        int index = insert(temp,c);
        temp = temp->array[index];
        i++;
        c = str[i];
    }
}

int Tries::insert(Node* ptr,char c){
    if(ptr->array_size == ptr->no_of_values){
        ptr->array = increaseArray(ptr->array, ptr->array_size);
        ptr->array_size++;
    }

    int i=0;
    for(i;i<ptr->no_of_values;i++){
        if(c<ptr->array[i]->data){
            break;
        }
    }
    
    for (int j = ptr->no_of_values; j > i; j--){
        ptr->array[j] = ptr->array[j-1];
    }

    ptr->array[i] = new Node(c);
    ptr->no_of_values++;
    return i;
}

void Tries::print(){
    print(root_node);
}

void Tries::print(Node* ptr){
    cout<<ptr->data;
    for (size_t i = 0; i < ptr->no_of_values; i++){
        print(ptr->array[i]);
    }
    if(ptr->no_of_values == 0){
        cout<<endl;
    }
}