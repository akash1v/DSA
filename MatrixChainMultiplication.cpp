#include<iostream>
#include<vector>
using namespace std;

vector<vector<vector<int>>> MatrixChanMultiplication(int* d, int n/*no of matrices*/)
{
    vector<vector<vector<int>>> A(2, vector<vector<int>>(n,vector<int>(n,0)));
    
    for(int c = 1; c < n; c++)
    {
        for(int i = 0; i < n - c; i++)
        {
            int j = i + c;

            for(int k = i; k < j; k++)
            {
                int cost = A[0][i][k] + A[0][k+1][j] + d[i] * d[k+1] * d[j+1];
                if( A[0][i][j] == 0){
                    A[0][i][j] = cost;
                }
                else{
                    A[0][i][j] = min(A[0][i][j], cost);
                }
                if (A[0][i][j] == cost){
                    A[1][i][j] = k+1-i;
                }
                
            }
        }
    }
    return A;
}