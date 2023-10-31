void quickSort(int * array_a, int array_size){

    int nosoev = 0;                           //no of smaller or equal values
    int pivot = array_a[array_size-1];
    
    for (int i = 0; i < array_size; i++){                                                                   
        if(array_a[i]<=pivot){                            
            if(i==nosoev){
                nosoev++;
            }else{
                int key = array_a[nosoev];
                array_a[nosoev]  =  array_a[i];
                array_a[i]  = key;
                nosoev++;
            }
        }
    }

    if(nosoev>1){
    quickSort(array_a,nosoev-1);
    }

    if(array_size-nosoev > 1){
        int *p;
        p = &array_a[nosoev];
        quickSort(p,array_size-nosoev);
    }
}