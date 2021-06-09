//
// Created by ccyys on 2021/5/22.
//

#include <complex>
#include "Matrix.hpp"

using std::complex;
int main(){


    Matrix<complex<double>> matrix1(3,4);
    matrix1.setValue({{complex<double>(1,2),complex<double>(3,-2),3,4},
                     {complex<double>(-1,-5),6,7,8},
                     {9,10,11,12}});

    matrix1.conjugation().showMatrix();

}