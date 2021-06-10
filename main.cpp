//
// Created by ccyys on 2021/5/22.
//

#include <complex>
#include "Matrix.hpp"

using std::complex;
int main(){


    Matrix<double> matrix1(3,3);
    matrix1.setValue({{1,2,3},
                      {4,5,6},
                      {7,8,9}});
    Matrix<double> matrix2(2,2);
    matrix2.setValue({{1,2},
                      {4,5}});

    cout << matrix1.trace();



}