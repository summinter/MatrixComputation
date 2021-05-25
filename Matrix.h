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

class Matrix {
public:
    void setValue(vector<vector<double>>);

    void showMatrix();

    Matrix operator+(Matrix &a);

    Matrix operator-(Matrix &a);

    Matrix operator*(double a);

    friend Matrix operator*(double a, const Matrix &other);

    Matrix operator/(double a);

    Matrix transposition();

    Matrix conjugation();

    double dotProduct(Matrix &other);

    double crossProduct(Matrix &other);

    bool isVector() const;

    double det();

    vector<vector<double>> mat;
    int row;
    int col;

    Matrix(int row, int col);

    int Find(int i, int row);

    void Swap(int i, int j, int row);

private:
    vector<vector<double>> *ptr;
};


#endif
