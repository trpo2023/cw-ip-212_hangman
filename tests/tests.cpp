#include <stdlib.h>

#include <string>
#include <vector>

#include "GetCurrentWord.h"
#include "GetRandomWord.h"
#include "ctest.h"

// Проверка на возможность успешного запуска программы
CTEST(program, run) {
  const char *program_name = "./main_executable -ctest";
  int result = system(program_name);
  ASSERT_TRUE(!result);
}

// Тест на правильную генерацию числа для выбора случайного слова
CTEST(function, RandomWord) {
  int right_number = 0;
  int generated_number = GetRandomWord(10);
  if (generated_number >= 0 && generated_number <= 10) {
    right_number = 1;
  }
  ASSERT_TRUE(right_number);
}

// Тесты на показ верного результата выбранного символа ниже
CTEST(function, CurrentWordOneChar) {
  std::string word = "apple";
  std::string expected_result = "---l-";
  std::vector<bool> guessed_letters(5, false);
  guessed_letters[3] = true;

  std::string real_result = GetCurrentWord(word, guessed_letters);

  int lines_the_same = 0;
  if (real_result == expected_result) {
    lines_the_same = 1;
  }
  ASSERT_TRUE(lines_the_same);
}

CTEST(function, CurrentWordMultipleChar) {
  std::string word = "apple";
  std::string expected_result = "-pp--";
  std::vector<bool> guessed_letters(5, false);
  guessed_letters[1] = true;
  guessed_letters[2] = true;

  std::string real_result = GetCurrentWord(word, guessed_letters);

  int lines_the_same = 0;
  if (real_result == expected_result) {
    lines_the_same = 1;
  }
  ASSERT_TRUE(lines_the_same);
}

CTEST(function, CurrentWordNoOneGuessed) {
  std::string word = "watermellon";
  std::string expected_result = "-----------";
  std::vector<bool> guessed_letters(12, false);

  std::string real_result = GetCurrentWord(word, guessed_letters);

  int lines_the_same = 0;
  if (real_result == expected_result) {
    lines_the_same = 1;
  }
  ASSERT_TRUE(lines_the_same);
}

CTEST(function, CurrentWordAllGuessed) {
  std::string word = "strawberry";
  std::string expected_result = "strawberry";
  std::vector<bool> guessed_letters(12, true);

  std::string real_result = GetCurrentWord(word, guessed_letters);

  int lines_the_same = 0;
  if (real_result == expected_result) {
    lines_the_same = 1;
  }
  ASSERT_TRUE(lines_the_same);
}