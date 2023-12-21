int medianOfSortedArray(int* a, int a_s, int* b, int b_s){
    
    int temp[a_s + b_s]{};

    int m = 0;
    int n = 0;

    while(m < a_s){
        
        if( n == b_s){    break;    }
        while (n < b_s){
            if(a[m] <= b[n]){
                temp[m+n] = a[m];
                m++;
                break;
            }
            else{
                temp[m+n] = b[n];
                n++;
            }
        }
    }

    while (m < a_s){
        temp[m+n] = a[m];
        m++;
    }
    

    while (n < b_s){
        temp[m+n] = b[n];
        n++;
    }
    

    int k = (temp[0] + temp[a_s + b_s - 1])/2;
    return k;
}