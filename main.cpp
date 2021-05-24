//
// Created by ccyys on 2021/5/22.
//

#include "Matrix.hpp"
int main(){
    Matrix<double> matrix1(3,4);
    matrix1.setValue({{1,2,3,4},
                     {5,6,7,8},
                     {9,10,11,12}});
    vector<double> vec = {1,2,3};
    Matrix<double> matrix2 = vec * matrix1;
    matrix2.showMatrix();

}