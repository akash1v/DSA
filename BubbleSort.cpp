void bubbleSort(int * array_a, int array_size){
    for (int i = array_size-1; i > 0; i--)
    {
        for(int j=0;j<i;j++){
            if(array_a[j]>array_a[j+1]){
                int key = array_a[j+1];
                array_a[j+1]=array_a[j];
                array_a[j]=key;
            }
        }
    }  
}