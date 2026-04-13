#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

/* #include <string.h>
#include <stdio.h>

 int	main(void)
{
	printf("%ld\n", strlen("Into the new world!"));
	printf("%d\n", ft_strlen("Into the new world!"));
	printf("%ld\n", strlen("Into\nthe new world!  "));
	printf("%d\n", ft_strlen("Into\nthe n3w w0rld!  "));
	printf("%ld\n", strlen(""));
	printf("%d\n", ft_strlen(""));
} */