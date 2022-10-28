#include "libftprintf.h"

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

// char	*printingaddress(void *v)
// {
// 	// void	*p;
// 	// char	*str;

// 	// p = &v;
// 	// str = (char *)p;
// 	// write(1, str, ft_strlen(str));
// 	// return (0);
// }

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
// int main ()
// {
// 		// char c[] = "tukka";
// 	int *i;
// 	printf("%s", printingaddress(i));
// 	// printf("%d", hexa(i));
// 	printf("\n%p", i);
// 	// ft_printf("%x", i);
// }