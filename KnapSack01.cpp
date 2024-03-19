#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> KnapSack( int* values, int* weights, int n, int capacity)
{
    vector<vector<int>> A(n+1, vector<int>(capacity+1, 0));   

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < capacity + 1; j++)
        {
            if (weights[i] <= j)
            {
                int cost = values[i] + A[i][j - weights[i]];
                A[i+1][j] = max(A[i][j], cost);
            }
            else
            {
                A[i+1][j] = A[i][j];
            }
        }
    }
    return A;
}