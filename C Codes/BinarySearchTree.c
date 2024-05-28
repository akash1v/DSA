#include<stdio.h>
#include<stdlib.h>
struct BSTNode{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
    struct BSTNode* parent;
};

struct BSTNode* getBSTNode(int val){
    struct BSTNode* temp = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

struct BST{
    struct BSTNode* node;
};

struct BST* getBST(){
    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
    temp->node = NULL;
    return temp;
}

void insertNodeInBST(struct BSTNode* ptr, struct BSTNode* new_node){
    if(new_node->data<ptr->data){
        if(ptr->left != NULL){
            insertNodeInBST(ptr->left,new_node);
        }
        else{
            ptr->left = new_node;
            new_node->parent = ptr;
            new_node = NULL;
        }
    }
    else{
        if(ptr->right){
            insertNodeInBST(ptr->right,new_node);
        }
        else{
            ptr->right = new_node;
            new_node->parent = ptr;
            new_node = NULL;
        }
    }
};

void insertBST(struct BST* ptr, int val){
    struct BSTNode* new_node = getBSTNode(val);
    if(ptr->node == NULL){
        ptr->node = new_node;
        new_node = NULL;    
    }else{
        insertNodeInBST(ptr->node,new_node);
    }
}


struct BSTNode* searchNode(struct BSTNode* ptr, int val){
    if(ptr == NULL){
        return NULL;
    }
    else if(val == ptr->data){
        return ptr;
    }
    else if(val<ptr->data){
        return searchNode(ptr->left,val);
    }
    else{
        return searchNode(ptr->right,val);
    }
};

int search(struct BST* ptr, int val){
    struct BSTNode* temp = searchNode(ptr->node, val);
    if(temp==NULL){    return 0;    }
    return 1;
}

struct BSTNode* minimumNode(struct BSTNode* ptr){
    if(ptr != NULL){
        while(ptr->left){
            ptr = ptr->left;
        }
        return ptr;
    }
    return ptr;
}

int minimum(struct BST* ptr){
    struct BSTNode* temp = minimumNode(ptr->node);
    if(temp==NULL){    return 0;    }
    return temp->data;    
}

struct BSTNode* maximumNode(struct BSTNode* ptr){
    if(ptr != NULL){
        while(ptr->right){
            ptr = ptr->right;
        }
        return ptr;
    }
    return ptr;
}

int maximum(struct BST* ptr){
    struct BSTNode* temp = maximumNode(ptr->node);
    if(temp==NULL){    return 0;    }
    return temp->data;    
}

struct BSTNode* predecessor(struct BSTNode* ptr,int a){
    if(ptr == NULL){  return ptr;  }

    if(a > ptr->data ){
        if(ptr->right){
            if(a <= minimumNode(ptr->right)->data){
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

struct BSTNode* successor(struct BSTNode* ptr,int a){
    if(ptr == NULL){  return ptr;  }

    if(a < ptr->data ){
        if(ptr->left){
            if(a >= maximumNode(ptr->left)->data){
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

void removeNodeInBST(struct BSTNode* ptr){
    struct BSTNode* temp;
    temp = successor(ptr,ptr->data);
    if(temp != NULL){
        ptr->data = temp->data;
    }else{
        temp = predecessor(ptr,ptr->data);
        if(temp != NULL){
            ptr->data = temp->data;
        }
    }

    if(temp == NULL){
        if(ptr->parent->right == ptr){
            ptr->parent->right = NULL;
        }else{
            ptr->parent->left = NULL;
        }
        temp = ptr->parent;
        free(ptr);
    }else{
        return removeNodeInBST(temp);
    }
}

void removeBST(struct BST* ptr,int a){
    struct BSTNode* temp;
    temp = searchNode(ptr->node,a);
    if(temp != NULL){
        removeNodeInBST(temp);
    }
    else{
        printf("%d is not in the Binary Search Tree",a);
    }
}

void printBSTNode(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    printBSTNode(ptr->left);
    printf("%d  ",ptr->data);
    printBSTNode(ptr->right);
}

void print(struct BST* ptr){
    printBSTNode(ptr->node);
    printf("\n");
}

// int main(){
//     struct BST* alpha = getBST();
//     insertBST(alpha, 24);
//     insertBST(alpha, 32);
//     insertBST(alpha, 11);
//     insertBST(alpha, 39);
//     insertBST(alpha, 22);
//     insertBST(alpha, 14);
//     insertBST(alpha, 4);
//     insertBST(alpha, 100);
//     print(alpha);
//     removeBST(alpha,11);
//     print(alpha);
//     removeBST(alpha,24);
//     print(alpha);
//     removeBST(alpha,100);
//     print(alpha);
//     removeBST(alpha,4);
//     print(alpha);
//     removeBST(alpha,11);

//     return 0;
// }