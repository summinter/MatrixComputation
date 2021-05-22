//
// Created by ccyys on 2021/5/22.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
class Matrix{
public:
    void setValue(vector<vector<double>>);
    void showMatrix();
    Matrix operator+(Matrix &a);
    Matrix operator-(Matrix &a);

    vector<vector<double>> mat;
    int row;
    int col;
    Matrix(int row, int col);
};


#endif
