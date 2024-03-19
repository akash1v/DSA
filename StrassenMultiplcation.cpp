#include<iostream>
#include"Matrix.cpp"
using namespace std;

Matrix add(Matrix a, Matrix b)
{
    Matrix c(a.M(), a.N());
    for (int i = 0; i < a.M(); i++)
    {
        for (int j = 0; j < a.N(); j++)
        {
            c(i, j) = a(i, j) + b(i, j);
        }
    }
    return c;
}

Matrix subs(Matrix a, Matrix b)
{
    Matrix c(a.M(), a.N());
    for (int i = 0; i < a.M(); i++)
    {
        for (int j = 0; j < a.N(); j++)
        {
            c(i, j) = a(i, j) - b(i, j);
        }
    }
    return c;
}

void divide(Matrix* array, Matrix& a)
{
    int n= a.N();
    int mid = n/2;
    for (int i = 0; i < mid; i++)
    {
        for(int j = 0; j < mid; j++)
        {
            array[0](i,j) = a(i,j);
        }
    }

    for (int i = 0; i < mid; i++)
    {
        for(int j = mid; j < n; j++)
        {
            array[1](i,j - mid) = a(i,j);
        }
    }

    for (int i = mid; i < n; i++)
    {
        for(int j = 0; j < mid; j++)
        {
            array[2](i - mid,j) = a(i,j);
        }
    }
    
    for (int i = mid; i < n; i++)
    {
        for(int j = mid; j < n; j++)
        {
            array[3](i - mid,j - mid) = a(i,j);
        }
    }
}

Matrix conquer(Matrix& c11, Matrix& c12, Matrix& c21, Matrix& c22)
{
    int n = c11.M() + c12.M();
    int mid = n/2;
    Matrix result(n, n);
    
    for (int i = 0; i < mid; i++)
    {
        for(int j = 0; j < mid; j++)
        {
            result(i, j) = c11(i, j);
        }
    }

    for (int i = 0; i < mid; i++)
    {
        for(int j = mid; j < n; j++)
        {
            result(i, j) = c12(i, j - mid);
        }
    }

    for (int i = mid; i < n; i++)
    {
        for(int j = 0; j < mid; j++)
        {
            result(i, j) = c21(i - mid, j);
        }
    }

    
    for (int i = mid; i < n; i++)
    {
        for(int j = mid; j < n; j++)
        {
            result(i, j) = c22(i - mid, j - mid);
        }
    }
    return result;
}

Matrix multiply(Matrix a, Matrix b)
{
    if(a.N() != b.M() || a.M() != a.N() || b.M() != b.N()){      return Matrix(0, 0);     }
    else if(a.N() == 1)
    {
        Matrix c(1,1);
        c(0, 0) = a(0,0)*b(0,0);
        return c;
    }

    int n= a.N();
    int mid = n/2;
    Matrix array_a[4] = {Matrix(mid, mid), Matrix(n-mid, mid),
                       Matrix(mid, n-mid), Matrix(n-mid, n-mid)};
    divide(array_a, a); 
    Matrix& a11 = array_a[0];
    Matrix& a12 = array_a[1];
    Matrix& a21 = array_a[2];
    Matrix& a22 = array_a[3];
    
    Matrix array_b[4] = {Matrix(mid, mid), Matrix(n-mid, mid),
                       Matrix(mid, n-mid), Matrix(n-mid, n-mid)};
    divide(array_b, b); 
    Matrix& b11 = array_b[0];
    Matrix& b12 = array_b[1];
    Matrix& b21 = array_b[2];
    Matrix& b22 = array_b[3];

    Matrix P = multiply(add(a11, a22),add(b11, b22));
    
    Matrix Q = multiply(add(a21, a22), b11);
    Matrix R = multiply(add(a12, a11), b22);
    
    Matrix S = multiply(subs(b12, b22), a11);
    Matrix T = multiply(subs(b21, b11), a22);
    
    Matrix U = multiply(subs(a21, a11), add(b12, b11));
    Matrix V = multiply(subs(a12, a22), add(b21, b22));

    Matrix c11 = add(add(subs(P, R), T), V);
    Matrix c12 = add(R, S);
    Matrix c21 = add(Q, T);
    Matrix c22 = add(add(subs(P, Q), S), U);

    Matrix result = conquer(c11, c12, c21, c22);
    return result;
}

int main()
{
    Matrix a(2,2);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(1, 0) = 3;
    a(1, 1) = 4;

    Matrix b = multiply(a, a);
    b.print();

}