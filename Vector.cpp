#include "Vector.hpp"
#include "Complex.hpp"
#include <cmath>
#include <iostream>

template<typename T>
Vector<T>::Vector()
{
    // Initialize empty vector
    size_ = 0;
    data_ = new T[size_];
}

template<typename T>
Vector<T>::Vector(int size)
{
    size_ = size;
    data_ = new T[size_];
    //fill vector with zeros
    for (int i=0; i<size_; i++)
    {
        data_[i] = 0;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v1)
{
    size_ = v1.size_;
    data_ = new T[size_];
    for (int i=0; i < size_; i++)
    {
        data_[i] = v1.data_[i];
    }
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] data_;
}

template<typename T>
int Vector<T>::GetSize() const
{
    return size_;
}

template<typename T>
void Vector<T>::SetElement(int index, const T& element)
{
    data_[index] = element;
}

template<typename T>
void Vector<T>::Append(const T& element)
{   
    // Resize data_
    T * new_data = new T[size_+1];      // Create new array that is one element larger
    for (int i=0; i<size_; i++)
    {   
        new_data[i] = data_[i];         // Copy data_ into new array
    }
    new_data[size_] = element;
    size_++;
}

template<typename T>
T Vector<T>::GetElement(int index) const
{
    return data_[index];
}

template<typename T>
T& Vector<T>::operator[](int i)
{   
    // If given index is out of bounds, return -1 to denote error
    if (i < 0 || i >= size_){
        return -1;                  
    }
    return data_[i];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v1)
{
    size_ = v1.size_;
    delete[] data_;
    data_ = new T[size_];
    for (int i=0; i < size_; i++)
    {
        data_[i] = v1.data_[i];
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
        new_vector[i] = (data_[i] + v1.data_[i]);
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
        new_vector[i] = (data_[i] - v1.data_[i]);
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
        len = len + (data_[i]*data_[i]);
    }
    return sqrt(len);
}

int main(){
    return 0;
}