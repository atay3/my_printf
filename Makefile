CC=gcc
CFLAGS=-Wall -Wextra -Werror 
DEPS = my_printf.h
TARGET = my_printf
OBJ = my_printf.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

my_printf: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)