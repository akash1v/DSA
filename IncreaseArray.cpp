template<typename t>
t* increaseArray(t* array, int size, int ifactor=1){
    t* new_array = new t[size + ifactor]{};
    for (int i = 0; i < size; i++){
        new_array[i] = array[i];
    }
    delete[] array;
    return new_array;
}