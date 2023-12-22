#include"IncreaseArray.cpp"
template<typename s, typename t>
class Dictionary
{
private:
    s* key{};
    t* value{};
    int size{};
    int no_of_values{};
public:
    Dictionary(){};
    Dictionary(int);

    void insert(s, t);
    s key(int);
    s key(t);
    t value(int);
    t value(s);
    void remove(s);
    void remove(t);

    ~Dictionary();
};

template<typename s, typename t>
Dictionary<s,t>::Dictionary(int a){
    key = new t[a];
    value = new t[a];
    size = a;
};

template<typename s, typename t>
void Dictionary<s,t>::insert(s k, t v){
    if(no_of_values == size){
        increaseArray(key, size);
        increaseArray(value,size);
        size++;
    }

    key[no_of_values] = k;
    value[no_of_values] = v;
    no_of_values++;
}


template<typename s, typename t>
s Dictionary<s,t>::key(int a){
    return key[a];
}

template<typename s, typename t>
s Dictionary<s,t>::key(t a){
    for (int i = 0; i < no_of_values; i++){
        if(value[i] == a){
            return key[a];
        }
    }
}

template<typename s, typename t>
t Dictionary<s,t>::value(int a){
    return value[a];
}

template<typename s, typename t>
t Dictionary<s,t>::value(s a){
    for (int i = 0; i < no_of_values; i++){
        if(key[i] == a){
            return value[a];
        }
    }
}

template<typename s, typename t>
void Dictionary<s,t>::remove(s a){
    int i=0;
    for (i, i < no_of_values; i++){
        if(key[i] == a){
            result = value[i];
        }
    }
    for(int k=i; k < no_of_values - 1;k++){
        key[k] = key[k + 1];
        value[k] = value[k+1];
    }
    no_of_values--;
}

template<typename s, typename t>
void Dictionary<s,t>::remove(t a){
    int i=0;
    for (i, i < no_of_values; i++){
        if(value[i] == a){
            result = value[i];
        }
    }
    for(int k=i; k < no_of_values - 1;k++){
        key[k] = key[k + 1];
        value[k] = value[k+1];
    }
    no_of_values--;
}

template<typename s, typename t>
Dictionary<s,t>::~Dictionary(){
    delete[] key;
    delete[] value;
}