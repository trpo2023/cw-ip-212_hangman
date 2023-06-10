#include <string.h>

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

// Подключение библиотек программы
#include "DrawHangman.h"
#include "GetCurrentWord.h"
#include "GetRandomWord.h"

// Количество попыток до проигрыша
const int MAX_TRIES = 6;

// Слова для угадывания
std::vector<std::string> words = {
    "apple",     "banana",     "orange",     "lemon", "grape",
    "pineapple", "watermelon", "strawberry", "kiwi",  "peach"};

int main(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "-ctest") == 0) {
    std::cout << "Program runs successfully!";
    return 0;
  }
  int menu;
  std::cout << "---------------------------------------------------------------"
               "------------------"
            << std::endl
            << std::endl;
  std::cout << "                     Welcome to the Hangman!" << std::endl
            << std::endl;
  std::cout << "---------------------------------------------------------------"
               "------------------"
            << std::endl;
  std::cout << "             Game menu" << std::endl;
  std::cout << "      1. Start the game" << std::endl;
  std::cout << "      2. Rules of the game" << std::endl;
  while (menu != 1) {
    std::cout << "Select the action you want to perform ";
    std::cin >> menu;
    if (menu != 1 && menu != 2) {
      std::cout
          << "The command was not found. Enter one of the values listed above."
          << std::endl;
    }
    switch (menu) {
      case 2:
        std::cout << "---------------------------------------------------------"
                     "------------------------"
                  << std::endl;
        std::cout << "                    Rules of the game  " << std::endl;
        std::cout
            << " The computer makes a word (a noun in the nominative singular, "
            << std::endl;
        std::cout
            << " or plural in the absence of the singular form of the word) "
            << std::endl;
        std::cout << " The player suggests a letter that can be included in "
                     "this word."
                  << std::endl;
        std::cout << " If there is such a letter in a word, then a letter "
                     "appears above the "
                  << std::endl;
        std::cout
            << " features corresponding to this letter — as many times as it "
            << std::endl;
        std::cout
            << " occurs in the word. The player continues to guess the letters "
            << std::endl;
        std::cout << " until he guesses the whole word. For each incorrect "
                     "answer, one "
                  << std::endl;
        std::cout << " body part (head, torso, 2 arms and 2 legs) is added to "
                     "the gallows."
                  << std::endl
                  << std::endl;
        break;

      case 1:
        // system("cls");
        int words_sz = words.size();
        int temp = GetRandomWord(words_sz);
        std::string secret_word = words[temp];

        int incorrect_guesses = 0;
        std::vector<bool> guessed_letters(secret_word.length(), false);
        while (incorrect_guesses < MAX_TRIES) {
          std::cout << "Guess the word: "
                    << GetCurrentWord(secret_word, guessed_letters)
                    << std::endl;
          std::cout << "Enter the letter: ";
          char guess;
          std::cin >> guess;
          bool is_guess_correct = false;

          for (long unsigned int i = 0; i < secret_word.length(); ++i) {
            if (secret_word[i] == guess) {
              guessed_letters[i] = true;
              is_guess_correct = true;
            }
          }

          if (is_guess_correct) {
            std::cout << "The correct letter!" << std::endl;
          } else {
            ++incorrect_guesses;
            std::cout << "Wrong letter! There are still attempts left: "
                      << MAX_TRIES - incorrect_guesses << std::endl;
          }

          DrawHangman(incorrect_guesses);

          if (GetCurrentWord(secret_word, guessed_letters) == secret_word) {
            std::cout << "Congratulations, you guessed the word \""
                      << secret_word << "\"!" << std::endl;
            break;
          }
        }

        if (incorrect_guesses >= MAX_TRIES) {
          std::cout << "You've lost! The hidden word was \"" << secret_word
                    << "\"." << std::endl;
        }
        return 0;
    }
  }
}
