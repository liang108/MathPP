#pragma once

//Use templates to allow for complex numbers, ints, and doubles

template<typename T>
class Vector
{
    private:
        T * entries_;                                     // Pointer to array of entries of type T
        int size_;                                        // Track size of vector
        friend class Matrix;
    public:
        // Constructors - TODO: check that data type being instantiated is either int, double, or complex
        Vector();                                         // Default sets an empty vector with size 0
        Vector(int size);                                 // Non-default, initialize with size, entries are all 0
        Vector(T * data);                                 // Non-default, initialize with an existing array
        Vector(const Vector<T>& v1);                      // Copy constructor
        
        // Destructor
        ~Vector();                                        // De-allocate array memory on heap
        
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

        // Length of vector (aka norm)
        T length() const;                               
};

#include "Vector.hxx"