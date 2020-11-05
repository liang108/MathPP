#include "Vector.hpp"
#include "Matrix.hpp"
#include "Complex.hpp"
#include <iostream>
#include <cmath>

int main(){
    int * my_array = new int[5];
    my_array[0] = 10;
    my_array[1] = 11;
    my_array[2] = 12;
    my_array[3] = 13;
    my_array[4] = 14;
    Vector<int> v = Vector<int>(my_array, 5);
    for (int i=0; i < 5; i++)
    {
        std::cout << my_array[i] <<"\n";
    }
    Vector<int> v1 = Vector<int>(v);
    std::cout << v.GetSize();
    return 0;
}