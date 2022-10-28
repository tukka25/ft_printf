#include "libftprintf.h"

int	add(char* num_args, ...)
{
	int i;
	int x;
	int	g;
	va_list	args;

	va_start(args, num_args);
	g = va_arg(args, int);
	i = 0;
	if (i == 0)
	{
		
	}
	va_end(args);
	return (0);
}

int main()
{
	char c = 't';

	add("%c",c);
	// ft_putchar(c);
}