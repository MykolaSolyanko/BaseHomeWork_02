#pragma once
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

void encrypt_string(char *encript_string);
void decrypt_string(char *decript_string, const size_t key = 0);
