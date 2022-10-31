/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:59:04 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/31 20:05:38 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int 	i;
	int		x;
	va_list	args;

	va_start(args, str);
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		// while (str[i] == ' ' || )
		if (str[i] != '%')
			x += ft_putstr((char *)str);
		else if (str[i] == '%')
		{
			// printf("before :%d\n", i);
			i++;
			if (str[i] == '\n')
				write (1, "\n", 1);
			if (str[i] == 'c')
			{
				x += ft_putchar(va_arg(args, int));
			}
			else if (str[i] == 's')
			{
				x += ft_putstr(va_arg(args, char *));
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				x += ft_putnbr(va_arg(args, int));
			}
			else if (str[i] == 'x' || str[i] == 'X')
			{
				if (str[i] == 'X')
					x += hexa_upper(va_arg(args, int));
				else
					x += hexa_lower(va_arg(args, int));
			}
			else if (str[i] == 'u')
			{
				x += ft_uputnbr(va_arg(args, int));
			}
			else if (str[i] == 'p')
			{
				x += printingaddress(va_arg(args, size_t));
			}
			//i++;
			// printf("\n%d", i);
		}
		else
			x += ft_putchar(va_arg(args, int));
		// printf("\nafter :%d\n", i);
		i++;
	}
	//printf("\n 3 :%d", i);
	va_end(args);
	return (x);
}
int main()
{
	char c[] = "tukkatydyjdghd";
	int i = 6;
	int m;
	int n;
	
	m = printf("%s %d", c, i);
	printf("\n");
	n = ft_printf("%s %d", c, i);
	// n = printf("\n%c %d\n", 'j', i);
	printf("\nmine : %d  printf : %d \n", n, m);
	// ft_printf("%x", i);
}