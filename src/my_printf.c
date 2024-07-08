#include "my_printf.h"
#include <string.h>

int my_printf(char * restrict format, ...) {
    
    va_list args; //holds the variable arguments
    
    va_start(args, format); //initializes the va_list

    char* ptr = format;
    int num_chars = 0;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr = find_specification(ptr, args, &num_chars);
        }
        else {
            write(1, ptr, 1);
            ptr++;
            num_chars++;
        }
    }
    
    va_end(args);

    return num_chars;
}

char* find_specification(char* ptr, va_list args, int* num_chars) {
    switch(*(ptr+1)) {
        case 'd': 
            put_decimal(va_arg(args, int), num_chars);
            break;
        case 'o':
            put_octal(va_arg(args, int), num_chars);
            break;
        case 'u':
            put_unsigned_dec(va_arg(args, unsigned int), num_chars);
            break;
        case 'x':
            put_hexadecimal(va_arg(args, int), num_chars);
            break;
        case 'c' :
            put_char((char) va_arg(args, int), num_chars);           
            break;
        case 's':
            put_str(va_arg(args, char*), num_chars);
            break;
        case 'p':
            put_ptr(va_arg(args, void*), num_chars);
            break;
    }
    
    return ptr+2;
}

void put_decimal(int d, int* num_chars) {
    if (d < 0) {
        char minus = '-';
        write(1, &minus, 1);
        (*num_chars)++;
        d = -d; //convert to positive number
    }

    put_unsigned_dec(d, num_chars);
}

void put_unsigned_dec(unsigned int u, int* num_chars) {
    int divisor = 1;

    //finds highest place value
    while (u / divisor > 9) {
        divisor *= 10;
    }
    
    while (divisor > 0) {
        char digit = (u / divisor) + '0'; //convert to ASCII representation
        write(1, &digit, 1);
        //goes down one place value to print next digit
        u %= divisor;
        divisor /= 10;
        (*num_chars)++;
    }
}

void put_octal(int o, int *num_chars) {
    int divisor = 8;
    int index = 0, size = 1;
    int* arr = (int*) malloc(size * sizeof(int));

    while (o != 0) {
        //convert from decimal to octal
        arr[index++] = o % divisor;
        o /= divisor;

        //resize array
        if (index >= size) {
            size *= 2;
            arr = (int*) realloc(arr, size * sizeof(int));
        }
    }

    //print octal digits in reverse order
    for (int i = index - 1; i >= 0; i--) {
        char digit = arr[i] + '0';
        write(1, &digit, 1);
        (*num_chars)++;
    }
    
    free(arr);
}

void put_hexadecimal(int x, int* num_chars) {
    int divisor = 16;
    int index = 0, size = 1;
    char* arr = (char*) malloc(size * sizeof(char));

    while (x != 0) {
        int temp = x % divisor;

        if (temp < 10) {
            temp += 48; //ASCII for '0' to '9'
        }
        else if (x == 'x') {
            temp += 87; //ASCII for 'a' to 'f'
        }
        else {
            temp += 55; //ASCII for 'A' to 'F'
        }

        if (index >= size) {
            size *= 2;
            arr = (char*) realloc(arr, size * sizeof(char));
        }

        arr[index++] = temp;
        x /= divisor;
    }
    
    for (int i = index - 1; i >= 0; i--) {
        write(1, &arr[i], 1);
        (*num_chars)++;
    }

    free(arr);
}

void put_char(char c, int* num_chars) {
    write(1, &c, 1);
    (*num_chars)++;
}

void put_str(char *s, int *num_chars) {
    if (s == NULL) {
        char* null_msg = "(null)";
        int length = strlen(null_msg);
        write(1, null_msg, length);
        (*num_chars) += length;
    }
    else {
        int length = strlen(s);
        write(1, s, length);
        *num_chars += length;
    }
}

void put_ptr(void* ptr, int* num_chars) {
    char* hex_num = "0123456789abcdef"; //stores hexadecimal digits
    uintptr_t buf = (uintptr_t) ptr;

    char* prefix = "0x";
    int length = strlen(prefix);
    write(1, prefix, length);
    (*num_chars) += length;

    int non_zero_found = 0; //tracks if nonzero digits are encountered
    size_t num_hex_digits = sizeof(buf) * 2;

    for (size_t i = 0; i < num_hex_digits; i++) {
        int shift = (num_hex_digits - i - 1) * 4;
        int nibble = (buf >> shift) & 0xf;

        if (non_zero_found || nibble != 0) {
            non_zero_found = 1;
            write(1, &hex_num[nibble], 1); //writes current hex digit represented by nibble
            (*num_chars)++;
        }
    }

    if (!non_zero_found) {
        write(1, &hex_num[0], 1);
        (*num_chars)++;
    }
}

//needs to be recompiled with tests uncommented to run the tests
int main() {
    // int a = 10;
    // int* p = &a;

    // printf("TESTING POINTER \n---------------------\n\n");
    // printf("\nmy_printf: test_01\n");
    // int test_01 = my_printf("%p\n", p);
    // printf("Amount of characters printed is %d\n\n", test_01);

    // printf("printf: test_01\n");
    // int test_01_printf = printf("%p\n", p);
    // printf("Amount of characters printed is %d\n\n", test_01_printf);

    return 0;

}
