#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		src_count;

	if (!src)
		return (NULL);
	src_count = ft_strlen(src) + 1;
	dest = malloc(src_count);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, src_count);
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	*dest1;
	char	*dest2;

	dest1 = strdup("123+adfas");
	dest2 = ft_strdup("123+adfas");

	printf("strdup: %s\n", dest1);
	printf("ft_strdup: %s\n", dest2);
	free(dest1);
	free(dest2);
} */