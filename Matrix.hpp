//
// Created by ccyys on 2021/5/22.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

template<class T>
class Matrix {
public:
    void setValue(vector <vector<T>>);

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

    Matrix operator*(vector <T> a);

    Matrix operator/(T a);

    Matrix operator*(T a);

    Matrix transposition();

    Matrix conjugation();

    T dotProduct(Matrix &other);

    T crossProduct(Matrix &other);

    bool isVector() const;

    T det();

    T eigenValue();

    Mat intoOpenCV();


    friend Matrix<T> operator*(T a, const Matrix &other) {
        Matrix res(other.row, other.col);
        for (int i = 0; i < other.row; i++) {
            for (int j = 0; j < other.col; j++) {
                res.mat[i][j] = other.mat[i][j] * a;
            }
        }
        return res;
    };

    //friend function must be write inside the class
    friend Matrix<T> operator*(vector <T> vec, Matrix &a) {
        if (vec.size() != a.mat.size()) {
            cout << "This vector cannot be multiplied with a matrix.";
            exit(0);
        }
        Matrix<T> res(1, a.mat[0].size());
        for (int i = 0; i < a.mat[0].size(); i++) {
            res.mat[0][i] = 0;
            for (int j = 0; j < a.mat.size(); j++) {
                res.mat[0][i] += vec[j] * a.mat[j][i];
            }
        }
        return res;
    }

    vector <vector<T>> mat;
    int row{};
    int col{};

    Matrix(int row, int col);

    void Swap(int i, int j, int row);

    int Find(int i, int row);
};

template<class T>
Matrix<T> Matrix<T>::conjugation() {
    Matrix res(col, row);
    res = this->transposition();
    if (typeid(T) == typeid(complex < double > )) {
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                res.mat[j][i] = conj(res.mat[j][i]);
            }
        }
    }
    return res;

}

template<class T>
Matrix<T> Matrix<T>::transposition() {
    Matrix res(col, row);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            res.mat[i][j] = mat[j][i];
        }
    }
    return res;
}

template<class T>
Matrix<T>::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
    vector <T> temp(col);
    this->mat.resize(row, temp);
}

template<class T>
void Matrix<T>::setValue(vector <vector<T>> valueMat) {
    if (valueMat.size() != mat.size() || valueMat[0].size() != mat[0].size()) {
        cout << "The input value's size does not match the matrix!";
        exit(0);
    }
    for (int i = 0; i < valueMat.size(); i++) {
        for (int j = 0; j < valueMat[0].size(); j++) {
            mat[i][j] = valueMat[i][j];
        }
    }
}

template<class T>
void Matrix<T>::setValue(vector <T> valueMat) {
    for (int i = 0; i < valueMat.size(); i++) {
        if (valueMat[i][0] >= mat.size() || valueMat[i][1] >= mat[0].size()) {
            cout << "The input value's index does not match the matrix!";
            exit(0);
        }
        mat[valueMat[i][0]][valueMat[i][1]] = valueMat[i][2];
    }
}

template<class T>
void Matrix<T>::setValue(Mat valueMat) {
    if (valueMat.rows != mat.size() || valueMat.cols != mat[0].size()) {
        cout << "The input value's size does not match the matrix!";
        exit(0);
    }
    for (int i = 0; i < valueMat.rows; i++) {
        for (int j = 0; j < valueMat.cols; j++) {
            this->mat[i][j]=valueMat.at<double>(i, j);
        }
    }
}

template<class T>
void Matrix<T>::showMatrix() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
Matrix<T> Matrix<T>::elementWiseMultiple(Matrix<T> &a) {
    if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()) {
        cout << "Matrix size does not match! Element wise multiplication operation failed.";
        exit(0);
    }
    Matrix<T> res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] * a.mat[i][j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &a) {
    if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()) {
        cout << "Matrix size does not match! Plus operation failed.";
        exit(0);
    }
    Matrix<T> res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &a) {
    if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()) {
        cout << "Matrix size does not match! Subtraction operation failed.";
        exit(0);
    }
    Matrix<T> res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] - a.mat[i][j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &a) {
    if (mat[0].size() != a.mat.size()) {
        cout << "Matrix size does not match! Two matrix multiplication failed.";
        exit(0);
    }
    Matrix<T> res(row, a.col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < a.col; j++) {
            res.mat[i][j] = 0;
            for (int k = 0; k < col; k++) {
                res.mat[i][j] += mat[i][k] * a.mat[k][j];
            }
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator*(vector <T> vec) {
    if (mat[0].size() != 1) {
        cout << "This matrix cannot be multiplied with a vector.";
        exit(0);
    }
    Matrix<T> res(row, vec.size());
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            res.mat[i][j] = mat[i][0] * vec[j];
        }
    }
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T a) {
    Matrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] * a;
        }
    }
    return res;
}


template<class T>
Matrix<T> Matrix<T>::operator/(T a) {
    if (a == 0) {
        cout << "Divisor can not be zero! Division operation failed.";
        exit(0);
    }
    Matrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] / a;
        }
    }
    return res;
}


template<class T>
T Matrix<T>::findMax() {
    T max = INT32_MIN;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] > max) {
                max = mat[i][j];
            }
        }
    }
    return max;
}

template<class T>
T Matrix<T>::findMaxByRow(int rowNum) {
    if (rowNum > row) {
        cout << "Your input row number is too large";
        exit(0);
    }
    T max = INT32_MIN;
    for (int i = 0; i < mat[0].size(); i++) {
        if (mat[rowNum][i] > max) {
            max = mat[rowNum][i];
        }
    }
    return max;
}

template<class T>
T Matrix<T>::findMaxByCol(int colNum) {
    if (colNum > col) {
        cout << "Your input col number is too large";
        exit(0);
    }
    T max = INT32_MIN;
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i][colNum] > max) {
            max = mat[i][colNum];
        }
    }
    return max;
}

template<class T>
T Matrix<T>::findMin() {
    T min = INT32_MAX;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] < min) {
                min = mat[i][j];
            }
        }
    }
    return min;
}

template<class T>
T Matrix<T>::findMinByRow(int rowNum) {
    if (rowNum > row) {
        cout << "Your input row number is too large";
        exit(0);
    }
    T min = INT32_MAX;
    for (int i = 0; i < mat[0].size(); i++) {
        if (mat[rowNum][i] < min) {
            min = mat[rowNum][i];
        }
    }
    return min;
}

template<class T>
T Matrix<T>::findMinByCol(int colNum) {
    if (colNum > col) {
        cout << "Your input col number is too large";
        exit(0);
    }
    T min = INT32_MAX;
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i][colNum] < min) {
            min = mat[i][colNum];
        }
    }
    return min;
}

template<class T>
T Matrix<T>::getSum() {
    T sum = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            sum += mat[i][j];
        }
    }
    return sum;
}

template<class T>
T Matrix<T>::getSumByRow(int rowNum) {
    T sum = 0;
    for (int i = 0; i < mat[0].size(); i++) {
        sum += mat[rowNum][i];
    }
    return sum;
}


template<class T>
T Matrix<T>::getSumByCol(int colNum) {
    T sum = 0;
    for (int i = 0; i < mat.size(); i++) {
        sum += mat[i][colNum];
    }
    return sum;
}

template<class T>
T Matrix<T>::getAverage() {
    return Matrix::getSum() / (row * col);
}

template<class T>
T Matrix<T>::getAverageByRow(int rowNum) {
    return Matrix::getSumByRow(rowNum) / (row * col);
}

template<class T>
T Matrix<T>::getAverageByCol(int colNum) {
    return Matrix::getSumByCol(colNum) / (row * col);
}


template<class T>
T Matrix<T>::dotProduct(Matrix &other) {
    if (!this->isVector() || !other.isVector()) {
        cout << "The dot product requires two vectors! Dot product operation failed.";
        exit(0);
    }
    double res = 0;
    for (int j = 0; j < col; j++) {
        res += mat[0][j] + other.mat[0][j];
    }
    return res;
}

template<class T>
T Matrix<T>::crossProduct(Matrix &other) {
    if (!this->isVector() || !other.isVector()) {
        cout << "The cross product requires two vectors! Cross product operation failed.";
        exit(0);
    }

    return nullptr;
}

template<class T>
bool Matrix<T>::isVector() const {
    if (col == 1)return true;
    else return false;
}

template<class T>
T Matrix<T>::det() {
    Matrix tmp = Matrix(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            tmp.mat[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < row - 1; i++) {
        if (tmp.mat[i][i] != 0) {//对角线元素不为0
            if (mat[i][i] != 1.0)
                if (int j = tmp.Find(i, row)) { tmp.Swap(i, j, row); }
            for (int m = i + 1; m < row; m++) {
                if (tmp.mat[m][i] != 0) {
                    float temp = -(tmp.mat[m][i]) / tmp.mat[i][i];
                    for (int p = 0; p < row; p++) {//R(m)+tempRi
                        tmp.mat[m][p] = tmp.mat[m][p] + temp * mat[i][p];
                    }
                } else continue;
            }
        } else {//若对角线元素为0
            int m;
            for (m = i + 1; m < row; m++) {//
                if (tmp.mat[m][i]) {//使对角线元素非0
                    for (int p = 0; p < row; p++)//Ri+Rm
                        tmp.mat[i][p] = tmp.mat[m][p] + tmp.mat[i][p];
                    break;
                } else continue;
            }
            if (m == row) {
                return 0;
            }
            i--;
        }
    }

    float sum = tmp.mat[0][0];
    for (int i = 1; i < row; i++)
        sum = sum * tmp.mat[i][i];
    return sum;

}

template<class T>
int Matrix<T>::Find(int i, int row) {
    for (int m = i + 1; m < row; m++)
        if (mat[m][i] == 1.0)
            return m;
    return 0;
}

template<class T>
void Matrix<T>::Swap(int i, int j, int row) {
    for (int m = 0; m < row; m++) {
        mat[i][m] += mat[j][m];
        mat[j][m] = mat[i][m] - mat[j][m];
        mat[i][m] -= mat[j][m];
    }
}

template<class T>
Mat Matrix<T>::intoOpenCV() {
    Mat mat(Size(this->row, this->col), CV_64FC1);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            if (this->mat[i][j].imag() == 0)
                mat.at<double>(i, j) = this->mat[i][j];
            else cout << "The matrix has complex value and can't be transferred to OpenCV matrix! " << endl;
            exit(0);
        }
    }
    return mat;
}

#endif
