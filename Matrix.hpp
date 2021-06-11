//
// Created by ccyys on 2021/5/22.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

template <class T>
class Matrix
{
public:
    void setValue(vector<vector<T>>);
    void setValueWithSparse(vector<vector<T>>);

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

    Matrix operator/(T a);

    Matrix operator*(T a);

    Matrix transposition();

    Matrix conjugation();

    T dotProduct(Matrix &other);

    vector<T> crossProduct(Matrix &other);

    bool isVector() const;

    T det(Matrix &a);

    Mat eigenValue();

    Mat eigenVector();

    Mat intoOpenCV();

    Matrix convolution(Matrix &a);

    Matrix inverse();

    T trace();

    int find(int i, int row);

    void swap(int i, int j, int row);

    friend Matrix<T> operator*(T a, const Matrix &other)
    {
        Matrix res(other.row, other.col);
        for (int i = 0; i < other.row; i++)
        {
            for (int j = 0; j < other.col; j++)
            {
                res.mat[i][j] = other.mat[i][j] * a;
            }
        }
        return res;
    };

    //friend function must be write inside the class
    friend Matrix<T> operator*(vector<T> vec, Matrix &a)
    {
        if (vec.size() != a.mat.size())
        {
            cout << "This vector cannot be multiplied with a matrix.";
            exit(0);
        }
        Matrix<T> res(1, a.mat[0].size());
        for (int i = 0; i < a.mat[0].size(); i++)
        {
            res.mat[0][i] = 0;
            for (int j = 0; j < a.mat.size(); j++)
            {
                res.mat[0][i] += vec[j] * a.mat[j][i];
            }
        }
        return res;
    }

    vector<vector<T>> mat;
    int row{};
    int col{};

    Matrix(int row, int col);
};
    template <class T>
    Matrix<T> Matrix<T>::conjugation()
    {
        Matrix res(col, row);
        res = this->transposition();
        if (typeid(T) == typeid(complex<double>))
        {
            for (int j = 0; j < col; j++)
            {
                for (int i = 0; i < row; i++)
                {
                    res.mat[j][i] = conj(res.mat[j][i]);
                }
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::transposition()
    {
        Matrix res(col, row);
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                res.mat[i][j] = mat[j][i];
            }
        }
        return res;
    }

    template <class T>
    Matrix<T>::Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        vector<T> temp(col);
        this->mat.resize(row, temp);
    }

    template <class T>
    void Matrix<T>::setValue(vector<vector<T>> valueMat)
    {
        if (valueMat.size() != mat.size() || valueMat[0].size() != mat[0].size())
        {
            cout << "The input value's size does not match the matrix!";
            exit(0);
        }
        for (int i = 0; i < valueMat.size(); i++)
        {
            for (int j = 0; j < valueMat[0].size(); j++)
            {
                mat[i][j] = valueMat[i][j];
            }
        }
    }

template <class T>
void Matrix<T>::setValueWithSparse(vector<vector<T>> valueMat)
{
    for(vector<T> value: valueMat){
        if(value.size()!= 3 || value[0] < 0 || value[0] >= row || value[1] < 0 || value[1] >= col){
            cout << "The input coordinate is not in proper range.";
            exit(0);
        }else{
            mat[value[0],value[1]] = value[2];
        }
    }
}



template <class T>
    void Matrix<T>::showMatrix()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    template <class T>
    Matrix<T> Matrix<T>::elementWiseMultiple(Matrix<T> &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            cout << "Matrix size does not match! Element wise multiplication operation failed.";
            exit(0);
        }
        Matrix<T> res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] * a.mat[i][j];
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::operator+(Matrix<T> &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            cout << "Matrix size does not match! Plus operation failed.";
            exit(0);
        }
        Matrix<T> res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] + a.mat[i][j];
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::operator-(Matrix<T> &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            cout << "Matrix size does not match! Subtraction operation failed.";
            exit(0);
        }
        Matrix<T> res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] - a.mat[i][j];
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::operator*(Matrix<T> &a)
    {
        if (mat[0].size() != a.mat.size())
        {
            cout << "Matrix size does not match! Two matrix multiplication failed.";
            exit(0);
        }
        Matrix<T> res(row, a.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < a.col; j++)
            {
                res.mat[i][j] = 0;
                for (int k = 0; k < col; k++)
                {
                    res.mat[i][j] += mat[i][k] * a.mat[k][j];
                }
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::operator*(vector<T> vec)
    {
        if (mat[0].size() != 1)
        {
            cout << "This matrix cannot be multiplied with a vector.";
            exit(0);
        }
        Matrix<T> res(row, vec.size());
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                res.mat[i][j] = mat[i][0] * vec[j];
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::operator*(T a)
    {
        Matrix res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] * a;
            }
        }
        return res;
    }

    template <class T>
    Matrix<T> Matrix<T>::operator/(T a)
    {
        if (a == complex<double>(0, 0))
        {
            cout << "Divisor can not be zero! Division operation failed.";
            exit(0);
        }
        Matrix res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.mat[i][j] = mat[i][j] / a;
            }
        }
        return res;
    }

    template <class T>
    T Matrix<T>::findMax()
    {
        if (typeid(T) == typeid(complex<double>))
        {
            cout << "complex can not compare";
            exit(0);
        }
        T max = INT32_MIN;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] > max)
                {
                    max = mat[i][j];
                }
            }
        }
        return max;
    }

    template <class T>
    T Matrix<T>::findMaxByRow(int rowNum)
    {
        if (typeid(T) == typeid(complex<double>))
        {
            cout << "complex can not compare";
            exit(0);
        }
        if (rowNum > row)
        {
            cout << "Your input row number is too large";
            exit(0);
        }
        T max = INT32_MIN;
        for (int i = 0; i < mat[0].size(); i++)
        {
            if (mat[rowNum][i] > max)
            {
                max = mat[rowNum][i];
            }
        }
        return max;
    }

    template <class T>
    T Matrix<T>::findMaxByCol(int colNum)
    {
        if (typeid(T) == typeid(complex<double>))
        {
            cout << "complex can not compare";
            exit(0);
        }
        if (colNum > col)
        {
            cout << "Your input col number is too large";
            exit(0);
        }
        T max = INT32_MIN;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][colNum] > max)
            {
                max = mat[i][colNum];
            }
        }
        return max;
    }

    template <class T>
    T Matrix<T>::findMin()
    {
        if (typeid(T) == typeid(complex<double>))
        {
            cout << "complex can not compare";
            exit(0);
        }
        T min = INT32_MAX;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] < min)
                {
                    min = mat[i][j];
                }
            }
        }
        return min;
    }

    template <class T>
    T Matrix<T>::findMinByRow(int rowNum)
    {
        if (typeid(T) == typeid(complex<double>))
        {
            cout << "complex can not compare";
            exit(0);
        }
        if (rowNum > row)
        {
            cout << "Your input row number is too large";
            exit(0);
        }
        T min = INT32_MAX;
        for (int i = 0; i < mat[0].size(); i++)
        {
            if (mat[rowNum][i] < min)
            {
                min = mat[rowNum][i];
            }
        }
        return min;
    }

    template <class T>
    T Matrix<T>::findMinByCol(int colNum)
    {
        if (typeid(T) == typeid(complex<double>))
        {
            cout << "complex can not compare";
            exit(0);
        }
        if (colNum > col)
        {
            cout << "Your input col number is too large";
            exit(0);
        }
        T min = INT32_MAX;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][colNum] < min)
            {
                min = mat[i][colNum];
            }
        }
        return min;
    }

    template <class T>
    T Matrix<T>::getSum()
    {
        T sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                sum += mat[i][j];
            }
        }
        return sum;
    }

    template <class T>
    T Matrix<T>::getSumByRow(int rowNum)
    {
        T sum = 0;
        for (int i = 0; i < mat[0].size(); i++)
        {
            sum += mat[rowNum][i];
        }
        return sum;
    }

    template <class T>
    T Matrix<T>::getSumByCol(int colNum)
    {
        T sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            sum += mat[i][colNum];
        }
        return sum;
    }

    template <class T>
    T Matrix<T>::getAverage()
    {
        return Matrix::getSum() / T(row * col);
    }

    template <class T>
    T Matrix<T>::getAverageByRow(int rowNum)
    {
        return Matrix::getSumByRow(rowNum) / T(row * col);
    }

    template <class T>
    T Matrix<T>::getAverageByCol(int colNum)
    {
        return Matrix::getSumByCol(colNum) / T(row * col);
    }

    template <class T>
    T Matrix<T>::dotProduct(Matrix &other)
    {
        if (!this->isVector() || !other.isVector())
        {
            cout << "The dot product requires two vectors! Dot product operation failed.";
            exit(0);
        }
        double res = 0;
        for (int j = 0; j < col; j++)
        {
            res += mat[0][j] + other.mat[0][j];
        }
        return res;
    }

    template <class T>
    vector<T> Matrix<T>::crossProduct(Matrix &other)
    {
        vector<T> vec(3);
        if (!this->isVector() || !other.isVector())
        {
            cout << "The cross product requires two vectors! Cross product operation failed.";
            exit(0);
        }else{
            if(row == 3 && other.row==3){
                vec[0] = mat[1][0] * ohter.mat[2][0] - mat[2][0] * ohter.mat[1][0]
                vec[0] = mat[0][0] * ohter.mat[2][0] - mat[2][0] * ohter.mat[0][0]
                vec[0] = mat[0][0] * ohter.mat[1][0] - mat[1][0] * ohter.mat[0][0]

            }
        }

        return vec;
    }

    template <class T>
    bool Matrix<T>::isVector() const
    {
        if (col == 1)
            return true;
        else
            return false;
    }

    template <class T>
    T det(Matrix<T> &a)
    {
        if (a.mat.size() == 1)
        {
            return a.mat.front().front();
        }
        uint32_t size_m = a.mat.size();
        Matrix<T> submatrix(a.row, a.col);
        submatrix.mat = vector<vector<T>>(size_m - 1, vector<T>(size_m - 1, static_cast<T>(0)));
        T will_return(0);
        for (uint32_t i = 0; i < size_m; ++i)
        {
            for (uint32_t j = 0; j < size_m - 1; ++j)
            {
                for (uint32_t k = 0; k < size_m - 1; ++k)
                {
                    submatrix.mat[j][k] = a.mat[(((i > j) ? 0 : 1) + j)][k + 1];
                }
            }
            will_return += ((i % 2) ? -1 : 1) * a.mat[i].front() * det(submatrix);
        }
        return will_return;
    }

    template <class T>
    int Matrix<T>::find(int i, int row)
    {
        for (int m = i + 1; m < row; m++)
            if (mat[m][i] == 1.0)
                return m;
        return 0;
    }

    template <class T>
    void Matrix<T>::swap(int i, int j, int row)
    {
        for (int m = 0; m < row; m++)
        {
            mat[i][m] += mat[j][m];
            mat[j][m] = mat[i][m] - mat[j][m];
            mat[i][m] -= mat[j][m];
        }
    }

    template <class T>
    Matrix<T> Matrix<T>::convolution(Matrix &kernel)
    {
        T temp;
        Matrix<T> result(row, col);
        int kLength = kernel.col;
        int kWidth = kernel.row;

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                temp = 0;
                for (int m = 0; m < kLength; m++)
                {
                    for (int n = 0; n < kWidth; n++)
                    {
                        if ((i - m) >= 0 && (i - m) < col && (j - n) >= 0 && (j - n) < row)
                        {
                            temp += kernel.mat[m][n] * this->mat[i - m][j - n];
                        }
                    }
                }
                result.mat[i][j] = temp;
            }
        }
        return result;
    }

    template <class T>
    Matrix<T> inverse(Matrix<T> &a)
    {
        //可逆条件
        if (a.row == a.col && a.row > 1 && det(a) != 0)
        {
            static constexpr T zeroNumber{0};
            static constexpr T oneElement{1};
            std::vector<std::vector<T>> result_vector(a.row, std::vector<T>(a.col, zeroNumber));
            for (int32_t i = 0; i < a.row; i++)
            {
                for (int32_t j = 0; j < a.col; j++)
                {
                    //vector<vector<T>> submatrix(this->rows() - 1, vector<T>(this->cols() - 1, static_cast<T>(0)));
                    Matrix<T> submatrix(a.row, a.col);
                    submatrix.setValue(vector<vector<T>>(a.mat));
                    submatrix.mat.erase(submatrix.mat.begin() + i);
                    for (int m = 0; m < a.row - 1; ++m)
                    {
                        submatrix.mat[m].erase(submatrix.mat[m].begin() + j);
                    }
                    result_vector[j][i] =
                        (((i + j) % 2) ? -1 : 1) * det(submatrix); //子矩阵展开得到伴随矩阵
                }
            }
            Matrix<T> will_return(a.row, a.col);
            will_return.setValue(result_vector);
            will_return = will_return / det(a);
            //will_return[i][j] = res[i][j] / this->determinant();//逆
            return will_return;
        }
        return Matrix<T>(0, 0);
    }

    template <class T>
    Mat Matrix<T>::intoOpenCV()
    {
        Mat mat(Size(this->row, this->col), CV_64F);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (typeid(T) != typeid(complex<double>))
                    mat.at<double>(i, j) = this->mat[i][j];
                else
                {
                    cout << "The matrix has complex value and can't be transferred to OpenCV matrix! " << endl;
                    exit(0);
                }
            }
        }
        return mat;
    }
    template <class T>
    T Matrix<T>::trace()
    {
        if (row != col)
        {
            cout << "only a matrix with row equal to col has a trace.";
            exit(0);
        }
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += mat[i][i];
        }
        return sum;
    }

    template <class T>
    Mat Matrix<T>::eigenValue()
    {
        Mat eValuesMat;
        Mat eVectorsMat;
        Mat myMat = this->intoOpenCV();
        eigen(myMat, eValuesMat, eVectorsMat);
        return eValuesMat;
    }

    template <class T>
    Mat Matrix<T>::eigenVector()
    {
        Mat eValuesMat;
        Mat eVectorsMat;
        Mat myMat = this->intoOpenCV();
        eigen(myMat, eValuesMat, eVectorsMat);
        return eVectorsMat;
    }
template <class T>
Matrix<T> Matrix<T>::reshape(int newRow, int newCol) {
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
        vector<T> newRows(newCol);
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
#endif
