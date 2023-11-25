#include<stdio.h>

char options(){
    char input;
    printf("Select A to add an element in array\n");
    printf("Select R to remove an element fron an index in array\n");
    printf("Select P to print array\n");
    printf("Select Q to quit\n");
    scanf(" %c",&input);
    return input;
}

int inputValue(){
    int result;
    printf("Value : ");
    scanf("%d",&result);
    return result;
}

int inputIndex(int from,int to){
    int result;
    printf("Give an index from %d to %d : ",from,to);
    scanf("%d",&result);
    return result;
}

int remove_Array(int* array_a,int no_of_values){
    int index = inputIndex(0,no_of_values-1);
    while (index>no_of_values-1 || index<0){
        index = inputIndex(0,no_of_values-1);
    }
    int result = array_a[index];
    for (index; index<no_of_values-1; index++){
        array_a[index] = array_a[index+1];
    }
    return result;
}

void print(int* array,int no_of_values){
    if(no_of_values != 0){
        printf("%d",array[0]);
        for(int i=1;i<no_of_values;i++){
            printf(", %d",array[i]);
        }
        printf("\n");
    }
}

void insert_Array(int array_a[], int no_of_values){
    int value = inputValue();
    int index = inputIndex(0,no_of_values);
    while (index>no_of_values || index<0){
        index = inputIndex(0,no_of_values);
    }                                  
    for(int i=no_of_values;i > index; i--){
        array_a[no_of_values] = array_a[no_of_values-1];  
    }
    array_a[index] = value;
}

int main(){

    int array[10];
    int size = 10;
    int no_of_values = 0;
    char input = 'A';

    while (input!='Q'){
        input = options();
        switch (input){
        case 'A':
        case 'a':
            if(no_of_values<size){
                insert_Array(array,no_of_values);
                no_of_values++;
            }else{
                printf("Array is full\n");
            }
            break;
        case 'R':
        case 'r':
            remove_Array(array,no_of_values);
            no_of_values--;
            break;
        case 'P':
        case 'p':
            print(array,no_of_values);
            break;
        default:
            input = 'Q';
            break;
        }
    }
    return 0;
}