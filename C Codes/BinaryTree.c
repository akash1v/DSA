#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct Node* getNode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){
    struct Node* tree;
    struct Node* temp;
    tree = getNode(15);
    tree->right = getNode(47);
    tree->left = getNode(20);

    temp = tree->left;
    temp->left = getNode(79);
    temp->right = getNode(18);
    
    temp = temp->left;
    temp->left = getNode(26);
    temp->right = getNode(81);
    
    temp = tree->right;
    temp->right = getNode(67);
    
    temp = temp->right;
    temp->left = getNode(99);
    return 0;
}