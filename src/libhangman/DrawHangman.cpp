#include "DrawHangman.h"

#include <iostream>

// Функция для отображения виселицы и человека в зависимости от количества
// ошибочных попыток
void DrawHangman(int incorrect_guesses) {
  std::cout << "  +---+" << std::endl;
  std::cout << "  |   |" << std::endl;
  std::cout << "  " << (incorrect_guesses >= 1 ? "|   O" : "|") << std::endl;
  std::cout << "  "
            << (incorrect_guesses >= 4
                    ? "|  /|\\"
                    : (incorrect_guesses >= 3
                           ? "|  /|"
                           : (incorrect_guesses >= 2 ? "|   |" : "|")))
            << std::endl;
  std::cout << "  "
            << (incorrect_guesses >= 6
                    ? "|  / \\"
                    : (incorrect_guesses >= 5 ? "|  / " : "|"))
            << std::endl;
  std::cout << "  |" << std::endl;
  std::cout << "=====" << std::endl;
}