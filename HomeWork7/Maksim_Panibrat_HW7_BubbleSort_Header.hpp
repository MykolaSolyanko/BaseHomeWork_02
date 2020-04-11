#pragma once
#include <functional>
#include <iostream>
#include <random>

using Comparison = std::function<bool(int, int)>;

enum SELECT_TYPE { WHOLE = 1, FRACTIONAL, LETTERS };

enum SELECT_WHOLE { SHORT = 1, INT, LONG };

enum SELECT_FRACTIONAL { FLOAT = 1, DOUBLE };

enum SELECT_CHAR { UPPER = 0, LOWER = 1 };

enum SELECT_SIDE { LEFT = 1, RIGHT };

void Create_whole();
void Create_fractional();
void Create_char();
