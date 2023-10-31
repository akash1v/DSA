void insertionSort(int * array_a, int array_size){
    for (int i = 0; i < array_size; i++){
        for (int j = i; j>0; j--){
            if (array_a[j]<array_a[j-1]){
                int key = array_a[j];
                array_a[j] = array_a[j-1];
                array_a[j-1] = key;
            }
            else{
                break;
            }          
        }       
    }
}