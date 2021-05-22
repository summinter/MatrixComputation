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
    Matrix elementWiseMultiple(Matrix &a);
    double findMax();
    double findMaxByRow(int rowNum);
    double findMaxByCol(int colNum);
    double findMin();
    double findMinByRow(int rowNum);
    double findMinByCol(int colNum);
    double getSum();
    double getSumByRow(int rowNum);
    double getSumByCol(int colNum);
    double getAverage();
    double getAverageByRow(int rowNum);
    double getAverageByCol(int colNum);
    Matrix operator+(Matrix &a);
    Matrix operator-(Matrix &a);
    Matrix operator*(Matrix &a);
    Matrix operator*(vector<double> a);
    friend Matrix operator*(vector<double> vec, Matrix &a);




    vector<vector<double>> mat;
    int row;
    int col;
    Matrix(int row, int col);
};


#endif
