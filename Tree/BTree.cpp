#include<iostream>
using namespace std;

class Node{
public:
    int* info_array{};
    int no_of_values{};
    Node* parent{};
    Node** node_array{};

    Node(int a){
        info_array = new int [a]{};
        node_array = new Node*[a+1]{};
    };
};

class DataNode{
public:
    int key{};
    Node* right{};
};

class BTree{
private:
    Node* root_node;
    int size{};

    Node* makeParent(Node*,int &,Node*);
    int getLocation(Node*, int &);
    bool spaceAvailable(Node*);
    void makeSpace(Node*, int&, bool);
    void override(Node*, int &, Node*);
    DataNode* breakNode(Node*, bool);
    
    void print(Node*);
    
public:
    BTree();
    BTree(int);
    void insert(int);
    bool search(int);
    void print();
};

BTree::BTree(){
    size = 100;
    root_node = new Node(size);
}

BTree::BTree(int a){
    if(a < 2){  BTree(); }
    size = a;
    root_node = new Node(size);
}

void BTree::insert(int data){
    Node* temp = root_node;

    while(true){
        int i = getLocation(temp,data);
        if(temp->node_array[i] == nullptr){   break;  };
        temp = temp->node_array[i];
    }

    override(temp, data, nullptr);
    if(spaceAvailable(temp)){
        temp->no_of_values++;
        return;
    }

    DataNode* dn = breakNode(temp, false);

    while (true){
        Node* parent = temp->parent;
        if(parent == nullptr){
            root_node = makeParent(temp, dn->key, dn->right);
            root_node->no_of_values++;
            return;
        }
        temp = parent;
        override(temp, dn->key, dn->right);
        if(spaceAvailable(temp)){
            temp->no_of_values++;
            return;
        }
        dn = breakNode(temp,true);
    }
}

bool BTree::search(int data){
    Node* temp = root_node;
    while(true){
        int i = getLocation(temp,data);
        if(data == temp->info_array[i]){    return true;    }
        if(temp->node_array[i] == nullptr){   return false;  };
        temp = temp->node_array[i];
    }    
}

Node* BTree::makeParent(Node* left,int &data,Node* right){
    Node* parent = new Node(size);
    parent->info_array[0] = data;
    parent->node_array[0] = left;
    parent->node_array[1] = right;
    left->parent = parent;
    right->parent = parent;
    return parent;
};

bool BTree::spaceAvailable(Node* ptr){
    if(ptr->no_of_values<size-1){
        return true;
    }
    return false;
}

int BTree::getLocation(Node* ptr, int& data){
    int i=0;
    for(i;  i != ptr->no_of_values  && data > ptr->info_array[i]; i++);
    return i;
}

void BTree::makeSpace(Node* ptr, int& i,bool branch_node){
    for(int j = ptr->no_of_values ; j>i ;j--){
        ptr->info_array[j] = ptr->info_array[j-1];
        if(branch_node){
            ptr->node_array[j+1] = ptr->node_array[j];
        }
    }
}

void BTree::override(Node* ptr, int& data, Node* right){
    int i= getLocation(ptr, data);
    makeSpace(ptr, i, right);
    ptr->info_array[i] = data;
    if(right){
        ptr->node_array[i+1] = right;
        right->parent = ptr;
    }
}

DataNode* BTree::breakNode(Node* left,bool branch_node = false){

    DataNode* n = new DataNode();
    n->key = left->info_array[size/2];
    n->right = new Node(size);
    n->right->parent = left->parent;

    int i = (size/2)+1;
    int s=0;

    for(i, s=0; i < size; i++, s++ ){
        n->right->info_array[s] = left->info_array[i];
        n->right->no_of_values++;
        if(branch_node){
            n->right->node_array[s] = left->node_array[i];
            n->right->node_array[s]->parent = n->right;
        }
    }
    if(branch_node){
        n->right->node_array[s] = left->node_array[i];
        n->right->node_array[s]->parent = n->right;
    }
    left->no_of_values = left->no_of_values - n->right->no_of_values;
    return n;
}

void BTree::print(){
    print(root_node);
}

void BTree::print(Node* ptr){
    if(ptr == nullptr){    return;    }
    int i=0;
    for(i;i<ptr->no_of_values;i++){
        print(ptr->node_array[i]);
        cout<<ptr->info_array[i]<<"   ";
    }
    print(ptr->node_array[i]);
}