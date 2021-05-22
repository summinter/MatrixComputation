//
// Created by ccyys on 2021/5/22.
//

#include "Matrix.h"

int main(){
    Matrix matrix1(3,4);
    Matrix matrix2(3,5);
    vector<vector<double>> vec = {{1,2,3,4},
                                  {1,2,3,4},
                                  {1,2,3,4}};
    vector<vector<double>> vec2 = {{1,2,3,4,5},
                                  {1,2,3,4,5},
                                  {1,2,3,4,5}};
    matrix1.setValue(vec2);
    matrix2.setValue(vec2);
    matrix1 = matrix2 + matrix1;
    matrix1.showMatrix();
}