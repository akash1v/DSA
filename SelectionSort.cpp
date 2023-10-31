void selectionSort(int* array_a,int array_size){
    for (int i = 0; i < array_size; i++)
    {
        int k = i;
        for (int j = i; j<array_size; j++)
        {
            if(array_a[j]<array_a[k]){
                k = j;
            }
        }
        int key = array_a[i];
        array_a[i] = array_a[k];
        array_a[k] = key;   
    }
}