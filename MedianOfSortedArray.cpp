int medianOfSortedArray(int* a, int a_s, int* b, int b_s){
    
    int* temp = new int[a_s + b_s]{};

    int m = 0;
    int n = 0;

    while(m < a_s){
        while (n < b_s){
            if(a[m] <= b[n]){
                temp[m+n] = a[m];
                break;
            }
            else{
                temp[m+n] = b[n];
            }
            n++;
        }
        if(n == b_s){
            break;
        }
       m++;
    }

    int k = (temp[0] + temp[a_s + b_s - 1])/2;
    delete[] temp;
    return k;
}