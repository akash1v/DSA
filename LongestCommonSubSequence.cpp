#include<string>
#include<vector>
#include<iostream>
using namespace std;

string LCSS(string& a, string& b)
{
    vector<vector<int>> matrix(a.size() + 1, vector<int>(b.size() + 1,0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if(a[i] == b[j])
            {
                matrix[i+1][j+1] = 1 + matrix[i][j];
            }
            else
            {
                matrix[i+1][j+1] = max(matrix[i][j+1], matrix[i+1][j]);
            }
        }   
    }
    
    string result{};
    for (int i = b.size(),j = a.size(); i > 0 && j > 0; i--)
    {
        if (matrix[j][i] != matrix[j][i - 1])
        {
            result = b[i - 1] + result;
            j--;
        }
        
    }
    return result;
}
int main()
{
    string a = "ewoidsklnd";
    string b = "edekl";
    string c = LCSS(b, a);
    cout<<c<<endl;
    return 0;

}