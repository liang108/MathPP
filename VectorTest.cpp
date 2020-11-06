#include "Vector.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

// Unit tests for Vector class

int main()
{
    std::cout << "Testing..." << std::endl;

    /***** CONSTRUCTORS *****/ 

    // 1. Default
    Vector<int> v1; 
    assert(v1.GetSize() == 0);

    // 2. Non-default with size parameter
    Vector<double> v2(1);
    assert(v2.GetSize() == 1);
    assert(v2[0] == 0);
    
    Vector<int> v3(20);
    assert(v3.GetSize() == 20);
    assert(v3[0] == 0);
    assert(v3[19] == 0);

    // 3. Non-default with array and size parameters
    int a1[5] = {1,2,3,4,5};
    Vector<int> v4(a1, 5);
    assert(v4[0] == 1);
    assert(v4[4] == 5);
    assert(v4.GetSize() == 5);

    // 4. Copy constructor
    Vector<int> v5(v4);
    assert(v4[0] == 1);
    assert(v4[2] == 3);
    assert(v4[4] == 5);
    assert(v4.GetSize() == 5);


    std::cout << "Testing completed." << std::endl;
    return 0;
}