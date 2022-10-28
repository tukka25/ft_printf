/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:13:01 by abdamoha          #+#    #+#             */
/*   Updated: 2022/10/28 16:26:26 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
#include <stdlib.h>
# include <string.h>

int		ft_putchar(char c);
char	*ft_putstr(char *str);
int		ft_putnbr(int nb);
int		hexa_upper(int x);
char	*ft_itoa(int n);
int		ft_tolower(int n);
char	*ft_strcpy(char *dest, char *src);
unsigned int	ft_uputnbr(unsigned int nb);
int		hexa_lower(int x);


#endif