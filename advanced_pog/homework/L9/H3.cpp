#include <bits/stdc++.h>
using namespace std;

template <class T>
class Matrix
{
    int col, row;
    T *matrix;

public:
    Matrix(int m, int n)
    {
        row = m;
        col = n;
        matrix = new T[row * col];
    }
    Matrix(const Matrix &mat)
    {
        col = mat.col;
        row = mat.row;
        delete[] matrix;
        matrix = new T[row * col];
        for (int i = 0; i < row * col; i++)
        {
            matrix[i] = mat.matrix[i];
        }
    }
    void setMatrix();
    void display();
    void transport();
    void square();
    Matrix operator+(const Matrix &mat);
    ~Matrix()
    {
        row = col = 0;
        delete[] matrix;
    }
    Matrix(Matrix &&a)
    {
        row = a.row;
        col = a.col;
        delete[] matrix;
        matrix = a.matrix;
        a.matrix = NULL;
        a.row = a.col = 0;
    }
    Matrix operator=(Matrix &&a)
    {
        row = a.row;
        col = a.col;
        delete[] matrix;
        matrix = a.matrix;
        a.matrix = NULL;
        a.row = a.col = 0;
    }
};

template <class T>
void Matrix<T>::setMatrix()
{
    for (int i = 0; i < col * row; i++)
    {
        T temp;
        cin >> temp;
        matrix[i] = temp;
    }
}

template <class T>
void Matrix<T>::display()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i * col + j] << "\t";
        cout << endl;
    }
}

template <class T>
void Matrix<T>::transport()
{
    T *temp = new T[col * row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            temp[j * row + i] = matrix[i * col + j];
    }
    delete[] matrix;
    matrix = temp;
    swap(col, row);
}

template <class T>
void Matrix<T>::square()
{
    Matrix cop(*this);
    cop.transport();
    Matrix res(row, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            T temp = 0;
            for (int k = 0; k < col; k++)
            {
                temp += matrix[i * col + k] * cop.matrix[k * col + j];
            }
            res.matrix[i * row + j] = temp;
        }
    }
    res.display();
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix &mat)
{
    for (int i = 0; i < row * col; i++)
        matrix[i] += mat.matrix[i];
    return *this;
}

int main()
{
    Matrix<int> a(3, 5);
    a.setMatrix();
    cout << "This is matrix a : \n";
    a.display();
    Matrix<int> b(a);
    cout << "This is matrix b : \n";
    b.display();
    a.transport();
    cout << "After transposion matrix a is : \n";
    a.display();
    Matrix<double> c(4, 5);
    c.setMatrix();
    Matrix<double> d(4, 5);
    d.setMatrix();
    // something wrong here
    Matrix<double> res = c + d;
    cout << "The result of the matrix c + d is : \n";
    res.display();
    Matrix<double> e(3, 5);
    e.setMatrix();
    e.square();
    return 0;
}