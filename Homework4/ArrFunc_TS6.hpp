#pragma once
#include <iostream>

void rInitArray(int *const array_begin, int const *const array_end);
void fInitArray(int *const array_begin, int const *const array_end);
void uInitArray(int *const array_begin, int const *const array_end);
void ShowArray(int *const array_begin, int const *const array_end);

const size_t k_int_array_size{10'000};
const int k_min_random_value{10};
const int k_max_random_value{99};
const char k_file_name[]{"Taras_Samchuk_HW4_Task_1.txt"};