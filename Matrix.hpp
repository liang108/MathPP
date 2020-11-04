#pragma once

#include "Vector.hpp"

template<typename T>
class Matrix 
{
    private: 
        T** data_;                                      // A pointer to an array of pointers, each to an array of type T
        size_t num_rows_;                               // Vertical dimension
        size_t num_cols_;                               // Horizontal dimension
    
    public:
        // Constructors
        Matrix();                                       // Initialize empty matrix, data_ is nullptr
        Matrix(size_t num_rows, size_t num_cols);       // Initialize with dimensions, entries are all 0
        Matrix(const Vector<Vector<T>>& v1);            // Given a vector of vectors, assert all are equal length
        Matrix(const Matrix& m1);                       // Copy Constructor

        // Destructor
        ~Matrix();                                      // Need to deallocate heap memory

        // Member functions
        int GetNumRows();
        int GetNumCols();

        // Operators
        double& operator()(int i, int j);               // 1-based indexing operator
        Matrix& operator=(const Matrix& m1);            // Copy assignment
        Matrix operator+(const Matrix& m1) const;       // Binary addition, checks if matrices are equal size
        Matrix operator-(const Matrix& m1) const;       // Binary subtraction
        Matrix operator*(double scalar) const;          // Scalar multiplication

        // Friend functions
        friend Vector operator*(const Matrix& m, const Vector& v);      // Multiply a matrix and vector
        friend Vector operator*(const Vector& v, const Matrix& m);      // Same, but parameters switched for usability
};

// Definitions for friend functions
Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);

#include "Matrix.hxx"