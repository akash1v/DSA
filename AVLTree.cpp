#include<iostream>
using namespace std;

class LRHeight{
public:
    int left{};
    int right{};
};

template<typename t>
class Node{
public:
    t info{};
    Node<t>* right{};
    Node<t>* left{};
    Node<t>* parent{};

    Node(t data){    info = data;    }
};


template<typename t>
class AVLTree{
private :

    Node<t>* root_node{};

    void insert(Node<t>*,Node<t>*);
    void remove(Node<t>*);
    Node<t>* search(Node<t>*, t&);
    void copy(Node<t>*);

    LRHeight height(Node<t>*);
    int maxOf(LRHeight);

    void printInOrder(Node<t>*);
    void printReverseOrder(Node<t>*);
    void printPreOrder(Node<t>*);
    void printPostOrder(Node<t>*);
    void printPath(Node<t>* ,t*,int &);

    Node<t>* minimum(Node<t>*);
    Node<t>* maximum(Node<t>*);

    void AVLLeafCheck(Node<t>*);
    void AVLBranchCheck(Node<t>*);
    void LLLeaf(Node<t>*);
    void LRLeaf(Node<t>*);
    void RLLeaf(Node<t>*);
    void RRLeaf(Node<t>*);
    void LLBranch(Node<t>*);
    void RRBranch(Node<t>*);
    void UpdateBranch(Node<t>*,Node<t>*,Node<t>*);

    void destruct(Node<t>*);
public:

    AVLTree(){};
    AVLTree(AVLTree<t>&);

    void insert(t);
    void remove(t);
    bool search(t);
    
    int height();

    void printInOrder();
    void printReverseOrder();
    void printPreOrder();
    void printPostOrder();
    void printPath();
    
    t minimum();
    t maximum();
    t predecessor(t);
    t successor(t);
    
    ~AVLTree();
};

template<typename t>
AVLTree<t>::AVLTree(AVLTree<t>& avl){
    copy(avl.root_node);
}

template<typename t>
void AVLTree<t>::copy(Node<t>* node){
    if(node == nullptr){    return;    }
    insert(node->info);
    copy(node->left);
    copy(node->right);
}

template<typename t>
void AVLTree<t>::insert(t data){
    Node<t>* new_node = new Node<t>(data);

    if(root_node){
        insert(root_node,new_node);
    }
    else{
        root_node = new_node;
        new_node = nullptr;
    };
};

template<typename t>
void AVLTree<t>::insert(Node<t>* ptr, Node<t>* new_node){
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

template<typename t>
bool AVLTree<t>::search(t data){
    return search(root_node,data);
};

template<typename t>
Node<t>* AVLTree<t>::search(Node<t>* ptr, t & data){
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

template<typename t>
int AVLTree<t>::height(){
    return maxOf(height(root_node));
}

template<typename t>
LRHeight AVLTree<t>::height(Node<t>* ptr){    
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

template<typename t>
int AVLTree<t>::maxOf(LRHeight ptr){
    return ptr.left > ptr.right ? ptr.left : ptr.right;
}

template<typename t>
void AVLTree<t>::printInOrder(){
    printInOrder(root_node);
}

template<typename t>
void AVLTree<t>::printInOrder(Node<t>* ptr){
    if(!ptr){    return;    }
    printInOrder(ptr->left);
    cout<<ptr->info<<"  ";
    printInOrder(ptr->right);
}

template<typename t>
void AVLTree<t>::printReverseOrder(){
    printReverseOrder(root_node);
}

template<typename t>
void AVLTree<t>::printReverseOrder(Node<t>* ptr){
    if(!ptr){    return;    }
    printReverseOrder(ptr->right);
    cout<<ptr->info<<"  ";
    printReverseOrder(ptr->left);

}

template<typename t>
void AVLTree<t>::printPreOrder(){
    printPreOrder(root_node);
}

template<typename t>
void AVLTree<t>::printPreOrder(Node<t>* ptr){
    if(!ptr){    return;    }
    cout<<ptr->info<<"  ";
    printPreOrder(ptr->left);
    printPreOrder(ptr->right);
}


template<typename t>
void AVLTree<t>::printPostOrder(){
    printPostOrder(root_node);
}

template<typename t>
void AVLTree<t>::printPostOrder(Node<t>* ptr){
    if(!ptr){    return;    }
    cout<<ptr->info<<"  ";
    printPostOrder(ptr->left);
    printPostOrder(ptr->right);
}


template<typename t>
void AVLTree<t>::printPath(){
    if(!root_node){    return;     }
    t* array = new int[maxOf(height(root_node))+1];
    int count = 0;
    printPath(root_node,array,count);
}

template<typename t>
void AVLTree<t>::printPath(Node<t>* ptr,t* array,int &count){
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

template<typename t>
t AVLTree<t>::minimum(){
    Node<t>* ptr = minimum(root_node);
    if(ptr){   return ptr->info;   };
    return 0;
}

template<typename t>
Node<t>* AVLTree<t>::minimum(Node<t>* ptr){
    if(ptr){
        while(ptr->left){
            ptr = ptr->left;
        }
        return ptr;
    }
    return ptr;
}


template<typename t>
t AVLTree<t>::maximum(){
    Node<t>* ptr = maximum(root_node);
    if(ptr){   return ptr->info;   };
    return 0;
}

template<typename t>
Node<t>* AVLTree<t>::maximum(Node<t>* ptr){
    if(ptr){
        while(ptr->right){
            ptr = ptr->right;
        }
        return ptr;
    }
    return ptr;
}



template<typename t>
t AVLTree<t>::predecessor(t data){
    Node<t>* temp = search(root_node, data);
    if(!temp){
        return 0;
    }
    Node<t>* temp2 = maximum(temp->left);
    if(temp2){
        return temp2->info;    
    }
    while (temp->parent)
    {
        if(temp->parent->info < data){
            return temp->parent->info;
        }
        temp = temp->parent;
    }
    
    return 0;
}

template<typename t>
t AVLTree<t>::successor(t data){
    Node<t>* temp = search(root_node, data);
    if(!temp){    
        return 0;
    }
    Node<t>* temp2 = minimum(temp->right);
    if(temp2){
        return temp2->info;
    }
    while (temp->parent)
    {
        if(temp->parent->info > data){
            return temp->parent->info;
        }
        temp = temp->parent;
    }
    return 0;
}

template<typename t>
void AVLTree<t>::remove(t data){
    Node<t>* temp;
    temp = search(root_node,data);
    if(temp){    
        remove(temp);
    }
}

template<typename t>
void AVLTree<t>::remove(Node<t>* ptr){

    Node<t>* temp{};
    if(ptr->right){    temp = minimum(ptr->right);    }
    if(!temp && ptr->left){    temp = maximum(ptr->left);    }

    if(temp){
        ptr->info = temp->info;
        return remove(temp);
    }
    else{
        if(ptr->parent == nullptr){
            root_node = nullptr;
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

template<typename t>
void AVLTree<t>::AVLLeafCheck(Node<t>* ptr){
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

template<typename t>
void AVLTree<t>::UpdateBranch(Node<t>* parent,Node<t>* old_child,Node<t>* new_child){
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

template<typename t>
void AVLTree<t>::LLLeaf(Node<t>* ptr){
    Node<t>* temp = ptr->left;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->right = ptr;
    temp->right->parent = temp;
    ptr->left = nullptr;
    ptr = nullptr;
};

template<typename t>
void AVLTree<t>::RRLeaf(Node<t>* ptr){
    Node<t>* temp = ptr->right;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->left = ptr;
    temp->left->parent = temp;
    ptr->right = nullptr;
    ptr = nullptr;
};

template<typename t>
void AVLTree<t>::LRLeaf(Node<t>* ptr){
    Node<t>* temp = ptr->left->right;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->right = ptr;
    temp->right->parent = temp;
    temp->left = ptr->left;
    temp->left->parent = temp;
    ptr->left = nullptr;
    ptr->left->right = nullptr;
    ptr = nullptr;
};

template<typename t>
void AVLTree<t>::RLLeaf(Node<t>* ptr){
    Node<t>* temp = ptr->right->left;
    UpdateBranch(ptr->parent,ptr,temp);
    temp->left = ptr;
    temp->left->parent = temp;
    temp->right = ptr->right;
    temp->right->parent = temp;
    ptr->right = nullptr;
    ptr->right->left = nullptr;
    ptr = nullptr;
};

template<typename t>
void AVLTree<t>::AVLBranchCheck(Node<t>* ptr){
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

template<typename t>
void AVLTree<t>::LLBranch(Node<t>* ptr){
    Node<t>* temp = ptr->left;
    UpdateBranch(ptr->parent,ptr,temp);
    ptr->left = temp->right;
    ptr->left->parent = ptr;
    temp->right = ptr;
    temp->right->parent = temp;
    ptr = nullptr;    
};

template<typename t>
void AVLTree<t>::RRBranch(Node<t>* ptr){
    Node<t>* temp = ptr->right;
    UpdateBranch(ptr->parent,ptr,temp);
    ptr->right = temp->left;
    ptr->right->parent = ptr;
    temp->left = ptr;
    temp->left->parent = temp;
    ptr=nullptr;
};

template<typename t>
void AVLTree<t>::destruct(Node<t>* ptr){
    if(!ptr){   return;    }
    destruct(ptr->left);
    destruct(ptr->right);
    delete(ptr);
}

template<typename t>
AVLTree<t>::~AVLTree(){
    destruct(root_node);
}