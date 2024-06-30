#include<iostream>
using namespace std;
void MaxMin(int* array, int lindex, int rindex, int & max, int & min)
{
    if(rindex - lindex > 1)
    {
        int mindex = (rindex - lindex)/2 + lindex;
        int lmax, rmax, lmin, rmin;
        MaxMin(array, lindex, mindex, lmax, lmin);
        MaxMin(array, mindex, rindex, rmax, rmin);

        if(lmax > rmax)
        {
            max = lmax;
        }
        else
        {
            max = rmax;
        }

        if (lmin < rmin)
        {
            min = lmin;
        }
        else
        {
            min = rmin;
        }
        
    }
    else
    {
        if(array[lindex] > array[rindex])
        {
            max = array[lindex];
            min = array[rindex];
        }
        else
        {
            max = array[rindex];
            min = array[lindex];
        }
    }
}

void MaxMin(int* array, int n, int & max, int & min)
{
    MaxMin(array, 0, n-1, max, min);
}

int Max(int* array, int n)
{
    int max{}, min{};
    MaxMin(array,0 , n-1, max, min);
    return max;
}

int Min(int* array, int n)
{
    int max{}, min{};
    MaxMin(array,0 , n-1, max, min);
    return min;
}