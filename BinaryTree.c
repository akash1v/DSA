#include<stdio.h>
#include<stdlib.h>

struct BTNode{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BTNode* getBTNode(int val){
    struct BTNode* temp = (struct BTNode*)malloc(sizeof(struct BTNode));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
