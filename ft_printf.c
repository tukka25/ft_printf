/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:59:04 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/28 21:51:02 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int i;
	unsigned int	j;
	int x;
	char *g;
	va_list	args;

	va_start(args, str);
	i = 0;
	// j = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				x += ft_putchar(va_arg(args, int));
				return (x);
			}
			else if (str[i] == 's')
			{
				g = ft_putstr(va_arg(args, char *));
				return ((int)g);
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				x += ft_putnbr(va_arg(args, int));
				return (x);
			}
			else if (str[i] == 'p')
			{
				g = ((va_arg(args, char *)));
				return (((int)g));
			}
			else if (str[i] == 'x' || str[i] == 'X')
			{
				if (str[i] == 'X')
				{
					x = va_arg(args, int);
					// if (x < 0)
					// {
					// 	x = ft_uputnbr(x);
					// 	return (hexa_upper(x));
					// }
					return (hexa_upper(x));
				}
				else
				{
					x = va_arg(args, int);
					return (hexa_lower(x));
				}
			}
			else if (str[i] == 'u')
			{
				j = va_arg(args, int);
				return (ft_uputnbr(j));
			}
			// else if (str[i] == 'p')
			// {
			// 	g = va_arg(args, char *);
			// 	return ((int )printingaddress(g));
			// }
		}
		i++;
	}
	va_end(args);
	return (x);
}

int	hexa_upper(unsigned int x)
{
	int		i;
	int		j;
	char	str[100];

	i = 0;
	j = 0;
	if (x >= 10 && x <= 15)
	{
		str[i] = x + 55;
		i++;
		str[i] = '\0';
		 return (*str);
	}
	while (x / 16 != 0)
	{
		if (x % 16 >= 10 && x % 16 <= 15)
		{
			str[i] = x % 16 + 55;
			i++;
			j++;
		}
		else
		{
			str[i] = x % 16 + 48;
			i++;
			j++;
		}
		x = x / 16;
	}
	if (x % 16 >= 10 && x % 16 <= 15)
	{
		str[i] = x % 16 + 55;
		i++;
		j++;
	}
	else
	{
		str[i] = x % 16 + 48;
		i++;
		x = x / 16;
	}
	str[i] = '\0';
	while (j >= 0)
	{
		write(1, &str[j], 1);
		j--;
	}
	return (*str);
}

int	hexa_lower(unsigned int x)
{
	int		i;
	int		j;
	char	str[100];

	i = 0;
	j = 0;
	if (x >= 10 && x <= 15)
	{
		str[i] = x + 87;
		i++;
		str[i] = '\0';
		 return (*str);
	}
	while (x / 16 != 0)
	{
		if (x % 16 >= 10 && x % 16 <= 15)
		{
			str[i] = x % 16 + 87;
			i++;
			j++;
		}
		else
		{
			str[i] = x % 16 + 48;
			i++;
			j++;
		}
		x = x / 16;
	}
	if (x % 16 >= 10 && x % 16 <= 15)
	{
		str[i] = x % 16 + 87;
		i++;
		j++;
	}
	else
	{
		str[i] = x % 16 + 48;
		i++;
		x = x / 16;
	}
	str[i] = '\0';
	while (j >= 0)
	{
		write(1, &str[j], 1);
		j--;
	}
	 return (*str);
}
// int main()
// {
// 	// char c[] = "tukka";
// 	int i = 8;
// 	ft_printf("%p", i);
// 	// printf("%d", hexa(i));
// 	printf("\n%p", i);
// 	// ft_printf("%x", i);
// }