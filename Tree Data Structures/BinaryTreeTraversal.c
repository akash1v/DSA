#include<stdio.h>
#include"BinarySearchTree.c"

void printInOrderTraversal(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    printInOrderTraversal(ptr->left);
    printf("%d  ",ptr->data);
    printInOrderTraversal(ptr->right);
}

void inOrderTraversal(struct BST* ptr){
    printInOrderTraversal(ptr->node);
    printf("\n");
}

void printPreOrderTraversal(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    printf("%d  ",ptr->data);
    printPreOrderTraversal(ptr->left);
    printPreOrderTraversal(ptr->right);
}

void preOrderTraversal(struct BST* ptr){
    printPreOrderTraversal(ptr->node);
    printf("\n");
}

void printPostOrderTraversal(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    printPostOrderTraversal(ptr->left);
    printPostOrderTraversal(ptr->right);
    printf("%d  ",ptr->data);
}

void postOrderTraversal(struct BST* ptr){
    printPostOrderTraversal(ptr->node);
    printf("\n");
}


int main(){
    struct BST* bst = getBST();
    insertBST(bst,90);
    insertBST(bst,340);
    insertBST(bst,53);
    insertBST(bst,413);
    insertBST(bst,56);
    insertBST(bst,96);
    insertBST(bst,39);
    insertBST(bst,99);
    insertBST(bst,12);
    printf("In order traversal : \n");
    inOrderTraversal(bst);
    printf("Pre order traversal : \n");
    preOrderTraversal(bst);
    printf("Post order traversal : \n");
    postOrderTraversal(bst);
    return 0;
}