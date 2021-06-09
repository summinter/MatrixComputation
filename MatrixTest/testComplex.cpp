//
// Created by ccyys on 2021/5/22.
//

#include <complex>
#include "../Matrix.hpp"

using std::complex;
int main(){


    //test elementWiseMultiple()
    cout << "test elementWiseMultiple(): " << endl;
    Matrix<complex<double>> matrix1(3,4);
    matrix1.setValue({{complex<double>(1,2),complex<double>(3,-2),3,4},
                      {complex<double>(-1,-5),6,7,8},
                      {9,10,11,12}});

    Matrix<complex<double>> matrix2(3,4);
    matrix2.setValue({{complex<double>(1,2),complex<double>(3,-2),3,4},
                      {complex<double>(-1,-5),6,7,8},
                      {9,10,11,12}});
    matrix1.elementWiseMultiple(matrix2).showMatrix();
    cout << "--------------------"<< endl;

    //test conjugation()
    cout << "test conjugation(): " << endl;
    matrix1.conjugation().showMatrix();
    cout << "--------------------"<< endl;

    //test transposition()
    cout << "test transposition(): " << endl;
    matrix1.transposition().showMatrix();
    cout << "--------------------"<< endl;

    //test +
    cout << "test +: " << endl;
    Matrix<complex<double>> matrix3(3,4);
    (matrix1+matrix2).showMatrix();
    cout << "--------------------"<< endl;

    //test -
    cout << "test -: " << endl;
    (matrix1-matrix2).showMatrix();
    cout << "--------------------"<< endl;

    //test * by matrix
    cout << "test * by matrix: " << endl;
    Matrix<complex<double>> matrix4(4,3);
    matrix4.setValue({{complex<double>(1,2),complex<double>(3,-2),3},
                      {complex<double>(-1,-5),6,7},
                      {9,10,11},
                      {1,2,3}});
    (matrix1*matrix4).showMatrix();
    cout << "--------------------"<< endl;


    //test * by number
    cout << "test * by number: " << endl;
    (matrix1*5).showMatrix();
    cout << "--------------------"<< endl;


//    //test /
//    cout << "test /: " << endl;
//    (matrix1/5).showMatrix();
//    cout << "--------------------"<< endl;

}