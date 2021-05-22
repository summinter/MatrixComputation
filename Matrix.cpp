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
Matrix Matrix::elementWiseMultiple(Matrix &a){
    if(mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()){
        cout << "Matrix size does not match! Element wise multiplication operation failed.";
        exit(0);
    }
    Matrix res(row, col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            res.mat[i][j] = mat[i][j] * a.mat[i][j];
        }
    }
    return res;
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

Matrix Matrix::operator-(Matrix &a) {
    if(mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()){
        cout << "Matrix size does not match! Subtraction operation failed.";
        exit(0);
    }
    Matrix res(row, col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            res.mat[i][j] = mat[i][j] - a.mat[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(Matrix &a) {
    if(mat[0].size() != a.mat.size()){
        cout << "Matrix size does not match! Two matrix multiplication failed.";
        exit(0);
    }
    Matrix res(row, a.col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < a.col;j++){
            res.mat[i][j] = 0;
            for(int k = 0; k < col;k++){
                res.mat[i][j] += mat[i][k] * a.mat[k][j];
            }
        }
    }
    return res;
}
Matrix Matrix::operator*(vector<double> vec){
    if(mat[0].size() != 1){
        cout << "This matrix cannot be multiplied with a vector.";
        exit(0);
    }
    Matrix res(row, vec.size());
    for(int i = 0;i < mat.size();i++){
        for(int j = 0; j < vec.size(); j++){
            res.mat[i][j] = mat[i][0] * vec[j];
        }
    }
    return res;
}

Matrix operator*(vector<double> vec, Matrix &a){
    if(vec.size() != a.mat.size()){
        cout << "This vector cannot be multiplied with a matrix.";
        exit(0);
    }
    Matrix res(1, a.mat[0].size());
    for(int i = 0;i < a.mat[0].size();i++){
        res.mat[0][i] = 0;
        for(int j = 0;j < a.mat.size();j++){
            res.mat[0][i] += vec[j] * a.mat[j][i];
        }
    }
    return res;
}







