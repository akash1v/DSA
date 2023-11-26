#include<iostream>
using namespace std;

class HeightNode{
public:
    int left{};
    int right{};
};

class AVLTreeNode{
public:
    int info{};
    AVLTreeNode* right{};
    AVLTreeNode* left{};
    AVLTreeNode* parent{};
};

class AVLTree{
private :

    AVLTreeNode* node{};

    void insert(AVLTreeNode*,AVLTreeNode*);
    void remove(AVLTreeNode*);
    AVLTreeNode* search(AVLTreeNode*,int &);
    
    HeightNode height(AVLTreeNode*);
    int maxOf(HeightNode);

    void printInOrder(AVLTreeNode*);
    void printReverseOrder(AVLTreeNode*);
    void printPreOrder(AVLTreeNode*);
    void printPostOrder(AVLTreeNode*);
    void printPath(AVLTreeNode* ,int*,int &);


    AVLTreeNode* predecessor(AVLTreeNode*,int &);
    AVLTreeNode* successor(AVLTreeNode*,int &);
    AVLTreeNode* minimum(AVLTreeNode*);
    AVLTreeNode* maximum(AVLTreeNode*);

    void AVLLeafCheck(AVLTreeNode*);
    void AVLBranchCheck(AVLTreeNode*);
    void LLLeaf(AVLTreeNode*);
    void LRLeaf(AVLTreeNode*);
    void RLLeaf(AVLTreeNode*);
    void RRLeaf(AVLTreeNode*);
    void LLBranch(AVLTreeNode*);
    void RRBranch(AVLTreeNode*);
    void UpdateBranch(AVLTreeNode*,AVLTreeNode*,AVLTreeNode*);

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
};


void AVLTree::insert(int val){
    AVLTreeNode* new_node = new AVLTreeNode();
    new_node->info = val;
    if(node){
        insert(node,new_node);
    }
    else{
        node = new_node;
        new_node = nullptr;
    };
};

void AVLTree::insert(AVLTreeNode* ptr, AVLTreeNode* new_node){
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

bool AVLTree::search(int val){
    return search(node,val);
};

AVLTreeNode* AVLTree::search(AVLTreeNode* ptr, int & val){
    if(!ptr){    return nullptr;    }
    
    if(val == ptr->info){
        return ptr;
    }
    else if(val<ptr->info){
        return search(ptr->left,val);
    }
    else{
        return search(ptr->right,val);
    }
};

int AVLTree::height(){
    return maxOf(height(node));
}

HeightNode AVLTree::height(AVLTreeNode* ptr){    
    HeightNode h;
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

int AVLTree::maxOf(HeightNode ptr){
    return ptr.left > ptr.right ? ptr.left : ptr.right;
}

void AVLTree::printInOrder(){
    printInOrder(node);
}

void AVLTree::printInOrder(AVLTreeNode* ptr){
    if(!ptr){    return;    }
    printInOrder(ptr->left);
    cout<<ptr->info<<"  ";
    printInOrder(ptr->right);
}

void AVLTree::printReverseOrder(){
    printInOrder(node);
}

void AVLTree::printReverseOrder(AVLTreeNode* ptr){
    if(!ptr){    return;    }
    printReverseOrder(ptr->right);
    cout<<ptr->info<<"  ";
    printReverseOrder(ptr->left);

}

void AVLTree::printPreOrder(){
    printPreOrder(node);
}

void AVLTree::printPreOrder(AVLTreeNode* ptr){
    if(!ptr){    return;    }
    cout<<ptr->info<<"  ";
    printPreOrder(ptr->left);
    printPreOrder(ptr->right);
}


void AVLTree::printPostOrder(){
    printPostOrder(node);
}

void AVLTree::printPostOrder(AVLTreeNode* ptr){
    if(!ptr){    return;    }
    cout<<ptr->info<<"  ";
    printPostOrder(ptr->left);
    printPostOrder(ptr->right);
}


void AVLTree::printPath(){
    if(!node){    return;     }
    int* p;
    p = new int[maxOf(height(node))+1];
    int count = 0;
    printPath(node,p,count);
}

void AVLTree::printPath(AVLTreeNode* ptr,int* arr,int &count){
    arr[count] = ptr->info;
    count++;
    if(!ptr->left  &&  !ptr->right){
        for(int i=0;i<count;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }else{
        if(ptr->left){
            printPath(ptr->left,arr,count);
            count--;
        }
        if(ptr->right){
            printPath(ptr->right,arr,count);
            count--;
        }
    }
}

int AVLTree::minimum(){
    AVLTreeNode* ptr = minimum(node);
    if(ptr){   return ptr->info;   };
    return 0;
}

AVLTreeNode* AVLTree::minimum(AVLTreeNode* ptr){
    if(ptr){
        while(ptr->left){
            ptr = ptr->left;
        }
        return ptr;
    }
    return ptr;
}


int AVLTree::maximum(){
    AVLTreeNode* ptr = maximum(node);
    if(ptr){   return ptr->info;   };
    return 0;
}

AVLTreeNode* AVLTree::maximum(AVLTreeNode* ptr){
    if(ptr){
        while(ptr->right){
            ptr = ptr->right;
        }
        return ptr;
    }
    return ptr;
}



int AVLTree::predecessor(int a){
    AVLTreeNode* temp = search(node, a);
    if(!temp){
        return 0;
    }
    AVLTreeNode* temp2 = predecessor(temp, a);
    if(temp2){
        return temp->info;    
    }
    if(temp->parent && temp->parent->info < temp->info){
        return temp->parent->info;  
    };
    return 0;
}

AVLTreeNode* AVLTree::predecessor(AVLTreeNode* ptr,int &a){
    if(!ptr){  return ptr;  }

    if(a > ptr->info ){
        if(ptr->right){
            if(a <= minimum(ptr->right)->info){
                return ptr;
            }
            else{
                return predecessor(ptr->right,a);
            }
        }
        else{
            return ptr;
        }
    }
    else{
        return predecessor(ptr->left,a);
    }
};

int AVLTree::successor(int a){
    AVLTreeNode* temp = search(node, a);
    if(!temp){    
        return 0;
    }
    AVLTreeNode* temp2 = successor(temp, a);
    if(temp2){
        return temp2->info;
    }
    if(temp->parent && temp->parent->info < temp->info){
        return temp->parent->info;  
    };
    return 0;
}

AVLTreeNode* AVLTree::successor(AVLTreeNode* ptr,int &a){
    if(!ptr){  return ptr;  }

    if(a < ptr->info ){
        if(ptr->left){
            if(a >= maximum(ptr->left)->info){
                return ptr;
            }
            else{
                return successor(ptr->left,a);
            }
        }
        else{
            return ptr;
        }
    }
    else{
        return successor(ptr->right,a);
    }
};

bool AVLTree::remove(int a){
    AVLTreeNode* temp;
    temp = search(node,a);
    if(temp){    
        remove(temp);
        return true;
    }
    return false;
}

void AVLTree::remove(AVLTreeNode* ptr){
    AVLTreeNode* temp;
    temp = successor(ptr,ptr->info);
    if(!temp){    temp = predecessor(ptr,ptr->info);    }
    if(temp){
        ptr->info = temp->info;
        return remove(temp);
    }
    else{
        if(ptr->parent == nullptr){
            node = nullptr;
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

void AVLTree::AVLLeafCheck(AVLTreeNode* ptr){
    HeightNode h,h2;
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

void AVLTree::UpdateBranch(AVLTreeNode* parent,AVLTreeNode* old_child,AVLTreeNode* new_child){
    if(!parent){
        node = new_child;
    }
    else if(parent->right == old_child){
        parent->right = new_child;
    }
    else{
        parent->left = new_child;
    }
    new_child->parent = parent;
}

void AVLTree::LLLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->left;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->right = ptr;
    temp->right->parent = temp;
    ptr->left = nullptr;
    ptr = nullptr;
};

void AVLTree::RRLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->right;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->left = ptr;
    temp->left->parent = temp;
    ptr->right = nullptr;
    ptr = nullptr;
};

void AVLTree::LRLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->left->right;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->right = ptr;
    temp->right->parent = temp;
    temp->left = ptr->left;
    temp->left->parent = temp;
    ptr->left = nullptr;
    ptr->left->right = nullptr;
    ptr = nullptr;
};

void AVLTree::RLLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->right->left;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->left = ptr;
    temp->left->parent = temp;
    temp->right = ptr->right;
    temp->right->parent = temp;
    ptr->right = nullptr;
    ptr->right->left = nullptr;
    ptr = nullptr;
};

void AVLTree::AVLBranchCheck(AVLTreeNode* ptr){
    if(!ptr){    return;    }
    HeightNode h,h2;
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

void AVLTree::LLBranch(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->left;
    UpdateBranch(ptr->parent,ptr,temp);
    ptr->left = temp->right;
    ptr->left->parent = ptr;
    temp->right = ptr;
    temp->right->parent = temp;
    ptr = nullptr;    
};

void AVLTree::RRBranch(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->right;
    UpdateBranch(ptr->parent,ptr,temp);
    ptr->right = temp->left;
    ptr->right->parent = ptr;
    temp->left = ptr;
    ptr->left->parent = temp;
    ptr=nullptr;
};