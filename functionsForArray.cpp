#include<iostream>

void insertInArray(int array_a[], int array_size, int value, int location)
{

    if(location>array_size-1){    return;   }

    if(array_a[location]==0)
    {
        array_a[location]=value;
        return;
    }

    for(int i=0;i<location;i++)
    {
        if(array_a[i]==0)
        {
            for(int j=i;j<location;j++)
            {
                array_a[j] = array_a[j+1];
            };

            array_a[location] = value;
            return;
        }
    }

    for(int i=location+1;i < array_size; i++)
    {
        if(array_a[i]==0)
        {
            for(int j=i;j>location;j--)
            {
                array_a[j] = array_a[j-1];
            }

            array_a[location] = value;
            return;    
        }
    }
}

void deleteInArray(int* array_a,int delete_location)
{
    array_a[delete_location] = 0;
}

int linearSearchInArray(int*  array_a, int array_size, int value)
{
    for(int i=0;i<array_size;i++)
    {
        if(array_a[i]==value)
        {
            return i;
        }
    }

    return -1;
}

void printArray(int* array_a , int array_size)
{
    for(int i=0;i<array_size;i++)
    {
        std::cout<<array_a[i]<<std::endl;
    }
}

int noOfSameCharacterFromStartInString(char* str_1,int str_1_size,char* str_2,int str_2_size)
{
    int iter{},result{};

    if(str_1_size <= str_2_size){    iter = str_1_size;    }
    else{    iter = str_2_size;    };
        
    for(int i=0;i<iter;i++)
    {
        if(str_1[i]!=str_2[i]){    break;    }
        result++;
    }

    return result;
}

int wordOccurence(char* word,int word_size,char* text,int text_size)
{
    int no_of_occurences = 0;
    for(int i=0;i<text_size;i++)
    {
        if(word[0]==text[i])
        {
            if(word_size == noOfSameCharacterFromStartInString(word,word_size,&text[i],text_size-i))
            {
                no_of_occurences++;
            }
        }
    }
    return no_of_occurences;
}