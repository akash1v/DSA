#include<iostream>
#include<vector>
using namespace std;

int LISS(vector<int> a)
{
    vector<int> b(a.size(), 1);


    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                b[i] = max(b[i], b[j] + 1);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if(b[i] > b[max])
        {
            max = i;
        }
    }
    
    return b[max];
    
}

int main()
{
    vector<int> array = {3, 4, -1, 0, 6, 2, 3};
    cout<<LISS(array)<<endl;
    
    return 0;
}