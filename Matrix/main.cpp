/**
 * @file main.cpp
 * @brief Тестовая программа с меню для класса Matrix.
 */

#include "Matrix.h"
#include <iostream>
#include <limits>

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void printTypes(const Matrix& m) {
    std::cout << "Квадратная:        " << (m.isSquare() ? "да" : "нет") << '\n';
    std::cout << "Нулевая:           " << (m.isZero() ? "да" : "нет") << '\n';
    std::cout << "Диагональная:      " << (m.isDiagonal() ? "да" : "нет") << '\n';
    std::cout << "Единичная:         " << (m.isIdentity() ? "да" : "нет") << '\n';
    std::cout << "Симметрическая:    " << (m.isSymmetric() ? "да" : "нет") << '\n';
    std::cout << "Верх. треугольная: " << (m.isUpperTriangular() ? "да" : "нет") << '\n';
    std::cout << "Ниж. треугольная:  " << (m.isLowerTriangular() ? "да" : "нет") << '\n';
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Matrix m;
    int choice = -1;

    do {
        std::cout << "\n=========== МЕНЮ ===========\n"
                  << "1. Ввести матрицу вручную\n"
                  << "2. Загрузить матрицу из файла\n"
                  << "3. Вывести матрицу\n"
                  << "4. Изменить размер\n"
                  << "5. Извлечь подматрицу\n"
                  << "6. Проверить тип матрицы\n"
                  << "7. Транспонировать (на месте)\n"
                  << "8. Получить транспонированную (новая)\n"
                  << "9. Сравнить с другой матрицей\n"
                  << "0. Выход\n"
                  << "Выбор: ";
        std::cin >> choice;
        if (!std::cin) { clearInput(); continue; }

        switch (choice) {
        case 1: {
            std::cin >> m;
            if (!std::cin) { std::cout << "Ошибка ввода!\n"; clearInput(); }
            break;
        }
        case 2: {
            std::string fn;
            std::cout << "Имя файла: ";
            std::cin >> fn;
            if (m.loadFromFile(fn)) std::cout << "Загружено успешно.\n";
            else                    std::cout << "Не удалось загрузить.\n";
            break;
        }
        case 3:
            std::cout << m;
            break;
        case 4: {
            int r, c;
            std::cout << "Новые строки и столбцы: ";
            std::cin >> r >> c;
            try { m.resize(r, c); std::cout << "Готово.\n"; }
            catch (const std::exception& e) { std::cout << "Ошибка: " << e.what() << '\n'; }
            break;
        }
        case 5: {
            int rs, cs, rr, cc;
            std::cout << "rowStart colStart subRows subCols: ";
            std::cin >> rs >> cs >> rr >> cc;
            try { std::cout << m.submatrix(rs, cs, rr, cc); }
            catch (const std::exception& e) { std::cout << "Ошибка: " << e.what() << '\n'; }
            break;
        }
        case 6:
            printTypes(m);
            break;
        case 7:
            m.transpose();
            std::cout << "Транспонировано.\n" << m;
            break;
        case 8:
            std::cout << m.transposed();
            break;
        case 9: {
            std::cout << "Введите вторую матрицу:\n";
            Matrix other;
            std::cin >> other;
            if (!std::cin) { std::cout << "Ошибка ввода!\n"; clearInput(); break; }
            std::cout << "Равны: " << ((m == other) ? "да" : "нет") << '\n';
            break;
        }
        case 0:
            std::cout << "Выход.\n";
            break;
        default:
            std::cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}
