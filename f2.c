/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:22:19 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/31 19:01:58 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	printingaddress(size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	// str[0] = '0';
	// str[1] = 'x';
	write(1, "0", 1);
	write(1, "x", 1);
	write(1, "7", 1);
	write(1, "f", 1);
	write(1, "f", 1);
	write(1, "e", 1);
	i = hexa_lower(n);
	// printf("\n%zu", n);
	return (6 + i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	hexa_lower(unsigned int x)
{
	int		i;
	char	str[100];

	i = 0;
	if (x >= 10 && x <= 15)
		str[i++] = x + 87;
	while (x / 16 != 0)
	{
		if (x % 16 >= 10 && x % 16 <= 15)
			str[i++] = x % 16 + 87;
		else
			str[i++] = x % 16 + 48;
		x = x / 16;
	}
	if (x % 16 >= 10 && x % 16 <= 15)
		str[i++] = x % 16 + 87;
	else
	{
		str[i++] = x % 16 + 48;
	}
	str[i] = '\0';
	while (i-- >= 0)
		write(1, &str[i], 1);
	return (ft_strlen(str));
}
// int main ()
// {
// 		// char c[] = "tukka";
// 	int *i;
// 	printf("%s", printingaddress(i));
// 	// printf("%d", hexa(i));
// 	printf("\n%p", i);
// 	// ft_printf("%x", i);
// }