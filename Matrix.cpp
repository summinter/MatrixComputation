#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
    vector<double> temp(col);
    this->mat.resize(row, temp);
}

void Matrix::setValue(vector<vector<double>> valueMat) {
    if (valueMat.size() != mat.size() || valueMat[0].size() != mat[0].size()) {
        cout << "The input value's size does not match the matrix!" << endl;
        exit(0);
    }
    for (int i = 0; i < valueMat.size(); i++) {
        for (int j = 0; j < valueMat[0].size(); j++) {
            mat[i][j] = valueMat[i][j];
        }
    }
}

void Matrix::showMatrix() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(Matrix &a) {
    if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size()) {
        cout << "Matrix size does not match! Plus operation failed." << endl;
        exit(0);
    }
    Matrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(Matrix &a) {
    return Matrix(0, 0);
}

Matrix Matrix::operator/(double a) {
    if (a == 0) {
        cout << "Divisor can not be zero! Division operation failed." << endl;
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

Matrix Matrix::operator*(double a) {
    Matrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mat[i][j] = mat[i][j] * a;
        }
    }
    return res;
}

Matrix operator*(double a, const Matrix &other) {
    Matrix res(other.row, other.col);
    for (int i = 0; i < other.row; i++) {
        for (int j = 0; j < other.col; j++) {
            res.mat[i][j] = other.mat[i][j] * a;
        }
    }
    return res;
}

Matrix Matrix::transposition() {
    Matrix res(col, row);
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            res.mat[i][j] = mat[j][i];
        }
    }
    return res;
}

Matrix Matrix::conjugation() {
    return this->transposition();
//    TO DO
}

double Matrix::dotProduct(Matrix &other) {
    if (!this->isVector() || !other.isVector()) {
        cout << "The dot product requires two vectors! Dot product operation failed." << endl;
        exit(0);
    } else if (this->row != other.row) {
        cout << "The dot product requires two vectors with the same dimensions! Dot product operation failed." << endl;
        exit(0);
    }
    double res = 0;
    for (int j = 0; j < col; j++) {
        res += mat[0][j] * other.mat[0][j];
    }
    return res;
}

bool Matrix::isVector() const {
    if (col == 1)return true;
    else return false;
}

Matrix Matrix::crossProduct(Matrix &other) {
    if (!this->isVector() || !other.isVector()) {
        cout << "The cross product requires two vectors! Cross product operation failed." << endl;
        exit(0);
    } else if (this->row != 3 || other.row != 3) {
        cout << "The dot product requires two vectors with the 3 dimensions! Dot product operation failed." << endl;
        exit(0);
    }
    Matrix res(row, 1);
    res.mat[0][0] = mat[0][1] * other.mat[0][2] - mat[0][2] * other.mat[0][1];
    res.mat[0][1] = mat[0][3] * other.mat[0][0] - mat[0][0] * other.mat[0][3];
    res.mat[0][2] = mat[0][0] * other.mat[0][1] - mat[0][1] * other.mat[0][0];
    return res;
}

double Matrix::det() {
    if (row != col) {
        cout
                << "The determinant calculation requires a matrix with the equal rows and coloumns! Determinant calculation operation failed."
                << endl;
        exit(0);
    }
    Matrix tmp = Matrix(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            tmp.mat[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < row - 1; i++) {
        if (tmp.mat[i][i] != 0) {
            if (mat[i][i] != 1.0)
                if (int j = tmp.Find(i, row)) { tmp.Swap(i, j, row); }
            for (int m = i + 1; m < row; m++) {
                if (tmp.mat[m][i] != 0) {
                    float temp = -(tmp.mat[m][i]) / tmp.mat[i][i];
                    for (int p = 0; p < row; p++) {
                        tmp.mat[m][p] = tmp.mat[m][p] + temp * mat[i][p];
                    }
                } else continue;
            }
        } else {
            int m;
            for (m = i + 1; m < row; m++) {
                if (tmp.mat[m][i]) {
                    for (int p = 0; p < row; p++)
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

int Matrix::Find(int i, int row) {
    for (int m = i + 1; m < row; m++)
        if (mat[m][i] == 1.0)
            return m;
    return 0;
}

void Matrix::Swap(int i, int j, int row) {
    for (int m = 0; m < row; m++) {
        mat[i][m] += mat[j][m];
        mat[j][m] = mat[i][m] - mat[j][m];
        mat[i][m] -= mat[j][m];
    }
}

//void Matrix::setValue(SparseValue values[]) {
//    for (int i = 0; sizeof(values) / sizeof(int) > i; i++) {
//        mat[values[i].rowIndex][values[i].colIndex] = values[i].value;
//    }
//}

Matrix Matrix::reshape(int newRow, int newCol) {
    Matrix res(min(this->row, newRow), min(this->col, newCol));
    for (int i = 0; i < res.row; i++) {
        for (int j = 0; j < res.col; j++) {
            res.mat[i][j] = mat[i][j];
        }
    }
    if (this->row > newRow) {
        if (this->col < newCol) {
            for (int i = 0; i < res.row; i++) {
                res.mat[i].insert(res.mat[i].end(), newCol - this->col, 0);
            }
            res.col = newCol;
        }
    } else if (this->row < newRow) {
        vector<double> newRows(newCol);
        res.mat.insert(res.mat.end(), newRow - this->row, newRows);
        res.row = newRow;
        if (this->col < newCol) {
            for (int i = 0; i < res.row; i++) {
                res.mat[i].insert(res.mat[i].end(), newCol - this->col, 0);
            }
            res.col = newCol;
        }
    }
    return res;
}

SparseValue::SparseValue(int rowIndex, int colIndex, double value) {
    this->colIndex = colIndex;
    this->rowIndex = rowIndex;
    this->value = value;
}
