#include<iostream>
#include<algorithm>
#define max_fib 1000

using namespace std;
int fibonacci(int num)
{
    
    if (num == 0 || num == 1)
    {
        return num;
    }

    static int fib[max_fib];
    fill(begin(fib), end(fib), -1);
    fib[0] = 0;
    fib[1] = 1;


    if (fib[num - 1] == -1)
    {
        fib[num - 1] = fibonacci(num - 2) + fibonacci(num - 3);
    }
    
    int result = fib[num - 1] + fib[num - 2];
    return result;
}

int main()
{
    // for (int i = 0; i < 15; i++)
    // {
        cout<<fibonacci(15)<<endl;
    // }
    return 0;
}