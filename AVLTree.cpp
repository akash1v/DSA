#include<iostream>
using namespace std;


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
    int height(AVLTreeNode*);

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
    void LLLeaf(AVLTreeNode*);
    void LRLeaf(AVLTreeNode*);
    void RLLeaf(AVLTreeNode*);
    void RRLeaf(AVLTreeNode*);

    void AVLBranchCheck(AVLTreeNode*);
    void LLBranch(AVLTreeNode*);
    void RRBranch(AVLTreeNode*);
    
    public:


    void insert(int);
    void remove(int);
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
    if(!node){
        node = new_node;
        new_node = nullptr;
        delete(new_node);
    }else{
        insert(node,new_node);
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
            delete(new_node);
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
            delete(new_node);
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
    if(!ptr){
        return nullptr;
    }
    else if(val == ptr->info){
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
    return height(node);
}

int AVLTree::height(AVLTreeNode* ptr){
    if((!ptr) || (!ptr->left && !ptr->right)){
        return 0;
    }
    else{
        int left = 1 + height(ptr->left);
        int right = 1 + height(ptr->right);
        return left>right?left:right;
    }
}

void AVLTree::printInOrder(){
    printInOrder(node);
}

void AVLTree::printInOrder(AVLTreeNode* ptr){
    if(!ptr){
        return;
    }
    printInOrder(ptr->left);
    cout<<ptr->info<<endl;
    printInOrder(ptr->right);
}

void AVLTree::printReverseOrder(){
    printInOrder(node);
}

void AVLTree::printReverseOrder(AVLTreeNode* ptr){
    if(!ptr){
        return;
    }
    printReverseOrder(ptr->right);
    cout<<ptr->info<<endl;
    printReverseOrder(ptr->left);
}

void AVLTree::printPreOrder(){
    printPreOrder(node);
}

void AVLTree::printPreOrder(AVLTreeNode* ptr){
    if(!ptr){
        return;
    }
    cout<<ptr->info<<endl;
    printPreOrder(ptr->left);
    printPreOrder(ptr->right);
}


void AVLTree::printPostOrder(){
    printPostOrder(node);
}

void AVLTree::printPostOrder(AVLTreeNode* ptr){
    if(!ptr){
        return;
    }
    cout<<ptr->info<<endl;
    printPostOrder(ptr->left);
    printPostOrder(ptr->right);
}


void AVLTree::printPath(){
    if(!node){  return;     }
    int* p;
    p = new int[height(node)];
    int count = 0;
    printPath(node,p,count);
}

void AVLTree::printPath(AVLTreeNode* ptr,int* arr,int &count){
    arr[count] = ptr->info;
    count++;
    if(!ptr->left  &&  !ptr->right){
        for(int i=0;i<count;i++){
            cout<<arr[i]<<", ";
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
    AVLTreeNode* ptr{};
    ptr = minimum(node);
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
    AVLTreeNode* ptr{};
    ptr = maximum(node);
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
    if(temp==nullptr){    
        temp = predecessor(node, a);
        if(temp!=nullptr){    return temp->info;    }
        return 0;
    }else{
        temp = predecessor(temp, a);
        if(temp!=nullptr){    return temp->info;    }
        if(temp->parent->info < temp->info){    return temp->parent->info;  };
        return 0;
    }
}

AVLTreeNode* AVLTree::predecessor(AVLTreeNode* ptr,int &a){
    if(!ptr){  return ptr;  }

    if(a > ptr->info ){
        if(ptr->right){
            if(a <= minimum(ptr->right)->info){
                return ptr;
            }else{
                return predecessor(ptr->right,a);
            }
        }else{
            return ptr;
        }
    }else{
        return predecessor(ptr->left,a);
    }
};

int AVLTree::successor(int a){
    AVLTreeNode* temp = search(node, a);
    if(temp==nullptr){    
        temp = predecessor(node, a);
        if(temp!=nullptr){    return temp->info;    }
        return 0;
    }else{
        temp = predecessor(temp, a);
        if(temp!=nullptr){    return temp->info;    }
        if(temp->parent->info < temp->info){    return temp->parent->info;  };
        return 0;
    }
}

AVLTreeNode* AVLTree::successor(AVLTreeNode* ptr,int &a){
    if(!ptr){  return ptr;  }

    if(a < ptr->info ){
        if(ptr->left){
            if(a >= maximum(ptr->left)->info){
                return ptr;
            }else{
                return successor(ptr->left,a);
            }
        }else{
            return ptr;
        }
    }else{
        return successor(ptr->right,a);
    }
};

void AVLTree::remove(int a){
    AVLTreeNode* temp;
    temp = search(node,a);
    remove(temp);
}

void AVLTree::remove(AVLTreeNode* ptr){
    AVLTreeNode* temp;
    temp = successor(ptr,ptr->info);
    if(temp){
        ptr->info = temp->info;
    }else{
        temp = predecessor(ptr,ptr->info);
        if(temp){
            ptr->info = temp->info;
        }
    }

    if(!temp){
        if(ptr->parent->right == ptr){
            ptr->parent->right = nullptr;
        }else{
            ptr->parent->left = nullptr;
        }
        temp = ptr->parent;
        delete(ptr);
        AVLLeafCheck(temp);
    }else{
        return remove(temp);
    }
}

void AVLTree::AVLLeafCheck(AVLTreeNode* ptr){
    int lheight{},rheight{};
    if(ptr->left){  lheight = 1+height(ptr->left);  }
    if(ptr->right){ rheight = 1+height(ptr->right)  ;}

    if(lheight-rheight > 1 || lheight-rheight < -1){

        if(ptr->left){
            if(ptr->left->left){  LLLeaf(ptr);  }
            else{  LRLeaf(ptr);  }
        }
        else{
            if(ptr->right->right){  RRLeaf(ptr);  }
            else{  RLLeaf(ptr);  }
        }
        
    }

    while (ptr->parent)
    {
        AVLBranchCheck(ptr->parent);
        ptr = ptr->parent;
    };

};

void AVLTree::LLLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->left;
    if(!ptr->parent){  node = temp;  };
    temp->parent = ptr->parent;
    ptr->parent = temp;
    temp->right = ptr;
    ptr->left = nullptr;

    if(temp->parent){
        if(temp->parent->right == ptr){
            temp->parent->right = temp;
        }
        else{
            temp->parent->left = temp;
        }
    }
};

void AVLTree::LRLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->left->right;
    if(!ptr->parent){  node = temp;  };
    temp->parent = ptr->parent;
    temp->right = ptr;
    temp->left = ptr->left;
    temp->left->parent = temp;
    temp->right->parent = temp;
    temp->right->left = nullptr;
    temp->left->right = nullptr;

    if(temp->parent){
        if(temp->parent->right == ptr){
            temp->parent->right = temp;
        }
        else{
            temp->parent->left = temp;
        }
    }
};

void AVLTree::RLLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->right->left;
    if(!ptr->parent){  node = temp;  };
    temp->parent = ptr->parent;
    temp->left = ptr;
    temp->right = ptr->right;
    temp->left->parent = temp;
    temp->right->parent = temp;
    temp->right->left = nullptr;
    temp->left->right = nullptr;

    if(temp->parent){
        if(temp->parent->right == ptr){
            temp->parent->right = temp;
        }
        else{
            temp->parent->left = temp;
        }
    }
};

void AVLTree::RRLeaf(AVLTreeNode* ptr){
    AVLTreeNode* temp = ptr->right;
    if(!ptr->parent){  node = temp;  };
    temp->parent = ptr->parent;
    ptr->parent = temp;
    temp->left = ptr;
    ptr->right = nullptr;

    if(temp->parent){
        if(temp->parent->right == ptr){
            temp->parent->right = temp;
        }
        else{
            temp->parent->left = temp;
        }
    }
};

void AVLTree::AVLBranchCheck(AVLTreeNode* ptr){

    int lheight{},rheight{};
    if(ptr->left){  lheight = 1+height(ptr->left);  }
    if(ptr->right){ rheight = 1+height(ptr->right)  ;}

    if(lheight-rheight > 1 || lheight-rheight < -1){

        if(lheight-rheight>0){
            if(height(ptr->left->left) > height(ptr->left->right)){  LLBranch(ptr);  }
            else{   RRBranch(ptr->left);    LLBranch(ptr);  }
        }
        else{
            if(height(ptr->right->right) > height(ptr->right->left)){  RRBranch(ptr);  }
            else{  LLBranch(ptr->right);    RRBranch(ptr);  }
        }
    }

};

void AVLTree::LLBranch(AVLTreeNode* ptr){
    AVLTreeNode* temp;
    temp = ptr->left;
    ptr->left = temp->right;
    ptr->left->parent = ptr;
    temp->right = ptr;
    temp->parent = ptr->parent;
    ptr->parent = temp;
    
    if(temp->parent){
        if(temp->parent->right == ptr){
            temp->parent->right = temp;
        }
        else{
            temp->parent->left = temp;
        }
    }else{
        node = temp;
    }
};

void AVLTree::RRBranch(AVLTreeNode* ptr){
    AVLTreeNode* temp;
    temp = ptr->right;
    ptr->right = temp->left;
    ptr->right->parent = ptr;
    temp->left = ptr;
    temp->parent = ptr->parent;
    ptr->parent = temp;
    
    if(temp->parent){
        if(temp->parent->right == ptr){
            temp->parent->right = temp;
        }
        else{
            temp->parent->left = temp;
        }
    }else{
        node = temp;
    }

};