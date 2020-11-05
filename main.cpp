#include "Vector.hpp"
#include "Matrix.hpp"
#include "Complex.hpp"
#include <iostream>
#include <cmath>

int main(){
    int * my_array = new int[3];
    my_array[0] = 1;
    my_array[1] = 2;
    my_array[2] = 3;
    /*my_array[3] = 4;
    my_array[4] = 5;*/
    Vector<int> v = Vector<int>(my_array, 3);
    std::cout << v.length() << std::endl;

    return 0;
}