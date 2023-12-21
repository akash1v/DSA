int* mergeSortedArray(int* a, int a_s, int* b, int b_s){
    
    int* array = new int[a_s + b_s];
    
    int m{},n{};
    while (m < a_s){
        if(n == b_s){    break;    }
        while (n < b_s){
            if(a[m] <= b[n]){
                array[m+n] = a[m];
                m++;
                break;
            }
            else{
                array[m+n] = b[n];
                n++;
            }
        }
    }

    while (m < a_s){
        array[m+n] = a[m];
        m++;
    }

    while (n < b_s){
        array[m+n] = b[n];
        n++;
    }

    return array;
}