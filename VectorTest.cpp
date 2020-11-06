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

    // Member functions

    // 1. GetSize() passes constructor tests above

    // 2. SetElement
    v5.SetElement(0, 42);
    v5.SetElement(4, 108);
    assert(v5[0] == 42);
    assert(v5[4] == 108);

    // 3. Append
    v1.Append(1);
    assert(v1.GetSize() == 1);
    assert(v1[0] == 1);

    v4.Append(6);
    v4.Append(7);
    assert(v4.GetSize() == 7);
    assert(v4[5] == 6);
    assert(v4[6] == 7);

    // 4. GetElement
    assert(v2.GetElement(0) == 0);
    assert(v4.GetElement(6) == v4[6]);

    // Operator Overloading

    // 1. Indexing [] operator: Passed above tests

    // 2. Copy Assignment operator =
    v5 = v1;
    assert(v5[0] == v1[0]);
    assert(v5.GetSize() == 1);
    
    v5 = v4;
    assert(v5.GetSize() == 7);
    assert(v5[0] == 1);
    assert(v5[4] == 5);
    assert(v5[6] == 7);

    // 3. Binary + Operator
    Vector<int> v7(v1);
    v7 = v7 + v1;
    assert(v7[0] == 2);

    Vector<int> v6(7);
    v6 = v5 + v4;
    assert(v6.GetSize() == v4.GetSize());
    assert(v6[0] == 2);
    assert(v6[1] == 4);
    assert(v6[6] == 14);

    // 4. Binary - Operator
    Vector<int> v8(v1);
    v8 = v8 - v1;
    assert(v8[0] == 0);

    Vector<int> v9(v5);
    v9.SetElement(6, 8);
    v9 = v9 - v5;
    assert(v9[0] == 0);
    assert(v9[6] == 1);

    // 5. Scalar * Operator
    v9 = v9 * 3;
    assert(v9.GetSize() == 7);
    assert(v9[3] == 0);
    assert(v9[6] == 3);

    v1 = v1 * 10;
    assert(v1[0] == 10);

    // 6. Dot product * operator
    assert(v1*v1 == 100);
    
    Vector<int> v10(a1, 5);
    Vector<int> v11(v10);
    v11.SetElement(4, 10);
    assert(v10*v11 == 80);

    // Norm function
    assert(v1.norm() == 10);
    v1.SetElement(0, 1);
    v1.Append(1);
    assert(v1.norm() == sqrt(2));
    

    std::cout << "Testing completed." << std::endl;
    return 0;
}