#include "Vector.hpp"
#include "Complex.hpp"
#include <iostream>
#include <cmath>

int main(){

    Complex z = Complex(7, 6.20);
    z.Print();
    Vector<Complex> v1;
    v1.Append(z);
    v1[0].Print();
    return 0;
}