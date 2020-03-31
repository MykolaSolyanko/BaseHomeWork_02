#pragma once
#include <iostream>
#include <random>
#include <cstring>
#include <chrono>

using Comp = bool (*) (int, int);
bool More(int a, int b);
bool Less(int a, int b);
void bSort(int* begin, const int* const end, Comp func = More);
int* user_partiotion (int* begin, int * end, Comp func = More);
void qSort(int* begin, int* end, Comp func = More);
void print_array(const int* begin, const int* const end);
