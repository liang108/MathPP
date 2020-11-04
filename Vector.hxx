#include "Vector.hpp"
#include "Complex.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <cassert>

template<typename T>
Vector<T>::Vector()
{
    // Initialize empty vector
    size_ = 0;
    entries_ = nullptr;
}

template<typename T>
Vector<T>::Vector(int size)
{
    assert(size > 0);
    size_ = size;
    entries_ = new T[size_];
    //fill vector with zeros
    for (int i=0; i<size_; i++)
    {
        entries_[i] = T();          // Call default constructor for T objects
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v1)
{
    size_ = v1.size_;
    entries_ = new T[size_];
    for (int i=0; i < size_; i++)
    {
        entries_[i] = v1.entries_[i];
    }
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] entries_;
}

template<typename T>
int Vector<T>::GetSize() const
{
    return size_;
}

template<typename T>
void Vector<T>::SetElement(int index, const T& element)
{
    entries_[index] = element;
}

template<typename T>
void Vector<T>::Append(const T& element)
{   
    T * new_data = new T[size_+1];      // Create new array that is one element larger
    if (size_ == 0)                     // If vector is empty, need to avoid copying junk values
    {
        new_data[0] = element;
        entries_ = new_data;
        size_++;
        return;
    }
    for (int i=0; i<size_; i++)         // Copy values from old array
    {
        new_data[i] = entries_[i];
    }
    new_data[size_] = element;          // Set last element of new array to element being appended
    size_++;
    entries_ = new_data;
    new_data = nullptr;
}

template<typename T>
T Vector<T>::GetElement(int index) const
{
    return entries_[index];
}

template<typename T>
T& Vector<T>::operator[](int i)
{   
    //If vector is empty
    if (size_ == 0)
    {
        throw std::length_error("Vector is empty");
    }

    // If given index is out of bounds
    if (i < 0 || i >= size_)
    {
        throw std::out_of_range("Given index is not in vector");
    }

    return entries_[i];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v1)
{
    size_ = v1.size_;
    delete[] entries_;
    entries_ = new T[size_];
    for (int i=0; i < size_; i++)
    {
        entries_[i] = v1.entries_[i];
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& v1) const
{
    Vector<T> new_vector = Vector(size_);
    if (size_ != v1.size_)
    {
        std::cout << "Error: vectors are of different lengths" << std::endl;
        return new_vector;
    }
    for (int i=0; i < size_; i++)
    {
        new_vector[i] = (entries_[i] + v1.entries_[i]);
    }
    return new_vector;
}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& v1) const
{
    Vector<T> new_vector = Vector(size_);
    if (size_ != v1.size_)
    {
        std::cout << "Error: vectors are of different lengths" << std::endl;
        return new_vector;
    }
    for (int i=0; i < size_; i++)
    {
        new_vector[i] = (entries_[i] - v1.entries_[i]);
    }
    return new_vector;    
}

template<typename T>
Vector<T> Vector<T>::operator*(const T& scalar) const
{
    Vector<T> new_vector = Vector(size_);
    for (int i=0; i < size_; i++)
    {
        new_vector[i] = new_vector[i]*scalar;
    }
    return new_vector;       
}

template<typename T>
T Vector<T>::length() const
{
    // Return the length of the vector (not the number of elements but the actual length, ie. the norm)
    // Norm of a vector x in R^n as sqrt(x_1^2 + x_2^2 + ... + x_n^2)
    T len;
    for (int i=0; i < size_; i++)
    {
        len = len + (entries_[i]*entries_[i]);
    }
    return sqrt(len);
}