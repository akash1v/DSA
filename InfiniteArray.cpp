#include"IncreaseArray.cpp"
template<typename t>
class Array{
private:
    t* array{};
    int size{};

public:
    t & operator[](int i);
    int operator()();
    ~Array();
};

template<typename t>
t & Array<t>::operator[](int i){
    if(i >= size){
        array = increaseArray(array, size, i-size + 1);
        size = i+1;
    }
    return array[i];
}

template<typename t>
int Array<t>::operator()(){
    return size;
}
template<typename t>
Array<t>::~Array(){
    delete[] array;
}