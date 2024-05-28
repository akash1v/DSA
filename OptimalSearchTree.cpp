#include<iostream>
#include<vector>
using namespace std;

vector<vector<vector<int>>> OptimalSearchTree(int* s, int* u, int n/*no of keyss*/)
{
    n++;
    vector<vector<vector<int>>> A(2, vector<vector<int>>(n,vector<int>(n,0)));

    for(int c = 1; c < n; c++)
    {
        for(int i = 0; i < n - c; i++)
        {
            int j = i + c;

            int w = u[j];
            for (int k = i; k < j; k++)
            {
                w += u[k];
                w += s[k];
            }
            
            for(int k = i; k < j; k++)
            {    
                int cost = A[0][i][j] + A[0][k+1][j] + w;
                if( A[0][i][j] == 0){
                    A[0][i][j] = cost;
                }
                else{
                    A[0][i][j] = min(A[0][i][j], cost);
                }
                if (A[0][i][j] == cost){
                    A[1][i][j] = k+1;
                }
            }
        }
    }
    return A;
}

int main(){
    int s[5] = {1,2,3,4,5};
    int u[6] = {-1,-2,-3,-4,-5,-6};
    vector<vector<vector<int>>> A = OptimalSearchTree(s, u, 5);
}