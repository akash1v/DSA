#include"LinkedListStack.cpp"
#include"Dictionary.cpp"
#include<string>

using namespace std;

string postfix(){
    LinkedList charc;
    for (int i = 65; i < 91; i++)
    {
        charc.insert(i, 0);
    }
    for (int i = 97; i < 123; i++){
        charc.insert(i, 0);
    }
    
}