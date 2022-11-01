/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:59:04 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/01 12:28:59 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	va_list	args;

	va_start(args, str);
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] != '%')
			x += ft_putchar(str[i]);
		else if (str[i] == '%')
		{
			i++;
			x += check_after_percent(str[i], args);
		}
		else
			x += ft_putchar(va_arg(args, int));
		i++;
	}
	va_end(args);
	return (x);
}

int	check_after_percent(char s, va_list args)
{
	int		x;

	x = 0;
	if (s == '%')
		x += ft_putchar('%');
	else if (s == '\n')
		write (1, "\n", 1);
	else if (s == 'c')
		x += ft_putchar(va_arg(args, int));
	else if (s == 's')
		x += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		x += ft_putnbr(va_arg(args, int));
	else if (s == 'x')
		x += hexa_lower(va_arg(args, int));
	else if (s == 'X')
		x += hexa_upper(va_arg(args, int));
	else if (s == 'u')
		x += ft_uputnbr(va_arg(args, int));
	else if (s == 'p')
		x += printingaddress(va_arg(args, size_t));
	return (x);
}
// int main(int ac, char **av)
// {
// 	char c[] = "tukkatydyjdghd";
// 	int i = 7536;
// 	int m;
// 	int n;

// 	m = printf("%s", c);
// 	printf("\n");
// 	n = ft_printf("%s", c);
// 	//  n = printf("\, n%c %d\n", 'j', i);
// 	printf("\nmine : %d  printf : %d \n", n, m);
// 	// ft_printf("%x", i);
// }