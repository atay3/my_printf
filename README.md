# Welcome to My Printf
***

## Task
Create a function, my_printf, that produces an output similar to the printf function in C. The function should write output to stdout under the control of a format string that specifies how subsequent arguments are converted for output. Each conversion specification is ontroduced by the percent character and the arguments should correspond properly with the conversion specifier.

This function should be able to handle the following:
- signed decimal (%d)
- unsigned octal (%o)
- unsigned decimal (%u)
- unsigned hexxadecimal (%x)
- characters (%c)
- strings (%s)
- pointers (%p) where the void* pointer argument is printed in hexadecimal

## Description
The my_printf function is a custom implementation inspired by the standard printf function in the C programming language. It allows users to format and output data to the standard output stream (stdout) according to a specified format string.

Utilizes the va_list to hold the variable arguments passed to the function and va_arg to initialize the va_list with the arguments. This enables my_printf to support a variable number of arguments based on the format string. Then a pointer is used to iterate through the format string to search for a format specifier and call the correct helper function to perform the operations related to the specifier and print the desired output. The number of characters printed by my_printf is counted and returned.

The implementation includes several helper functions, each responsible for handling a specific conversion specifier:

put_decimal: Handles signed decimal integers (%d).
put_unsigned_dec: Handles unsigned decimal integers (%u).
put_octal: Handles unsigned octal integers (%o).
put_hexadecimal: Handles unsigned hexadecimal integers (%x).
put_char: Handles single characters (%c).
put_str: Handles null-terminated strings (%s).
put_ptr: Handles pointers (%p), printing their hexadecimal representation.

The helper functions implement basic error handling mechanisms to handle edge cases and invalid input format strings.

Currently, my_printf supports a subset of the conversion specifiers available in the standard printf function.

## Installation
Users can compile the program using the provided Makefile. Once the repository is cloned, navigate to the project directory and run the following command:
```
make
```

To remove the compiled executable and object files use the following:
```
make clean
```

To completely clean the project directory, removing all compiled files and the executable, use the following:
```
make fclean
```

To recompile the program from scratch after making changes to the source code use the following:
```
make re
```

## Usage
You can clone the project repository from GitHub using the following command:
```
git clone https://github.com/atay3/my_printf.git
```

The my_printf function can be used like printf in users' code. The format for this is:
```
my_printf("%format_specifier", arg);
```
Where the format specifier is one of d, o, u, x, c, s, or p and the corresponding argument can be int (or an appropriate variant), char*, or pointer.

After compiling the code, run it by using:
```
./my_printf
```



### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
