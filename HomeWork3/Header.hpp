#pragma once

char *alloc_char_array(size_t kSize);
size_t length_char_array(char *array);
void CharArrayReverse(char *array, int size);
void PrintCharArray(char *array, int size);
void PrintUpperCaseCharArray(char *array, int size);
void PrintLowerCaseCharArray(char *array, int size);
void is_digit(char *array, int size);

void PartialSortElemArray(int *array, int size);
void PrintIntArray(int *array, int size);
void FillAndSortIntArray(int *array, int size);
void FillIntArrDefault(int *array, int size);
void FillIntArrRandom(int *array, int size);
void FillIntArrCustom(int *array, int size);
void FillingIntArray(int *array, int size);
void DeleteElemArray(int *array, int &size);
