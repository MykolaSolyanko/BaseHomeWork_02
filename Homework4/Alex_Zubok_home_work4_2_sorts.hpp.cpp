#pragma once
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>

using Comp_int = bool (*)(int, int);
bool More(int a, int b);
bool Less(int a, int b);
int *user_partiotion(int *begin, int *end, Comp_int func = More);
void qSort(int *begin, int *end, Comp_int func = More);
void print_array(const int *begin, const int *const end);

using Comp_unsigned = bool (*)(unsigned, unsigned);
bool More(unsigned a, unsigned b);
bool Less(unsigned a, unsigned b);
int *user_partiotion(unsigned *begin, unsigned *end, Comp_unsigned func = More);
void qSort(unsigned *begin, unsigned *end, Comp_unsigned func = More);
void print_array(const unsigned *begin, const unsigned *const end);

using Comp_double = bool (*)(double, double);
bool More(double a, double b);
bool Less(double a, double b);
int *user_partiotion(double *begin, double *end, Comp_double func = More);
void qSort(double *begin, double *end, Comp_double func = More);
void print_array(const double *begin, const double *const end);

using Comp_char = bool (*)(char, char);
bool More(char a, char b);
bool Less(char a, char b);
int *user_partiotion(char *begin, char *end, Comp_char func = Less);
void bSort(char *begin, char *end, Comp_char func = Less);
void print_array(const char *begin, const char *const end);
