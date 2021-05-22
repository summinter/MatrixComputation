//
// Created by ccyys on 2021/5/22.
//

#include "Matrix.h"

int main(){
    Matrix matrix1(3,4);
    matrix1.setValue({{1,2,3,4},
                     {5,6,7,8},
                     {9,10,11,12}});
    cout << matrix1.findMaxByCol(1) << " " << matrix1.findMinByCol(1) << " " << matrix1.getSumByCol(1) << " " << matrix1.getAverageByCol(1);

}