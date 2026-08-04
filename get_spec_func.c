#include "main.h"

/**
 * get_spec_func - Selects the correct function to perform the operation
 * @spec: The specifier character
 * Return: Pointer to the function or NULL
 */
int (*get_spec_func(char spec))(va_list)
{
	spec_t specs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].spec != NULL)
	{
		if (specs[i].spec[0] == spec)
			return (specs[i].f);
		i++;
	}
	return (NULL);
}