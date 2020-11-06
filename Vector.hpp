#pragma once
#include <cstddef>

// TODO: Define operators (multiplication, length) to work with complex numbers
//#include "Complex.hpp"
//Use templates to allow for complex numbers, ints, and doubles
//Vector as used in linear algebra

template<typename T>
class Vector
{
    private:
        T * entries_;                                     // Pointer to array of entries of type T
        size_t size_;                                     // Track size of vector
    public:
        // Constructors 
        Vector<T>();                                      // Default sets an empty vector with size 0
        Vector<T>(size_t size);                           // Non-default, initialize with size, entries are all 0
        Vector<T>(T * data, size_t size);                 // Non-default, initialize with an existing array
        Vector<T>(const Vector<T>& v1);                   // Copy constructor
        
        // Destructor
        ~Vector<T>();                                     // De-allocate array memory on heap
        
        // Member functions
        int GetSize() const;                              // Return data member size_
        void SetElement(int index, const T& element);     // Change array element at index
        void Append(const T& element);                    // AKA Push back. Expensive: should know vector lengths before compile time
        
        // Indexing
        T GetElement(int index) const;                    // Return a copy of element at index
        T& operator[] (int i);                            // Zero-based indexing

        // Copy Assignment
        Vector<T>& operator=(const Vector<T>& v1);        // Copy assignment. Create new instance, then return a reference to that instance
        
        // Arithmetic - note that we don't want to change the original vectors, only return a copy of modified entries
        Vector<T> operator+(const Vector<T>& v1) const;   // Binary +
        Vector<T> operator-(const Vector<T>& v1) const;   // Binary -
        Vector<T> operator*(const T& scalar) const;       // Binary Scalar Multiplication
        double operator*(const Vector<T>& v1) const;      // Dot product, returns scalar
        //friend Complex operator*(const Vector<Complex>& v1);      // Dot product of complex vectors

        // Length of vector (aka norm)
        double length() const;        // For real vectors only
        
        //friend double length_complex(const Vector<Complex>& v1);    // For complex vector                      
};

//Complex operator*(const Vector<Complex>& v1, const Vector<Complex>& v2);
//double length_complex(const Vector<Complex>& v1);

#include "Vector.hxx"