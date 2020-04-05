#pragma once
#include <iostream>

void rundomInitArray(int *const array_begin, int const *const array_end);
void fileInitArray(int *const array_begin, int const *const array_end);
void userInitArray(int *const array_begin, int const *const array_end);
void ShowArray(int *const array_begin, int const *const array_end);

const char k_file_name[]{"Taras_Samchuk_HW4_Task_1.txt"};
const size_t k_int_array_size{10'000};