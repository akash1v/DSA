#pragma once
#include<iostream>
#include"LinkedList.cpp"
template<typename s, typename t>
class Dictionary{
private:
    LinkedList<s> keys;
    LinkedList<t> values;

public:

    void insert(s k, t v);
    void removeAt(int at);
    t remove(s k);
    s remove(t k);
    s key(t v);
    s keyAt(int at);
    t value(s k);
    t valueAt(int at);
};

template<typename s, typename t>
void Dictionary<s, t>::insert(s k, t v){
    keys.insert(k, keys.length());
    values.insert(v, values.length());    
}

template<typename s, typename t>
void Dictionary<s, t>::removeAt(int at){
    keys.remove(at);
    values.remove(at);
}

template<typename s, typename t>
t Dictionary<s, t>::remove(s k){
    int at = keys.search(k);
    keys.remove(at);
    return value.remove(at);
}

template<typename s, typename t>
s Dictionary<s, t>::remove(t v){
    int at = values.search(v);
    values.remove(at);
    return keys.remove(at);
}

template<typename s, typename t>
s Dictionary<s, t>::key(t v){
    return keys.at(values.search(v));
}

template<typename s, typename t>
s Dictionary<s, t>::keyAt(int at){
    return keys.at(at);
}

template<typename s, typename t>
t Dictionary<s, t>::value(s k){
    return values.at(keys.search(k));
}

template<typename s, typename t>
t Dictionary<s, t>::valueAt(int at){
    return values.at(at);
}
