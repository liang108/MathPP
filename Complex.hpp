#pragma once

class Complex
{
    private:
        // A complex number z is: z = a + bi, where a is the real part and b is the imaginary part, and a and b are real numbers
        double real_;   // Real part
        double imag_;   // Imaginary part
    public:
        // Constructors
        Complex();                                      // Initialize real and imag parts to zero
        Complex(double real, double imag);              // Initialize real and imag parts
        Complex(const Complex& z1);                     // Copy Constructor

        // Member functions
        Complex GetConjugate(Complex z);                // Conjugate of z = a+bi is z_bar = a-bi
        
};