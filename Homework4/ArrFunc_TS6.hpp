#pragma once
#include <iostream>

void rundomInitArray(int *const array_begin, int const *const array_end);
void fileInitArray(int *const array_begin, int const *const array_end);
void userInitArray(int *const array_begin, int const *const array_end);
void ShowArray(int *const array_begin, int const *const array_end);

static const size_t k_int_array_size{10'000};
static const int k_min_random_value{10};
static const int k_max_random_value{99};
static const char k_file_name[]{"Taras_Samchuk_HW4_Task_1.txt"};