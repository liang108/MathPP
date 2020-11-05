#include "Vector.hpp"
#include "Matrix.hpp"
#include "Complex.hpp"
#include <iostream>
#include <cmath>

int main(){

    Matrix<int> my_matrix = Matrix<int>(5, 5);
    std::cout<< my_matrix.GetNumCols();
    std::cout << my_matrix.GetNumRows();
    int result = my_matrix(1,1);
    std::cout << result;

    return 0;
}