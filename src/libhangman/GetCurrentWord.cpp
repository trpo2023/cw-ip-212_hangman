#include "GetCurrentWord.h"

#include <ctime>
#include <string>
#include <vector>

// Функция для отображения текущего состояния слова с учетом угаданных букв
std::string GetCurrentWord(std::string secret_word,
                           const std::vector<bool>& guessed_letters) {
  std::string current_word = secret_word;
  for (long unsigned int i = 0; i < secret_word.length(); ++i) {
    if (!guessed_letters[i]) {
      current_word[i] = '-';
    }
  }
  return current_word;
}