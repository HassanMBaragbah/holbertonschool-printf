#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Structure to map specifiers with printing functions
 * @spec: The conversion specifier (e.g., 'c', 's')
 * @f: Pointer to the corresponding function
 */
typedef struct specifier
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int (*get_spec_func(char spec))(va_list);

#endif /* MAIN_H */