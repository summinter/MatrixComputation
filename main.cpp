//
// Created by ccyys on 2021/5/22.
//

#include "Matrix.h"

int main(){
    Matrix matrix1(4,2);
    matrix1.setValue({{1,2},{1,2},{1,2},{1,2}});
    vector<double> vec = {1,2,3,4};
    matrix1 = vec * matrix1;
    matrix1.showMatrix();
}