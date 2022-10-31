/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:59:04 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/31 23:12:30 by abdamoha         ###   ########.fr       */
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
			if (str[i] == '%')
				x += ft_putchar('%');
			else if (str[i] == '\n')
				write (1, "\n", 1);
			else if (str[i] == 'c')
				x += ft_putchar(va_arg(args, int));
			else if (str[i] == 's')
				x += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd' || str[i] == 'i')
				x += ft_putnbr(va_arg(args, int));
			else if (str[i] == 'x')
				x += hexa_lower(va_arg(args, int));
			else if (str[i] == 'X')
				x += hexa_upper(va_arg(args, int));
			else if (str[i] == 'u')
				x += ft_uputnbr(va_arg(args, int));
			else if (str[i] == 'p')
				x += printingaddress(va_arg(args, size_t));
		}
		else
			x += ft_putchar(va_arg(args, int));
		i++;
	}
	va_end(args);
	return (x);
}
// int main(int ac, char **av)
// {
// 	char c[] = "tukkatydyjdghd";
// 	int i = 7536;
// 	int m;
// 	int n;

// 	m = printf("%c", 127);
// 	printf("\n");
// 	n = ft_printf("%c", 127);
// 	//  n = printf("\, n%c %d\n", 'j', i);
// 	printf("\nmine : %d  printf : %d \n", n, m);
// 	// ft_printf("%x", i);
// }