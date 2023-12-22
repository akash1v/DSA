#include"IncreaseArray.cpp"
class Array{
private:
    int* arr{};
    int siz{};

public:

    int size();
    int & operator[](int i);
    ~Array();
};

int Array::size(){
    return siz;
}

int & Array::operator[](int i){
    if(i >= siz){
        increaseArray(arr, siz, i-siz + 1);
        siz = i;
    }
    return arr[i];
}

Array::~Array(){
    delete[] arr;
}