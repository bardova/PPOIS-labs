/**
 * @file Matrix.cpp
 * @brief Реализация класса Matrix.
 */

#include "Matrix.h"
#include <cmath>
#include <iomanip>
#include <stdexcept>

void Matrix::allocate(int r, int c) {
    rows = r;
    cols = c;
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) data[i][j] = 0.0;
    }
}

void Matrix::deallocate() {
    if (data) {
        for (int i = 0; i < rows; ++i) delete[] data[i];
        delete[] data;
        data = nullptr;
    }
    rows = cols = 0;
}

Matrix::Matrix(int r, int c, double value) {
    if (r <= 0 || c <= 0) throw std::invalid_argument("Размеры должны быть > 0");
    allocate(r, c);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = value;
}

Matrix::Matrix(const Matrix& other) {
    allocate(other.rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
}

Matrix::~Matrix() { deallocate(); }

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    deallocate();
    allocate(other.rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    return *this;
}

double& Matrix::at(int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Индекс вне диапазона");
    return data[i][j];
}

double Matrix::at(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Индекс вне диапазона");
    return data[i][j];
}

void Matrix::resize(int newRows, int newCols) {
    if (newRows <= 0 || newCols <= 0)
        throw std::invalid_argument("Размеры должны быть > 0");

    double** newData = new double*[newRows];
    for (int i = 0; i < newRows; ++i) {
        newData[i] = new double[newCols];
        for (int j = 0; j < newCols; ++j) {
            if (i < rows && j < cols) newData[i][j] = data[i][j];
            else                       newData[i][j] = 0.0;
        }
    }
    deallocate();
    data = newData;
    rows = newRows;
    cols = newCols;
}

bool Matrix::loadFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) return false;
    int r, c;
    if (!(fin >> r >> c)) return false;
    if (r <= 0 || c <= 0) return false;

    Matrix temp(r, c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (!(fin >> temp.data[i][j])) return false;

    *this = temp;
    return true;
}

Matrix Matrix::submatrix(int rowStart, int colStart,
                         int subRows, int subCols) const {
    if (rowStart < 0 || colStart < 0 ||
        rowStart + subRows > rows || colStart + subCols > cols ||
        subRows <= 0 || subCols <= 0)
        throw std::out_of_range("Некорректные границы подматрицы");

    Matrix result(subRows, subCols);
    for (int i = 0; i < subRows; ++i)
        for (int j = 0; j < subCols; ++j)
            result.data[i][j] = data[rowStart + i][colStart + j];
    return result;
}

static bool almostEqual(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

bool Matrix::isSquare() const { return rows == cols; }

bool Matrix::isZero() const {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (!almostEqual(data[i][j], 0.0)) return false;
    return true;
}

bool Matrix::isDiagonal() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (i != j && !almostEqual(data[i][j], 0.0)) return false;
    return true;
}

bool Matrix::isIdentity() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (i == j && !almostEqual(data[i][j], 1.0)) return false;
            if (i != j && !almostEqual(data[i][j], 0.0)) return false;
        }
    return true;
}

bool Matrix::isSymmetric() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; ++i)
        for (int j = i + 1; j < cols; ++j)
            if (!almostEqual(data[i][j], data[j][i])) return false;
    return true;
}

bool Matrix::isUpperTriangular() const {
    if (!isSquare()) return false;
    for (int i = 1; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (!almostEqual(data[i][j], 0.0)) return false;
    return true;
}

bool Matrix::isLowerTriangular() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rows; ++i)
        for (int j = i + 1; j < cols; ++j)
            if (!almostEqual(data[i][j], 0.0)) return false;
    return true;
}

Matrix Matrix::transposed() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];
    return result;
}

void Matrix::transpose() {
    *this = transposed();
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) return false;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (!almostEqual(data[i][j], other.data[i][j])) return false;
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& is, Matrix& m) {
    int r, c;
    std::cout << "Введите число строк и столбцов: ";
    is >> r >> c;
    if (r <= 0 || c <= 0) {
        is.setstate(std::ios::failbit);
        return is;
    }
    Matrix temp(r, c);
    std::cout << "Введите " << r * c << " элементов:\n";
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            is >> temp.data[i][j];
    if (is) m = temp;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    os << "Матрица " << m.rows << "x" << m.cols << ":\n";
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j)
            os << std::setw(10) << std::setprecision(4) << m.data[i][j] << ' ';
        os << '\n';
    }
    return os;
}
