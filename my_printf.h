#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char* find_specification(char* ptr, va_list args, int* num_chars);
void put_decimal(int d, int* num_chars);
void put_octal(int o, int* num_chars);
void put_unsigned_dec(unsigned int u, int* num_chars);
void put_hexadecimal(int x, int* num_chars);
void put_char(char c, int* num_chars);
void put_str(char* s, int* num_chars);
void put_ptr(void* ptr, int* num_chars);
void put_hex_prefix(int* num_chars);