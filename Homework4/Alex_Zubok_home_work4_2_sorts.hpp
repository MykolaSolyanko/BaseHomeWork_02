#pragma once
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>

bool More(unsigned a, unsigned b);
using Comp_unsigned = bool (*)(unsigned, unsigned);
int *user_partiotion(unsigned *begin, unsigned *end, Comp_unsigned func = More);
void qSort(unsigned *begin, unsigned *end, Comp_unsigned func = More);
void print_array(const unsigned *begin, const unsigned *const end);

using Comp_double = bool (*)(double, double);
bool More(double a, double b);
int *user_partiotion(double *begin, double *end, Comp_double func = More);
void qSort(double *begin, double *end, Comp_double func = More);
void print_array(const double *begin, const double *const end);

using Comp_char = bool (*)(char, char);
bool More(char a, char b);
int *user_partiotion(char *begin, char *end, Comp_char func = Less);
void bSort(char *begin, const char *const end, Comp_char func = Less);
void print_array(const char *begin, const char *const end);
enum user_choise { eManual = 1, eAuto };
