#include<iostream>
using namespace std;
#define DEFAULT_FIB 10              //default fib should be greater than 0

class Fibonacci{
private:
    int max_fib;
    double* dm = nullptr;

    double find(int a) {
        if (dm[a] != -1) {
            return dm[a];
        }
        dm[a] = find(a - 1) + find(a - 2);
        return dm[a];
    }

    void Extend(int a){
        double* temp = new double[a + 1];
        for (int i = 0;i <= max_fib; i++){
            temp[i] = dm[i];
        }
        for (int i = max_fib + 1;i <= a; i++){
            temp[i] = -1;
        }
        max_fib = a;
        delete[] dm;
        dm = temp;
        temp = nullptr;
    }

public:
    Fibonacci(int a){
        if(a < 1){
            a = DEFAULT_FIB;
        }
        max_fib = a;
        dm = new double[a + 1]{0, 1};
        for (int i = 2; i <= a; i++){
            dm[i] = -1;
        }
        find(max_fib);
    }

    Fibonacci() : Fibonacci(DEFAULT_FIB){}

    double value(int a){
        if (a < 0){
            return -1;
        }
        if( a > max_fib){
            Extend(a);
        }
        return find(a);
    }

    ~Fibonacci(){
        delete[] dm;
    }
};