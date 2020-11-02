#pragma once

class Complex
{
    private:
        // A complex number z is: z = a + bi, where a is the real part and b is the imaginary part, and a and b are real numbers
        double real_;                                   // Real part
        double imag_;                                   // Imaginary part
    public:
        // Constructors
        Complex();                                      // Initialize real and imag parts to zero
        Complex(double real, double imag);              // Initialize real and imag parts
        Complex(const Complex& z1);                     // Copy Constructor

        // Copy assignment
        Complex& operator=(const Complex& z1);          // Return reference to a complex

        // Member functions
        Complex Conjugate();                         // Conjugate of z = a+bi is z_bar = a-bi
        double GetReal() const;
        double GetImag() const;
        double Absolute() const;                     // Absolute value or modulus
        double Distance(const Complex& z1) const;    // Distance between two complex numbers
        void SetReal(double real);
        void SetImag(double imag);
        void Print() const;                                   // Output to console in form a+bi

        // Operators
        bool operator==(const Complex& z1) const;
        bool operator!=(const Complex& z1) const;
        Complex operator+(const Complex& z1) const;           // Binary addition
        Complex operator-(const Complex& z1) const;           // Binary subtraction
        Complex operator*(const Complex& z1) const;           // Binary multiplication

};

# include "Complex.hxx"