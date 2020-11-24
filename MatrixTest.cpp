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

    // 3. Copy constructor
    Matrix<int> m4(m3);
    assert(m4.GetNumRows() == 10);
    assert(m4.GetNumCols() == 10);
    assert(m4(1,1) == 0);
    assert(m4(10,10) == 0);

    // Member functions

    // GetNumRows and GetNumCols pass above tests
    // 1. Append Row
    Vector<int> v1(10);
    v1[9] = 42;
    m4.AppendRow(v1);
    assert(m4.GetNumRows() == 11);

    std::cout << "Testing completed." << std::endl;
    return 0;
}