#pragma once

#include "Vector.hpp"

//TODO: Implement operators for complex multiplication

template<typename T>
class Matrix 
{
    private: 
        T** data_;                                      // A pointer to an array of pointers, each to an array of type T
        size_t num_rows_;                               // Vertical dimension
        size_t num_cols_;                               // Horizontal dimension
    
    public:
        // Constructors
        Matrix<T>();                                       // Initialize empty matrix, data_ is nullptr
        Matrix<T>(size_t num_rows, size_t num_cols);       // Initialize with dimensions, entries are all 0
        Matrix<T>(const Vector<Vector<T>>& v1);            // Given a vector of vectors, assert all are equal length
        Matrix<T>(const Matrix& m1);                       // Copy Constructor

        // Destructor
        ~Matrix<T>();                                      // Need to deallocate heap memory

        // Member functions
        int GetNumRows();
        int GetNumCols();

        // Operators
        T& operator()(int i, int j);                     // 1-based indexing operator
        Matrix<T>& operator=(const Matrix<T>& m1);            // Copy assignment
        Matrix<T> operator+(const Matrix<T>& m1) const;       // Binary addition, checks if matrices are equal size
        Matrix<T> operator-(const Matrix<T>& m1) const;       // Binary subtraction
        Matrix<T> operator*(double scalar) const;             // Scalar multiplication
        Vector<T> operator*(const Vector<T>& v) const;      // Multiply a matrix and vector
};

#include "Matrix.hxx"