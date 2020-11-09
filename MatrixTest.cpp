#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

int main()
{
    std::cout << "Testing..." << std::endl;

    // Constructors

    // 1. Default constructor
    Matrix<int> m1;
    assert(m1.GetNumRows() == 0);
    assert(m1.GetNumCols() == 0);

    // 2. Non-default with dimensions
    Matrix<int> m2(1, 1);
    assert(m2.GetNumRows() == 1);
    assert(m2.GetNumCols() == 1);
    assert(m2(1,1) == 0);

    Matrix<int> m3(10, 10);
    assert(m3.GetNumRows() == 10);
    assert(m3.GetNumCols() == 10);

    // 3. Non-default with 


    std::cout << "Testing completed." << std::endl;
    return 0;
}