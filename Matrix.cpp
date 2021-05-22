#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
    vector<double> temp(col);
    this->mat.resize(row, temp);
}
void Matrix::setValue(vector<vector<double>> valueMat) {
    if(valueMat.size() != mat.size() || valueMat[0].size() != mat[0].size()){
        cout << "The input value's size does not match the matrix!";
        exit(0);
    }
    for(int i = 0;i < valueMat.size();i++){
        for(int j = 0;j < valueMat[0].size(); j++){
            mat[i][j] = valueMat[i][j];
        }
    }
}

void Matrix::showMatrix() {
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(Matrix &a) {
    if(mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()){
        cout << "Matrix size does not match! Plus operation failed.";
        exit(0);
    }
    Matrix res(row, col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            res.mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
    return res;
}

