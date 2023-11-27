#include<iostream>
using namespace std;

class LRHeight{
public:
    int left{};
    int right{};
};

class Node{
public:
    int info{};
    Node* right{};
    Node* left{};
    Node* parent{};
};

class AVLTree{
private :

    Node* root_node{};

    void insert(Node*,Node*);
    void remove(Node*);
    Node* search(Node*,int &);
    
    LRHeight height(Node*);
    int maxOf(LRHeight);

    void printInOrder(Node*);
    void printReverseOrder(Node*);
    void printPreOrder(Node*);
    void printPostOrder(Node*);
    void printPath(Node* ,int*,int &);


    Node* predecessor(Node*,int &);
    Node* successor(Node*,int &);
    Node* minimum(Node*);
    Node* maximum(Node*);

    void AVLLeafCheck(Node*);
    void AVLBranchCheck(Node*);
    void LLLeaf(Node*);
    void LRLeaf(Node*);
    void RLLeaf(Node*);
    void RRLeaf(Node*);
    void LLBranch(Node*);
    void RRBranch(Node*);
    void UpdateBranch(Node*,Node*,Node*);

    void destruct(Node*);
public:

    void insert(int);
    bool remove(int);
    bool search(int);
    
    int height();

    void printInOrder();
    void printReverseOrder();
    void printPreOrder();
    void printPostOrder();
    void printPath();
    
    int minimum();
    int maximum();
    int predecessor(int);
    int successor(int);
    
    ~AVLTree();
};


void AVLTree::insert(int data){
    Node* new_node = new Node();
    new_node->info = data;
    if(root_node){
        insert(root_node,new_node);
    }
    else{
        root_node = new_node;
        new_node = nullptr;
    };
};

void AVLTree::insert(Node* ptr, Node* new_node){
    if(new_node->info<ptr->info){
        if(ptr->left){
            insert(ptr->left,new_node);
        }
        else{
            new_node->parent = ptr;
            ptr->left = new_node;
            new_node = nullptr;
            if(ptr->parent){
                AVLLeafCheck(ptr->parent);
            }
        }
    }
    else{
        if(ptr->right){
            insert(ptr->right,new_node);
        }
        else{
            new_node->parent = ptr;
            ptr->right = new_node;
            new_node = nullptr;
            if(ptr->parent){
                AVLLeafCheck(ptr->parent);
            }
        }
    }
};

bool AVLTree::search(int data){
    return search(root_node,data);
};

Node* AVLTree::search(Node* ptr, int & data){
    if(!ptr){    return nullptr;    }
    
    if(data == ptr->info){
        return ptr;
    }
    else if(data<ptr->info){
        return search(ptr->left,data);
    }
    else{
        return search(ptr->right,data);
    }
};

int AVLTree::height(){
    return maxOf(height(root_node));
}

LRHeight AVLTree::height(Node* ptr){    
    LRHeight h;
    if(ptr){
        if(ptr->left){
            h.left = 1 + maxOf(height(ptr->left));
        }
        if(ptr->right){
            h.right = 1 + maxOf(height(ptr->right));
        }
    }
    return h;
}

int AVLTree::maxOf(LRHeight ptr){
    return ptr.left > ptr.right ? ptr.left : ptr.right;
}

void AVLTree::printInOrder(){
    printInOrder(root_node);
}

void AVLTree::printInOrder(Node* ptr){
    if(!ptr){    return;    }
    printInOrder(ptr->left);
    cout<<ptr->info<<"  ";
    printInOrder(ptr->right);
}

void AVLTree::printReverseOrder(){
    printInOrder(root_node);
}

void AVLTree::printReverseOrder(Node* ptr){
    if(!ptr){    return;    }
    printReverseOrder(ptr->right);
    cout<<ptr->info<<"  ";
    printReverseOrder(ptr->left);

}

void AVLTree::printPreOrder(){
    printPreOrder(root_node);
}

void AVLTree::printPreOrder(Node* ptr){
    if(!ptr){    return;    }
    cout<<ptr->info<<"  ";
    printPreOrder(ptr->left);
    printPreOrder(ptr->right);
}


void AVLTree::printPostOrder(){
    printPostOrder(root_node);
}

void AVLTree::printPostOrder(Node* ptr){
    if(!ptr){    return;    }
    cout<<ptr->info<<"  ";
    printPostOrder(ptr->left);
    printPostOrder(ptr->right);
}


void AVLTree::printPath(){
    if(!root_node){    return;     }
    int* array;
    array = new int[maxOf(height(root_node))+1];
    int count = 0;
    printPath(root_node,array,count);
}

void AVLTree::printPath(Node* ptr,int* array,int &count){
    array[count] = ptr->info;
    count++;
    if(!ptr->left  &&  !ptr->right){
        for(int i=0;i<count;i++){
            cout<<array[i]<<"  ";
        }
        cout<<endl;
    }else{
        if(ptr->left){
            printPath(ptr->left,array,count);
            count--;
        }
        if(ptr->right){
            printPath(ptr->right,array,count);
            count--;
        }
    }
}

int AVLTree::minimum(){
    Node* ptr = minimum(root_node);
    if(ptr){   return ptr->info;   };
    return 0;
}

Node* AVLTree::minimum(Node* ptr){
    if(ptr){
        while(ptr->left){
            ptr = ptr->left;
        }
        return ptr;
    }
    return ptr;
}


int AVLTree::maximum(){
    Node* ptr = maximum(root_node);
    if(ptr){   return ptr->info;   };
    return 0;
}

Node* AVLTree::maximum(Node* ptr){
    if(ptr){
        while(ptr->right){
            ptr = ptr->right;
        }
        return ptr;
    }
    return ptr;
}



int AVLTree::predecessor(int data){
    Node* temp = search(root_node, data);
    if(!temp){
        return 0;
    }
    Node* temp2 = predecessor(temp, data);
    if(temp2){
        return temp->info;    
    }
    if(temp->parent && temp->parent->info < temp->info){
        return temp->parent->info;  
    };
    return 0;
}

Node* AVLTree::predecessor(Node* ptr,int & data ){
    if(!ptr){  return ptr;  }

    if(data > ptr->info ){
        if(ptr->right){
            if(data <= minimum(ptr->right)->info){
                return ptr;
            }
            else{
                return predecessor(ptr->right,data);
            }
        }
        else{
            return ptr;
        }
    }
    else{
        return predecessor(ptr->left,data);
    }
};

int AVLTree::successor(int data){
    Node* temp = search(root_node, data);
    if(!temp){    
        return 0;
    }
    Node* temp2 = successor(temp, data);
    if(temp2){
        return temp2->info;
    }
    if(temp->parent && temp->parent->info < temp->info){
        return temp->parent->info;  
    };
    return 0;
}

Node* AVLTree::successor(Node* ptr,int & data){
    if(!ptr){  return ptr;  }

    if(data < ptr->info ){
        if(ptr->left){
            if(data >= maximum(ptr->left)->info){
                return ptr;
            }
            else{
                return successor(ptr->left,data);
            }
        }
        else{
            return ptr;
        }
    }
    else{
        return successor(ptr->right,data);
    }
};

bool AVLTree::remove(int data){
    Node* temp;
    temp = search(root_node,data);
    if(temp){    
        remove(temp);
        return true;
    }
    return false;
}

void AVLTree::remove(Node* ptr){
    Node* temp;
    temp = successor(ptr,ptr->info);
    if(!temp){    temp = predecessor(ptr,ptr->info);    }
    if(temp){
        ptr->info = temp->info;
        return remove(temp);
    }
    else{
        if(ptr->parent == nullptr){
            root_node = nullptr;
            return;
        }
        else if(ptr->parent->right == ptr){
            ptr->parent->right = nullptr;
        }
        else{
            ptr->parent->left = nullptr;
        }
        temp = ptr->parent;
        delete(ptr);
        AVLBranchCheck(temp);
    }
}

void AVLTree::AVLLeafCheck(Node* ptr){
    LRHeight h,h2;
    h = height(ptr);
    if(h.left-h.right > 1){
        h2 = height(ptr->left);        
        if(h2.left > h2.right){  LLLeaf(ptr);  }
        else{  LRLeaf(ptr);  }
    }
    if(h.right-h.left > 1){   
        h2 = height(ptr->right);
        if(h2.right > h2.left){  RRLeaf(ptr);  }
        else{  RLLeaf(ptr);  }
    }
    AVLBranchCheck(ptr->parent);
};

void AVLTree::UpdateBranch(Node* parent,Node* old_child,Node* new_child){
    if(!parent){
        root_node = new_child;
    }
    else if(parent->right == old_child){
        parent->right = new_child;
    }
    else{
        parent->left = new_child;
    }
    new_child->parent = parent;
}

void AVLTree::LLLeaf(Node* ptr){
    Node* temp = ptr->left;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->right = ptr;
    temp->right->parent = temp;
    ptr->left = nullptr;
    ptr = nullptr;
};

void AVLTree::RRLeaf(Node* ptr){
    Node* temp = ptr->right;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->left = ptr;
    temp->left->parent = temp;
    ptr->right = nullptr;
    ptr = nullptr;
};

void AVLTree::LRLeaf(Node* ptr){
    Node* temp = ptr->left->right;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->right = ptr;
    temp->right->parent = temp;
    temp->left = ptr->left;
    temp->left->parent = temp;
    ptr->left = nullptr;
    ptr->left->right = nullptr;
    ptr = nullptr;
};

void AVLTree::RLLeaf(Node* ptr){
    Node* temp = ptr->right->left;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->left = ptr;
    temp->left->parent = temp;
    temp->right = ptr->right;
    temp->right->parent = temp;
    ptr->right = nullptr;
    ptr->right->left = nullptr;
    ptr = nullptr;
};

void AVLTree::AVLBranchCheck(Node* ptr){
    if(!ptr){    return;    }
    LRHeight h,h2;
    h = height(ptr);
    if(h.left - h.right > 1){
        h2 = height(ptr->left);
        if(h2.left >= h2.right){  LLBranch(ptr);  }
        else{   RRBranch(ptr->left);    LLBranch(ptr);  }
        return;
    }
    if(h.right - h.left > 1){
        h2 = height(ptr->right);
        if(h2.right >= h2.left){    RRBranch(ptr);  }
        else{    LLBranch(ptr->right);    RRBranch(ptr);    }
        return;    
    }
    AVLBranchCheck(ptr->parent);
};

void AVLTree::LLBranch(Node* ptr){
    Node* temp = ptr->left;
    UpdateBranch(ptr->parent,ptr,temp);
    ptr->left = temp->right;
    ptr->left->parent = ptr;
    temp->right = ptr;
    temp->right->parent = temp;
    ptr = nullptr;    
};

void AVLTree::RRBranch(Node* ptr){
    Node* temp = ptr->right;
    UpdateBranch(ptr->parent,ptr,temp);
    ptr->right = temp->left;
    ptr->right->parent = ptr;
    temp->left = ptr;
    ptr->left->parent = temp;
    ptr=nullptr;
};

void AVLTree::destruct(Node* ptr){
    if(!ptr){   return;    }
    destruct(ptr->left);
    destruct(ptr->right);
    delete(ptr);
}

AVLTree::~AVLTree(){
    destruct(root_node);
}