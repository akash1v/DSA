#include<iostream>
#include<string>

using namespace std;

class Cipher{
private:
    string str;
    string cphr;

    bool checkLength(string & a, string & b);
    bool checkDuplicate(string & a);
    bool checkAllElements(string & a, string & b);
public:
    Cipher(string a, string b);
    string encrypt(string a);
    string decrypt(string a);
};

Cipher::Cipher(string a, string b)
{
    if(!checkLength(a,b)){    return;    }
    if(!checkDuplicate(a)){    return;    }
    if(!checkAllElements(a,b)){    return;    }

    str = a;
    cphr = b;
}

bool Cipher:: checkLength(string & a, string & b){
    if(a.length() != b.length()){
        return false;
    }
    return true;
};

bool Cipher:: checkDuplicate(string & a){
    for (int i = 0; i < a.length() - 1; i++){
        for (int j = i + 1; j < a.length(); j++){
            if(a[i] == a[j]){
                return false;
            }
        }
    }
    return true;
};

bool Cipher:: checkAllElements(string & a, string & b){
    for (int i = 0; i < a.length(); i++){
        if(b.find(a[i]) == -1){
            return false;
        }
    }
    return true;    
};

string Cipher::encrypt(string a){
    for (int i = 0; i < a.length(); i++){
        int k = str.find(a[i]);
        if(k != -1){
            a[i] = cphr[k];
        }
    }
    return a;
}

string Cipher::decrypt(string a){
    for (int i = 0; i < a.length(); i++){
        int k = cphr.find(a[i]);
        if(k != -1){
            a[i] = str[k];
        }
    }
    return a;   
}