#pragma once
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>

bool More(int a, int b) { return a > b; }
using Comp = decltype(&More);
void bSort(int *begin, int *end, Comp func = More);
int *user_partiotion(int *begin, int *end, Comp func = More);
void qSort(int *begin, int *end, Comp func = More);
void print_array(const int *begin, const int *const end);

enum use_choise { eManual = 1, eAuto };
