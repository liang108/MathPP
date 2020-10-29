#include "Vector.hpp"
#include <iostream>
#include <cmath>

int main(){

    Vector<int> my_vec;
    my_vec.Append(0);
    my_vec.Append(1);
    std::cout << my_vec.GetElement(0) << std::endl;
    std::cout << my_vec.GetElement(1) << std::endl;
    std::cout << my_vec.GetSize() << std::endl;
    return 0;
}