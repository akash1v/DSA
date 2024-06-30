#include<iostream>
using namespace std;

void print(int i, char a, char b){
    std::cout<< i << " from " << a << " to " << b << std::endl;
}

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0){    return;    }

    hanoi(n - 1, source, destination, auxiliary);
    print(n, source,destination);
    hanoi(n - 1, auxiliary, source, destination);
}

void hanoi(int disk){
    hanoi(disk, 'A', 'B', 'C');
}
