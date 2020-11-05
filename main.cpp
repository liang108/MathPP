#include "Vector.hpp"
#include "Matrix.hpp"
#include "Complex.hpp"
#include <iostream>
#include <cmath>

int main(){
    int * my_array = new int[5];
    my_array[0] = 10;
    Vector<int> v = Vector<int>(my_array);
    Vector<int> v1 =Vector<int>(v);
    std::cout << v1[0];
    return 0;
}