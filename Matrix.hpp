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


template <class T>
    class Matrix{
    public:
        void setValue(vector<vector<T>>);
        void showMatrix();
        Matrix elementWiseMultiple(Matrix &a);
        T findMax();
        T findMaxByRow(int rowNum);
        T findMaxByCol(int colNum);
        T findMin();
        T findMinByRow(int rowNum);
        T findMinByCol(int colNum);
        T getSum();
        T getSumByRow(int rowNum);
        T getSumByCol(int colNum);
        T getAverage();
        T getAverageByRow(int rowNum);
        T getAverageByCol(int colNum);
        Matrix operator+(Matrix &a);
        Matrix operator-(Matrix &a);
        Matrix operator*(Matrix &a);
        Matrix operator*(vector<T> a);

        //friend function must be write inside the class
        friend Matrix<T> operator*(vector<T> vec, Matrix &a){
            if(vec.size() != a.mat.size()){
                cout << "This vector cannot be multiplied with a matrix.";
                exit(0);
            }
            Matrix<T> res(1, a.mat[0].size());
            for(int i = 0;i < a.mat[0].size();i++){
                res.mat[0][i] = 0;
                for(int j = 0;j < a.mat.size();j++){
                    res.mat[0][i] += vec[j] * a.mat[j][i];
                }
            }
            return res;
        }

        vector<vector<T>> mat;
        int row;
        int col;
        Matrix(int row, int col);
    };


template<class T>
Matrix<T>::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
    vector<T> temp(col);
    this->mat.resize(row, temp);
}

template<class T>
void Matrix<T>::setValue(vector<vector<T>> valueMat) {
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

template<class T>
void Matrix<T>::showMatrix() {
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
Matrix<T> Matrix<T>::elementWiseMultiple(Matrix<T> &a){
    if(mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()){
        cout << "Matrix size does not match! Element wise multiplication operation failed.";
        exit(0);
    }
    Matrix<T> res(row, col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            res.mat[i][j] = mat[i][j] * a.mat[i][j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &a) {
    if(mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()){
        cout << "Matrix size does not match! Plus operation failed.";
        exit(0);
    }
    Matrix<T> res(row, col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            res.mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &a) {
    if(mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()){
        cout << "Matrix size does not match! Subtraction operation failed.";
        exit(0);
    }
    Matrix<T> res(row, col);
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            res.mat[i][j] = mat[i][j] - a.mat[i][j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &a) {
    if(mat[0].size() != a.mat.size()){
        cout << "Matrix size does not match! Two matrix multiplication failed.";
        exit(0);
    }
    Matrix<T> res(row, a.col);
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

template<class T>
Matrix<T> Matrix<T>::operator*(vector<T> vec){
    if(mat[0].size() != 1){
        cout << "This matrix cannot be multiplied with a vector.";
        exit(0);
    }
    Matrix<T> res(row, vec.size());
    for(int i = 0;i < mat.size();i++){
        for(int j = 0; j < vec.size(); j++){
            res.mat[i][j] = mat[i][0] * vec[j];
        }
    }
    return res;
}



template<class T>
T Matrix<T>::findMax(){
    T max = INT32_MIN;
    for(int i = 0; i < mat.size();i++){
        for(int j = 0;j < mat[0].size();j++){
            if(mat[i][j] > max){
                max = mat[i][j];
            }
        }
    }
    return max;
}

template<class T>
T Matrix<T>::findMaxByRow(int rowNum){
    if(rowNum > row){
        cout << "Your input row number is too large";
        exit(0);
    }
    T max = INT32_MIN;
    for(int i = 0; i < mat[0].size();i++){
        if(mat[rowNum][i] > max){
            max = mat[rowNum][i];
        }
    }
    return max;
}

template<class T>
T Matrix<T>::findMaxByCol(int colNum){
    if(colNum > col){
        cout << "Your input col number is too large";
        exit(0);
    }
    T max = INT32_MIN;
    for(int i = 0; i < mat.size();i++){
        if(mat[i][colNum] > max){
            max = mat[i][colNum];
        }
    }
    return max;
}

template<class T>
T Matrix<T>::findMin(){
    T min = INT32_MAX;
    for(int i = 0; i < mat.size();i++){
        for(int j = 0;j < mat[0].size();j++){
            if(mat[i][j] < min){
                min = mat[i][j];
            }
        }
    }
    return min;
}

template<class T>
T Matrix<T>::findMinByRow(int rowNum){
    if(rowNum > row){
        cout << "Your input row number is too large";
        exit(0);
    }
    T min = INT32_MAX;
    for(int i = 0; i < mat[0].size();i++){
        if(mat[rowNum][i] < min){
            min = mat[rowNum][i];
        }
    }
    return min;
}

template<class T>
T Matrix<T>::findMinByCol(int colNum){
    if(colNum > col){
        cout << "Your input col number is too large";
        exit(0);
    }
    T min = INT32_MAX;
    for(int i = 0; i < mat.size();i++){
        if(mat[i][colNum] < min){
            min = mat[i][colNum];
        }
    }
    return min;
}

template<class T>
T Matrix<T>::getSum(){
    T sum = 0;
    for(int i = 0; i < mat.size();i++){
        for(int j = 0;j < mat[0].size();j++){
            sum += mat[i][j];
        }
    }
    return sum;
}

template<class T>
T Matrix<T>::getSumByRow(int rowNum){
    T sum = 0;
    for(int i = 0;i < mat[0].size();i++){
        sum += mat[rowNum][i];
    }
    return sum;
}


template<class T>
T Matrix<T>::getSumByCol(int colNum){
    T sum = 0;
    for(int i = 0;i < mat.size();i++){
        sum += mat[i][colNum];
    }
    return sum;
}

template<class T>
T Matrix<T>::getAverage(){
    return Matrix::getSum()/(row*col);
}
template<class T>
T Matrix<T>::getAverageByRow(int rowNum){
    return Matrix::getSumByRow(rowNum)/(row*col);
}
template<class T>
T Matrix<T>::getAverageByCol(int colNum){
    return Matrix::getSumByCol(colNum)/(row*col);
}




#endif
