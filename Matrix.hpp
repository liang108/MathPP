#pragma once

#include "Vector.hpp"

template<typename T>
class Matrix 
{
    private: 
        T** data_;                                      // A pointer to an array of pointers to an array of type T
        size_t num_rows_;                               // Vertical dimension
        size_t num_cols_;                               // Horizontal dimension
    
    public:
        Matrix();                                       // Initialize empty matrix, data_ is nullptr
        Matrix(size_t num_rows, size_t num_cols);       // Initialize with dimensions, entries are all 0
        Matrix(const Matrix& m1);  

};