#include "GetRandomWord.h"

#include <string>
#include <vector>

// Функция для выбора случайного слова из вектора слов
int GetRandomWord(int words_sz) {
  srand(static_cast<unsigned int>(time(0)));
  int random_index = rand() % words_sz;
  return random_index;
}