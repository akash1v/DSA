int xn(int x, int n){
    if (n == 0){
        return 1;
    }
    else if (n == 1){
        return n;
    }
    
    if ( n % 2 == 0){
        return xn(x, n/2 )*xn(x, n/2 );
    }
    int k = xn(x, (n-1)/2);
    return x*k*k;
}