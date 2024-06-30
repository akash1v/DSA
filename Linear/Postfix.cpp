#pragma once
#include"LinkedListStack.cpp"
#include"Dictionary.cpp"
#include<string>

using namespace std;

string postfix(string infix){
    string crctrs = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnnopqrstuvwx";
    
    Dictionary<char, int> oprtrs;
    oprtrs.insert('^',3);
    oprtrs.insert('/',2);
    oprtrs.insert('*',2);
    oprtrs.insert('+',1);
    oprtrs.insert('-',1);
    oprtrs.insert('(',0);
    oprtrs.insert(')',0);

    Stack<char> stk;
    string str;

    for(char c : infix){
        if(crctrs.find(c) != -1){    str += c;    }
        
        else if(c == '('){        stk.push(c);    }
    
        else if( c == ')'){
            while(stk.peek() != '('){
                str += stk.pop();
            }
            stk.pop();
        }
        else{
            while(oprtrs.value(c) < oprtrs.value(stk.peek())){
                str += stk.pop();
            }
            stk.push(c);
        }
    }

    while (stk.len()){    str += stk.pop();    }
    
    return str;
}