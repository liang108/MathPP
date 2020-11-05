#include "Vector.hpp"
#include "Matrix.hpp"
#include "Complex.hpp"
#include <iostream>
#include <cmath>

int main(){
    int * my_array = new int[1];
    my_array[0] = 1;
    /*my_array[1] = 2;
    my_array[2] = 3;
    my_array[3] = 4;
    my_array[4] = 5;*/
    Vector<int> v = Vector<int>(my_array, 1);
    Vector<int> v1 = Vector<int>(1);
    Vector<int> v2 = Vector<int>(1);
    v1[0] = 6;
    /*v1[1] = 7;
    v1[2] = 8;
    v1[3] = 9;
    v1[4] = 10;*/
    double result;
    //result = v * v1;
    v1 = v1 * 69;
    std::cout << result;
    std::cout << "\n" << v1[0];
    return 0;
}