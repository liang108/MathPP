#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>

template<typename T>
Matrix<T>::Matrix()
{
    data_ = nullptr;
    num_rows_ = 0;
    num_cols_ = 0;
}

template<typename T>
Matrix<T>::Matrix(size_t num_rows, size_t num_cols)
{
    // Ensure proper dimensions
    assert(num_rows > 0);
    assert(num_cols > 0);
    // Initialize matrix with specified dimensions and all entries 0
    num_rows_ = num_rows;
    num_cols_ = num_cols;   
    data_ = new T*[num_rows];

    for (int i=0; i < num_rows; i++)
    {
        data_[i] = new T[num_cols];
        for (int j=0; j < num_cols; j++)
        {
            data_[i][j] = T();              // Call default constructor for objects of type T
        }
    }
}

/* template<typename T>
Matrix<T>::Matrix(const T** data, size_t num_rows, size_t num_cols)
{   
    // Passing in 2D array, and dimensions
    // Check dimensions are not empty
    assert(num_rows > 0);
    assert(num_cols > 0);     
    num_rows_ = num_rows;
    num_cols_ = num_cols;

    // Initialize new matrix
    data_ = new T*[num_rows_];

    // Copy over values from T** data
    for (int i=0; i < num_rows_; i++)
    {
        data_[i] = new T[num_cols_];
        for (int j=0; j < num_cols_; j++)
        {
            data_[i][j] = data[i][j];
        }
    }
} */

template<typename T>
Matrix<T>::Matrix(const Matrix& m1)
{
    num_rows_ = m1.num_rows_;
    num_cols_ = m1.num_cols_;
    data_ = new T*[num_rows_];
    for (int i=0; i < num_rows_; i++)
    {
        data_[i] = new T[num_cols_];
        for (int j=0; j < num_cols_; j++)
        {
            data_[i][j] = m1.data_[i][j];
        }
    }
}

template<typename T>
Matrix<T>::~Matrix()
{
    for (int i=0; i < num_cols_; i++)       // Since data_ points to an array of pointers, need to
    {                                       // deallocate the data they point to first, then deallocate
        delete[] data_[i];                  // what data_ points to
    }
    delete[] data_;
    data_ = nullptr;
}

template<typename T>
int Matrix<T>::GetNumRows()
{
    return num_rows_;
}

template<typename T>
int Matrix<T>::GetNumCols()
{
    return num_cols_;
}

template<typename T>
void Matrix<T>::AppendRow(const Vector<T>& v)
{
    assert(v.GetSize() == GetNumCols());
    // Copy current data to use in new matrix
    T** old_data = data_;
    
    // Delete old matrix to free up memory
    for(int i=0; i < num_rows_; i++)
    {
        delete[] data_[i];
    }
    delete[] data_;

    // Allocate memory for new matrix with one more row
    data_ = new T*[num_rows_+1];
    
    for (int i=0; i < num_rows_; i++)
    {
        // Allocate new memory for each row
        data_[i] = new T[num_cols_];

        // Copy entries from old matrix into new one
        for (int j=0; j < num_cols_; j++)
        {
            data_[i][j] = old_data[i][j];
        }
    
        // Clear each row in old matrix
        delete[] old_data[i];
    }

    // Append values from vector into last row
    for (int i=0; i < v.GetSize(); i++)
    {
        data_[num_rows_][i] = v[i];
    }

    delete[] old_data;
    num_rows_++;
}


template<typename T>
void Matrix<T>::AppendCol(const Vector<T>& v)
{
    assert(v.GetSize() == GetNumRows());
    T** old_data = data_;

    for (int i=0; i < num_rows_; i++)
    {
        // Clear ith vector in old matrix
        delete[] data_[i];
        
        // Extend rows by one
        data_[i] = new T[num_cols_ + 1];

        // Copy data from old matrix
        for (int j=0; j < num_cols_; j++)
        {
            data_[i][j] = old_data[i][j];
        }
        // Add the ith entry of the vector into the last entry of the current row
        data_[i][num_cols_] = v[i];
        delete[] old_data[i];
    }

    delete[] old_data;
    num_cols_++;
}

template<typename T>
T& Matrix<T>::operator()(int i, int j)
{
    assert(i > 0);
    assert(i < num_rows_ + 1);
    assert(j > 0);
    assert(j < num_cols_ + 1);
    return data_[i-1][j-1];
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m1)
{
    // Delete existing matrix entries first, then allocate new memory
    for (int i=0; i < num_cols_; i++)       
    {                                       
        delete[] data_[i];                  
    }

    delete[] data_;
    data_ = new T*[num_rows_];
    
    // Create new matrix and fill with entries of m1
    num_rows_ = m1.num_rows_;
    num_cols_ = m1.num_cols_;
    for (int i=0; i < num_rows_; i++)
    {
        data_[i] = new T[num_cols_];
        for (int j=0; j < num_cols_; j++)
        {
            data_[i][j] = m1.data_[i][j];
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& m1) const
{
    Matrix<T> sum = Matrix<T>(*this);
    for (int i=0; i < sum.GetNumRows(); i++)
    {
        for (int j=0; j < sum.GetNumCols(); j++)
        {
            sum.data_[i][j] = sum.data_[i][j] + m1.data_[i][j];
        }
    }

    return sum;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& m1) const
{
    Matrix<T> difference = Matrix<T>(*this);
    for (int i=0; i < difference.GetNumRows(); i++)
    {
        difference.data_[i] = new T[num_cols_];
        for (int j=0; j < difference.GetNumCols(); j++)
        {
            difference.data_[i][j] = difference.data_[i][j] - m1.data_[i][j];
        }
    }

    return difference;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(double scalar) const
{
    for (int i=0; i < num_rows_; i++)
    {
        for (int j=0; j < num_cols_; j++)
        {
            data_[i][j] = data_[i][j] * scalar;
        }
    }
}

template<typename T>
Vector<T> Matrix<T>::operator*(const Vector<T>& v) const
{
    assert(v.GetSize() == GetNumCols());
    Vector<T> prod = Vector<T>(v.GetSize());            // initialize new vector with same size as v, all 0
    for (int i=0; i < v.GetSize(); i++)
    {
        for (int j=0; j < GetNumCols(); j++)
        {
            prod.entries_[i] = prod.entries_[i] + (data_[i][j] * v.entries_[j]);
        }
    }
    return prod;
}
