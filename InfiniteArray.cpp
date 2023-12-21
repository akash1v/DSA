template<typename t>
class Array{
private:
    t* arr{};
    int a_size{};

    void makeSpace(int);
public:

    int size();
    int & operator[](int i);
    ~Array();
};

template<typename t>
void Array<t>::makeSpace(int a){
    int* new_array = new t[a_size + a]{};
    for (int i = 0; i < a_size; i++){
        new_array[i] = arr[i];
    }
    delete[] arr;
    arr = new_array;
    new_array = nullptr;
    a_size = a_size + a;
}

template<typename t>
int Array<t>::size(){
    return a_size;
}

template<typename t>
int & Array<t>::operator[](int i){

    if(i >= a_size){    makeSpace(i - a_size + 1);    }
    return arr[i];
}

template<typename t>
Array<t>::~Array(){
    delete[] arr;
}