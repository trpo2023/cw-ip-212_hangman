#pragma once

#include <string>
#include <vector>

std::string GetCurrentWord(std::string secret_word,
                           const std::vector<bool>& guessed_letters);