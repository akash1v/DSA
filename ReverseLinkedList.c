#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.c"

struct LinkedList* reverseLinkedList(struct LinkedList* ptr){
    
    struct LinkedList* temp = getLinkedList();
    int length = ptr->no_of_keys;
    for(int i=0; i<length; i++){
        insertLinkedList(temp, removeLinkedList(ptr,ptr->no_of_keys-1), temp->no_of_keys);
    };
    return temp;
}

int main(){
    struct LinkedList* linkedlist = getLinkedList();
    for(int i=1;i<5;i++){
        insertLinkedList(linkedlist,i*10,linkedlist->no_of_keys);
    }
    print(linkedlist);
    linkedlist = reverseLinkedList(linkedlist);
    print(linkedlist);
}