// It has at least 8 characters and at most 20 characters
// It contains at least one lowercase letter, at least one uppercase letter, at least one digit and at least one special character
// It does not contain three repeating characters in a row

#include<iostream>
#include<string>
using namespace std;

bool checkLength(string & str){
    
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    if(i >= 8 && i <= 20){
        return true;
    }
    return false;
}

bool checkLowerCase(string & str){
    // using ascii values as from a = 97 to z = 122
    
    int i = 0;
    while (str[i] != '\0'){
        
        if( str[i] >= 97 && str[i <= 122]){
            return true;
        }
        i++;
    }
    return false;
}

bool checkUpperCase(string & str){
    // using ascii values as from A = 65 to Z = 90
    
    int i = 0;
    while (str[i] != '\0'){
        
        if( str[i] >= 65 && str[i] <= 90){
            return true;
        }
        i++;
    }
    return false;
    
}

bool checkNumber(string & str){
    // using ascii values as from 0 = 48 to 9 = 57

    int i = 0;
    while (str[i] != '\0'){

        if( str[i] >= 48 && str[i] <= 57){
            return true;
        }
        i++;
    }
    return false;   
}

bool checkSpecialCharacter(string & str){
    // using ascii values (33,47) U (58,64) U (91,96) U (123,126)

    int i=0;
    while (str[i] != '\0'){

        if(str[i] >= 33 && str[i] <= 47){
            return true;
        }

        if(str[i] >= 58 && str[i] <= 64){
            return true;
        }
    
        if(str[i] >= 91 && str[i] <= 96){
            return true;
        }

        if(str[i] >= 123 && str[i] <= 126){
            return true;
        }

        i++;
    }
    return false;
}

bool checkConsecutive(string & str){
    int i = 0;
    while( str[ i+2 ] != '\0'){
        if( str[i] == str[i+1] && str[i] == str[i+2]){
            return false;
        }
        i++;
    }
    return true;
}

bool strongPasswordChecker(string str){

    bool length = checkLength(str);
    if(!length){    return false;    }

    bool lower = checkLowerCase(str);
    if(!lower){    return false;    }

    bool upper = checkUpperCase(str);
    if(!upper){    return false;    }

    bool num = checkNumber(str);
    if(!num){    return false;    }

    bool special = checkSpecialCharacter(str);
    if(!special){    return false;    }

    bool consecutive = checkConsecutive(str);
    if(!consecutive){    return false;    }

    return true;
}
