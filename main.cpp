#include "Vector.hpp"
#include <iostream>
#include <cmath>

int main(){

    Vector<int> my_vec;
    my_vec.Append(0);
    my_vec.Append(1);
    my_vec.Append(420);
    std::cout << my_vec.GetElement(0) << std::endl;
    std::cout << my_vec.GetElement(1) << std::endl;
    std::cout << my_vec.GetElement(2) << std::endl;
    std::cout << my_vec.GetSize() << std::endl;
    Vector<int> my_vec_1 = Vector<int>(3);
    my_vec_1.SetElement(0, 0);
    my_vec_1.SetElement(1, 1);
    my_vec_1.SetElement(2, 420);
    Vector<int> sum_vec(3);
    sum_vec = my_vec + my_vec_1;
    for (int i=0; i<sum_vec.GetSize(); i++)
    {
        std::cout << sum_vec.GetElement(i) << std::endl;
    }
    return 0;

    Vector<int> my_vec_2 = Vector<int>(0);
    std::cout << my_vec_2[1] << std::endl;
    return 0;
}