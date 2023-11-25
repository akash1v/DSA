#include<stdio.h>
#include"BinarySearchTree.c"

void inOrderTraversal(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    inOrderTraversal(ptr->left);
    printf("%d  ",ptr->data);
    inOrderTraversal(ptr->right);
}

void inOrderTraversal(struct BST* ptr){
    inOrderTraversal(ptr->node);
    printf("\n");
}

void preOrderTraversal(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    printf("%d  ",ptr->data);
    preOrderTraversal(ptr->left);
    preOrderTraversal(ptr->right);
}

void preOrderTraversal(struct BST* ptr){
    preOrderTraversal(ptr->node);
    printf("\n");
}

void postOrderTraversal(struct BSTNode* ptr){
    if(ptr==NULL){  return;    }
    postOrderTraversal(ptr->left);
    postOrderTraversal(ptr->right);
    printf("%d  ",ptr->data);
}

void postOrderTraversal(struct BST* ptr){
    postOrderTraversal(ptr->node);
    printf("\n");
}