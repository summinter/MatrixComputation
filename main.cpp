//
// Created by ccyys on 2021/5/22.
//

#include <complex>
#include "Matrix.hpp"

using std::complex;
int main(){


    Matrix<double> matrix1(3,3);
    matrix1.setValue({{3,7,5},
                      {6,9,7},
                      {8,8,8}});

    inverse(matrix1).showMatrix();

}