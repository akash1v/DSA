#pragma once
template<typename t>
void swap(t* array, int a, int b){
    if( a == b){    return;    }
    t key = array[a];
    array[a] = array[b];
    array[b] = key;
}