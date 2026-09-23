/**
 * @file main.cpp
 * @brief Точка входа в программу "Крестики-нолики".
 */

#include "TTT.h"
#include <iostream>
#include <string>

/**
 * @brief Главная функция.
 * @return код завершения (0 — успех)
 */
int main() {
    setlocale(LC_ALL, "RU");
    TTT game;
    game.game();
    return 0;
}
