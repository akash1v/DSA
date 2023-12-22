template<typename t>
class Array{
private:
    t* arr{};
    int siz{};

    void makeSpace(int);
public:

    int size();
    int & operator[](int i);
    ~Array();
};

template<typename t>
void Array<t>::makeSpace(int a){
    int* new_array = new t[siz + a]{};
    for (int i = 0; i < siz; i++){
        new_array[i] = arr[i];
    }
    delete[] arr;
    arr = new_array;
    new_array = nullptr;
    siz = siz + a;
}

template<typename t>
int Array<t>::size(){
    return siz;
}

template<typename t>
int & Array<t>::operator[](int i){
    if(i >= siz){    makeSpace(i - siz + 1);    }
    return arr[i];
}

template<typename t>
Array<t>::~Array(){
    delete[] arr;
}