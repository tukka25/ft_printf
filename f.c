/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:21:22 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/28 16:27:38 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
			i++;
	}
	return (str);
}

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	//  return (x);
}

int	ft_tolower(int n)
{
	if (n >= 'A' && n <= 'Z')
	{
		return (n + 32);
	}
	return (n);
}

unsigned int	ft_uputnbr(unsigned int nb)
{
	unsigned int	n;
	
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');

}
// int main()
// {
// 	int i = 5654;

// 	printf("%d\n", ft_putnbr(i));
// 	printf("%d", i);
// }

// 2147483647
// 4294967295