/**
 * @file TTT.cpp
 * @brief Реализация класса TTT.
 */

#include "TTT.h"
#include <iostream>
#include <string>
#include <limits>

void TTT::game() {
    // Очистка поля
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = ' ';
        }
    }

    std::cout << "Введите имя игрока А: ";
    std::cin >> playerA;
    std::cout << "Введите имя игрока B: ";
    std::cin >> playerB;

    std::cout << *this;
    bool gameOver = false;
    char choice = 'O';
    while (!gameOver) {
        if (choice == 'O') {
            std::cout << playerA << " делает ход\n";
        } else {
            std::cout << playerB << " делает ход\n";
        }

        int x, y;
          chp(&x, &y);
            
            while (field[x][y] != ' ') {
                std::cout << "Эта ячейка уже занята! Выберите другую: ";
                chp(&x, &y);
            }

        field[x][y] = choice;
        std::cout << *this;
    if (win(field)) {
                std::cout << *this;
                if (choice == 'X') {
                    std::cout << "Выиграл " << playerB << "!\n";
                }
                else {
                    std::cout << "Выиграл " << playerA << "!\n";
                }
                gameOver = true;
            }
            else if ( isDraw(field)) {
                std::cout << *this << "Ничья!\n";
                gameOver = true;
            }
            else {
                // Смена игрока
                choice = (choice == 'O') ? 'X' : 'O';
            }
        }
}

void TTT::chp(int* x, int* y) {
    do {
        std::cout << "Выберите ячейку: \n";
        scanf("%d %d", x, y);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (*x >= 3 || *y >= 3 || *x < 0 || *y < 0);
}

std::ostream& operator<<(std::ostream& os, TTT& t){
for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            os << "[" << t.field[i][k] << "]";
        }
        os << "\n";
    }
    return os;
}

bool TTT::win(char field[3][3]) {
    // Проверка столбцов
    for (int i = 0; i < 3; i++) {
        if (field[0][i] == field[1][i] &&
            field[1][i] == field[2][i] &&
            field[0][i] != ' ') {
            return true;
        }
    }

    // Проверка строк
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1] &&
            field[i][1] == field[i][2] &&
            field[i][0] != ' ') {
            return true;
        }
    }

    // Главная диагональ
    if (field[0][0] == field[1][1] &&
        field[1][1] == field[2][2] &&
        field[0][0] != ' ') {
        return true;
    }

    // Побочная диагональ
    if (field[0][2] == field[1][1] &&
        field[1][1] == field[2][0] &&
        field[0][2] != ' ') {
        return true;
    }

    return false;
}

 bool TTT::isDraw(char field[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (field[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
