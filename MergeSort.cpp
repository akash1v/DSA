void mergeSort(int* array_a,int array_size){

    if(array_size==1){ return; }
    else if (array_size==2){
        if(array_a[0]<=array_a[1]){
            return;
        }
        else{
            int key = array_a[0];
            array_a[0]=array_a[1];
            array_a[1]=key;
            return;
        }
    }

    int a,b;

    if(array_size%2==0){
        a=array_size/2;
        b=array_size/2;
    }
    else{
        a=array_size/2 + 1;
        b=array_size/2;
    }

    int first_half[a]{};
    int last_half[b]{};

    for (int i = 0; i < a; i++){
        first_half[i] = array_a[i];
    };

    for(int i=array_size; i > a; i--){
        last_half[i-1-a] = array_a[i-1];
    }

    mergeSort(first_half,a);
    mergeSort(last_half,b);        

    int m=0;
    int n=0;

    while(m<a){
        while (n<b){
            if(first_half[m]<=last_half[n]){
                array_a[m+n]=first_half[m];
                break;
            }
            else{
                array_a[m+n]=last_half[n];
            }
            n++;
        }
        if(n==b){
            break;
        }
       m++;
    }

    if(n==b){
        while (m<a){
            array_a[m+n] = first_half[m];
            m++;
        }
    }
        
    if(m==a){
        while (n<b){
            array_a[m+n] = last_half[n];    
            n++;
        }
    }
    
    return;
}