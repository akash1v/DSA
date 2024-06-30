#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* getNode(int val){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
}

struct LinkedList
{
    struct Node* front;
    struct Node* end;
    int no_of_keys;
};

struct LinkedList* getLinkedList(){
    struct LinkedList* temp = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    temp->front = NULL;
    temp->end = NULL;
    temp->no_of_keys = 0;
    return temp;
}

int length(struct LinkedList* ptr){
    return ptr->no_of_keys;
}

void insertLinkedList(struct LinkedList* ptr,int val,int index){

    if(index < 0 || index > ptr->no_of_keys){
        return;
    }

    struct Node* new_node;
    new_node = getNode(val);

    if(ptr->no_of_keys == 0){
        ptr->front = new_node;
        ptr->end = new_node;
    }
    else if(index == 0){
        new_node->next = ptr->front;
        ptr->front = new_node;
    }
    else if(index == ptr->no_of_keys){
        ptr->end->next = new_node;
        ptr->end = new_node;
    }
    else{
        struct Node* temp;
        temp = ptr->front;
        for(int i=1;i<index-1;i++){
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        temp = NULL;
    }
    ptr->no_of_keys++;
    new_node = NULL;
    return;
}

int removeLinkedList(struct LinkedList*ptr, int index){

    if(ptr->no_of_keys == 0 || index < 0 || index >= ptr->no_of_keys){
        return 0;
    }
    
    struct Node* temp;
    temp = ptr->front;

    if(ptr->no_of_keys == 1){
        ptr->front = NULL;
        ptr->end = NULL;
    }
    else if(index == 0){
        ptr->front = ptr->front->next;
    }
    else if(index == ptr->no_of_keys - 1 || index == -1){
        while(temp->next!=ptr->end){
            temp = temp->next;
        }
        ptr->end = temp;
        temp = temp->next;
        ptr->end->next = NULL;

    }else{
        
        struct Node* temp_2;
        for(int i=0;i<index;i++){
            temp_2 = temp;
            temp = temp->next;
        }

        temp_2->next = temp->next;
        temp_2 = NULL;
    }
    int data = temp->data;
    free(temp);
    ptr->no_of_keys--;
    return data;
}

void print(struct LinkedList* ptr){
    struct Node* temp;
    temp = ptr->front;
    while(temp != NULL){
        printf("%d, ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// int main(){
//     struct LinkedList* linkedlist = getLinkedList();
//     for(int i=1;i<10;i++){
//         insertLinkedList(linkedlist,i*100,linkedlist->no_of_keys);
//     }
//     print(linkedlist);
//     removeLinkedList(linkedlist,2);
//     print(linkedlist);
// }