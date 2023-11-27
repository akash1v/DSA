#include<iostream>
using namespace std;
class BTreeNode{
public:
    int* data_array{};
    int no_of_values{};
    BTreeNode* parent{};
    BTreeNode** node_array{};

    BTreeNode(int a){
        data_array = new int [a]{};
        node_array = new BTreeNode*[a+1]{};
    };
};

class KeyNNode{
public:
    int key{};
    BTreeNode* right{};
};

class BTree
{
private:
    BTreeNode* node;
    int size{};

    BTreeNode* makeParent(BTreeNode*,int &,BTreeNode*);
    int getLocation(BTreeNode*, int &);
    bool spaceAvailable(BTreeNode*);
    void makeSpace(BTreeNode*, int&, bool);
    void override(BTreeNode*, int &, BTreeNode*);
    KeyNNode* breakNode(BTreeNode*, bool);
    
    void print(BTreeNode*);
    
public:
    BTree();
    BTree(int);
    void insert(int);
    bool search(int);
    void print();
};

BTree::BTree(){
    size = 100;
    node = new BTreeNode(size);
}

BTree::BTree(int a){
    if(a < 2){  BTree(); }
    size = a;
    node = new BTreeNode(size);
}

void BTree::insert(int val){
    BTreeNode* temp = node;

    while(true){
        int i = getLocation(temp,val);
        if(temp->node_array[i] == nullptr){   break;  };
        temp = temp->node_array[i];
    }

    override(temp, val, nullptr);
    if(spaceAvailable(temp)){
        temp->no_of_values++;
        return;
    }

    KeyNNode* knn = breakNode(temp, false);

    while (true){
        BTreeNode* parent = temp->parent;
        if(parent == nullptr){
            node = makeParent(temp, knn->key, knn->right);
            node->no_of_values++;
            return;
        }
        temp = parent;
        override(temp, knn->key, knn->right);
        if(spaceAvailable(temp)){
            temp->no_of_values++;
            return;
        }
        knn = breakNode(temp,true);
    }
}

bool BTree::search(int val){
    BTreeNode* temp = node;
    while(true){
        int i = getLocation(temp,val);
        if(val == temp->data_array[i]){    return true;    }
        if(temp->node_array[i] == nullptr){   return false;  };
        temp = temp->node_array[i];
    }    
}

BTreeNode* BTree::makeParent(BTreeNode* left,int &val,BTreeNode* right){
    BTreeNode* parent = new BTreeNode(size);
    parent->data_array[0] = val;
    parent->node_array[0] = left;
    parent->node_array[1] = right;
    left->parent = parent;
    right->parent = parent;
    return parent;
};

bool BTree::spaceAvailable(BTreeNode* ptr){
    if(ptr->no_of_values<size-1){
        return true;
    }
    return false;
}

int BTree::getLocation(BTreeNode* ptr, int& val){
    int i=0;
    for(i;  i != ptr->no_of_values  && val > ptr->data_array[i]; i++);
    return i;
}

void BTree::makeSpace(BTreeNode* ptr, int& i,bool branch_node){
    for(int j = ptr->no_of_values ; j>i ;j--){
        ptr->data_array[j] = ptr->data_array[j-1];
        if(branch_node){
            ptr->node_array[j+1] = ptr->node_array[j];
        }
    }
}

void BTree::override(BTreeNode* ptr, int& val, BTreeNode* right){
    int i= getLocation(ptr, val);
    makeSpace(ptr, i, right);
    ptr->data_array[i] = val;
    if(right){
        ptr->node_array[i+1] = right;
        right->parent = ptr;
    }
}

KeyNNode* BTree::breakNode(BTreeNode* left,bool branch_node = false){

    KeyNNode* n = new KeyNNode();
    n->key = left->data_array[size/2];
    n->right = new BTreeNode(size);
    n->right->parent = left->parent;

    int i = (size/2)+1;
    int s=0;

    for(i, s=0; i < size; i++, s++ ){
        n->right->data_array[s] = left->data_array[i];
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
    print(node);
}

void BTree::print(BTreeNode* ptr){
    if(ptr == nullptr){    return;    }
    int i=0;
    for(i;i<ptr->no_of_values;i++){
        print(ptr->node_array[i]);
        cout<<ptr->data_array[i]<<"   ";
    }
    print(ptr->node_array[i]);
}