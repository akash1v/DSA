#include<stdio.h>

int linearSearchInArray(int* array_a,int array_size,int value){
    for (int i = 0; i < array_size; i++)
    {
        if(array_a[i] == value){
            return i;
        }
    }
    return -1;
}

int biarySearchInArray(int* array_a,int left_index,int right_index,int value){
    
    if(right_index == left_index){
        if(array_a[right_index] == value){
            return right_index;
        }
        else{
            return -1;
        }
    }

    if(right_index-left_index == 1){
        if(array_a[left_index] == value){
            return left_index;
        }
        else if(array_a[right_index] == value){
            return right_index;
        }
        else{
            return -1;
        }
    }

    int mid_index = ( right_index - left_index )/2 + left_index;

    if(array_a[mid_index] == value){
        return mid_index;
    }
    else if(value > array_a[mid_index]){
        return biarySearchInArray(array_a,mid_index,right_index,value);
    }
    else if(value < array_a[mid_index]){
        return biarySearchInArray(array_a,left_index,mid_index,value);
    }
}

int main(){
    //Linear Search
    int array_1[10] = { 12 , 24 , 66 , 345 , 34 , 444 , 30 , 230 , 49 , 100};
    int value;
    printf("Value to be search in array using linear search algorithm : ");
    scanf("%d",&value);
    int result = linearSearchInArray(array_1,10,value);
    if(result == -1){   printf("%d is not in array\n",value);    }
    else{    printf("%d is in array at index %d \n",value,result);    }

    //Binary Search
    //For binary search in an array,array have to be sorted in ascending order
    int array_2[10] = { 12 , 24 , 30 , 34 , 49 , 66 , 100 , 230 , 345 , 444};
    printf("Value to be search in array using binary search algorithm : ");
    scanf("%d",&value);
    result = biarySearchInArray(array_2,0,9,value);
    if(result == -1){    printf("%d is not in array\n",value);    }
    else{    printf("%d is in array at index %d \n",value,result);    }
    

    return 0;
}