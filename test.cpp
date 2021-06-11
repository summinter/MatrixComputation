//
// Created by ccyys on 2021/5/22.
//

#include <complex>
#include "Matrix.hpp"

using std::complex;
int main(){


    cout << "test transposition" << endl;
    Matrix<double> matrix1(3,3);
    matrix1.setValue({{3,7,5},
                      {6,9,7},
                      {8,8,8}});
    matrix1.transposition().showMatrix();
    cout << "---------------------" << endl;

    cout << "test conjugation" << endl;
    Matrix<complex<double>> matrix2(3,3);
    matrix2.setValue({{complex<double>(1,-5),7,5},
                      {6,9,7},
                      {8,8,8}});
    matrix2.conjugation().showMatrix();
    cout << "---------------------" << endl;

    cout << "test dot product" << endl;
    Matrix<double> matrix3(3,1);
    matrix3.setValue({{1},{4},{5}});
    cout << matrix3.dotProduct(matrix3);
    cout << endl;
    cout << "---------------------" << endl;

    cout << "test cross product" << endl;
    Matrix<double> matrix4(3,1);
    matrix4.setValue({{1},{2},{3}});
    for(int i = 0;i<3;i++){
        cout << matrix3.crossProduct(matrix4)[i] << " ";
    }

    cout << endl << "---------------------" << endl;

    cout << "test convolution" << endl;
    Matrix<double> matrix5(2,2);
    matrix5.setValue({{1,2},{2,3}});
    matrix1.convolution(matrix5).showMatrix();


    cout << endl << "---------------------" << endl;

    cout << "test inverse" << endl;
    inverse(matrix1).showMatrix();


    cout << endl << "---------------------" << endl;


    cout << "test trace" << endl;
    cout << matrix1.trace();


    cout << endl << "---------------------" << endl;


    cout << "test reshape" << endl;
    matrix1.reshape(4,4).showMatrix();


    cout << endl << "---------------------" << endl;



    cout << "test slice" << endl;
    matrix1.reshape(2,2).showMatrix();


    cout << endl << "---------------------" << endl;


}