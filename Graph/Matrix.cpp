#include<iostream>
using namespace std;

class Matrix{
private:
    int** matrix{};
    int m{};
    int n{};

    int s_m{};
    int s_n{};

    void freeMatrix();

public:
    Matrix(int);
    Matrix(int, int);

    void zeroMatrix();
    void identityMatrix();
    void fillMatrix(int);

    int M();
    int N();
    int& operator()(int, int);

    void add(Matrix&);
    void multiply(Matrix&);
    int count();
    void print();

    void sparseMatrix();
    void denseMatrix();

    ~Matrix();
};

Matrix::Matrix(int a){
    if( a < 1 ){    return;    }

    matrix = new int*[a];
    for (int i = 0; i < a; i++){
        matrix[i] = new int[a]{};
    }
    m = a;
    n = a;
}

Matrix::Matrix(int a, int b){
    if( a < 1 || b < 1){    return;    }

    matrix = new int*[a];
    for (int i = 0; i < a; i++){
        matrix[i] = new int[b]{};
    }
    m = a;
    n = b;
}

void Matrix::zeroMatrix(){
    fillMatrix(0);
}

void Matrix::identityMatrix(){

    if (m != n){    return;    }
    zeroMatrix();
    for (int i = 0; i < m; i++){
        matrix[i][i] = 1;
    }
}

void Matrix::fillMatrix(int a){
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = a;
        }
    }
}

int Matrix::M(){    return m;    }

int Matrix::N(){    return n;    }

int& Matrix::operator()(int a, int b){    return matrix[a][b];    }

void Matrix::add(Matrix& a){
    if(m != a.M() || n != a.N()){    return ;    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] += a(i, j);
        }
    }
}

void Matrix::multiply(Matrix& a){
    if (n != a.M()){    return;    }

    int** new_matrix = new int*[m];
    for (int i = 0; i < m; i++){
        new_matrix[i] = new int[a.N()];
    }
    
    for (int i = 0; i < m; i++){
        for(int j = 0; j < a.N(); j++){
            int sum = 0;
            for (int s = 0; s < n; s++){
                sum += matrix[i][s]*a(s, j);
            }
            new_matrix[i][j] = sum;
        }
    }
    freeMatrix();
    matrix = new_matrix;
    n = a.N();
}

int Matrix::count(){
    int k = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(matrix[i][j] != 0){
                k++;
            }
        }
    }
    return k;
}

void Matrix::print(){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;   
    }
    cout<<endl;
    
}

void Matrix::sparseMatrix(){
    
    if( s_m > 0 ){    return;    }
    
    int k = count();
    if(k == 0){    return;    }
    
    int** new_matrix = new int*[3];
    for (int i = 0; i < 3; i++){
        new_matrix[i] = new int[k];
    }
    
    k = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(matrix[i][j] != 0){
                new_matrix[0][k] = i;
                new_matrix[1][k] = j;
                new_matrix[2][k] = matrix[i][j];
                k++;
            }
        }
    }
    
    freeMatrix();
    matrix = new_matrix;
    s_m = m;
    s_n = n;
    m = 3;
    n = k;
};

void Matrix::denseMatrix(){
    if( s_m < 1 ){    return;    }

    int** new_matrix = new int*[s_m];
    for (int i = 0; i < s_m; i++){
        new_matrix[i] = new int[s_n]{};
    }

    for(int i = 0; i < n; i++){
        new_matrix[ matrix[0][i] ] [ matrix[1][i] ] = matrix[2][i];
    }
    
    freeMatrix();
    matrix = new_matrix;
    m = s_m;
    n = s_n;
    s_m = 0;
    s_n = 0;
}


void Matrix::freeMatrix(){
    for (int i = 0; i < m; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix::~Matrix(){
    freeMatrix();
}