#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

/**
* struct convert - struct for symbols and functions
*
*@sym: the format symbol
*@f: the function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int (*prntfunc(char x))(va_list);
int print_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_p(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_reversed(va_list args);
int rot13(va_list args);
int (*get_func(char x))(va_list);

unsigned int base_len(unsigned int, int);
char *rev_string(char *);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsigned_number(unsigned int n);
void write_base(char *str);

#endif
