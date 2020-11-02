#include "Complex.hpp"
#include <iostream>
#include <cmath>

Complex::Complex()
{
    real_ = 0;
    imag_ = 0;
}

Complex::Complex(double real, double imag)
{
    real_ = real;
    imag_ = imag;
}

Complex::Complex(const Complex& z1)
{
    real_ = z1.real_;
    imag_ = z1.imag_;
}

Complex& Complex::operator=(const Complex& z1)
{
    if (*this != z1)
    {
        real_ = z1.real_;
        imag_ = z1.imag_;
    }
    return *this;
}

Complex Complex::GetConjugate()
{
    Complex conjugate = Complex(real_, (imag_*-1));
    return conjugate;
}

double Complex::GetReal() const
{
    return real_;
}

double Complex::GetImag() const
{
    return imag_;
}

double Complex::GetAbsolute() const
{
    return sqrt((real_ * real_) + (imag_ * imag_));
}

double Complex::GetDistance(const Complex& z1) const
{
    Complex difference = Complex(real_, imag_);
    difference = difference - z1;
    return difference.GetAbsolute();
}

void Complex::SetReal(double real)
{
    real_ = real;
}

void Complex::SetImag(double imag)
{
    imag_ = imag;
}

void Complex::Print() const
{
    std::cout << real_ << " + " << imag_ << "i";
}

bool Complex::operator==(const Complex& z1) const
{
    if (real_ == z1.real_ && imag_ == z1.imag_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Complex::operator!=(const Complex& z1) const
{
    if (real_ != z1.real_ || imag_ != z1.imag_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Complex Complex::operator+(const Complex& z1) const
{
    Complex sum = Complex(real_, imag_);
    sum.real_ = sum.real_ + z1.real_;
    sum.imag_ = sum.imag_ + z1.imag_;
    return sum;
}

Complex Complex::operator-(const Complex& z1) const
{
    Complex diff = Complex(real_, imag_);
    diff.real_ = diff.real_ - z1.real_;
    diff.imag_ = diff.imag_ - z1.imag_;
    return diff;
}

Complex Complex::operator*(const Complex& z1) const
{
    Complex prod = Complex(real_, imag_);
    prod.real_ = (prod.real_ * z1.real_) - (z1.imag_ * prod.imag_);
    prod.imag_ = (prod.real_ * z1.imag_) + (z1.imag_ * prod.real_);
    return prod;
}