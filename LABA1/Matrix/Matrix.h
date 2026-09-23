/**
 * @file Matrix.h
 * @brief Объявление класса вещественной матрицы Matrix.
 * @author Student
 * @date 2024
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Класс вещественной матрицы.
 *
 * Поддерживает создание, копирование, изменение размеров,
 * загрузку из файла, извлечение подматрицы, проверку типа,
 * транспонирование, а также ввод/вывод через потоки.
 */
class Matrix {
private:
    double** data;   ///< Двумерный массив элементов
    int rows;        ///< Число строк
    int cols;        ///< Число столбцов

    /**
     * @brief Выделение памяти под матрицу.
     * @param r число строк
     * @param c число столбцов
     */
    void allocate(int r, int c);

    /**
     * @brief Освобождение памяти.
     */
    void deallocate();

public:
    /**
     * @brief Конструктор по умолчанию.
     * @param r число строк (по умолчанию 1)
     * @param c число столбцов (по умолчанию 1)
     * @param value значение всех элементов
     */
    explicit Matrix(int r = 1, int c = 1, double value = 0.0);

    /**
     * @brief Конструктор копирования.
     * @param other копируемая матрица
     */
    Matrix(const Matrix& other);

    /**
     * @brief Деструктор.
     */
    ~Matrix();

    /**
     * @brief Оператор присваивания.
     * @param other присваиваемая матрица
     * @return ссылка на текущий объект
     */
    Matrix& operator=(const Matrix& other);

    // ---- Геттеры ----
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    /**
     * @brief Доступ к элементу (чтение/запись).
     */
    double& at(int i, int j);
    double  at(int i, int j) const;

    // ---- Операции ----

    /**
     * @brief Изменение размера матрицы.
     * @param newRows новое число строк
     * @param newCols новое число столбцов
     */
    void resize(int newRows, int newCols);

    /**
     * @brief Загрузка матрицы из файла.
     * @param filename имя файла
     * @return true при успехе
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Извлечение подматрицы.
     * @param rowStart начальная строка
     * @param colStart начальный столбец
     * @param subRows число строк
     * @param subCols число столбцов
     * @return новая матрица
     */
    Matrix submatrix(int rowStart, int colStart,
                     int subRows, int subCols) const;

    // ---- Проверка типа ----
    bool isSquare()         const; ///< Квадратная
    bool isDiagonal()       const; ///< Диагональная
    bool isZero()           const; ///< Нулевая
    bool isIdentity()       const; ///< Единичная
    bool isSymmetric()      const; ///< Симметрическая
    bool isUpperTriangular()const; ///< Верхняя треугольная
    bool isLowerTriangular()const; ///< Нижняя треугольная

    /**
     * @brief Транспонирование (возвращает новую матрицу).
     */
    Matrix transposed() const;

    /**
     * @brief Транспонирование на месте.
     */
    void transpose();

    // ---- Операторы сравнения ----
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    // ---- Потоки ----
    /**
     * @brief Ввод матрицы из потока.
     * Формат: сначала rows и cols, затем rows*cols чисел.
     */
    friend std::istream& operator>>(std::istream& is, Matrix& m);

    /**
     * @brief Вывод матрицы в поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

#endif // MATRIX_H
