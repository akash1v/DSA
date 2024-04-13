int xpowern(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    int k = xpowern(x, n/2);

    if (n%2 == 1)
    {
        return k*k*x;
    }
    return k*k;
}