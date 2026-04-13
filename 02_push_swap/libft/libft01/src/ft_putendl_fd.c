#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

/* int main(void)
{
	ft_putendl_fd("Hello world!", 1); // prints "Hello world!\n"
	ft_putendl_fd("", 1);             // just prints a newline
	ft_putendl_fd(NULL, 1);           // does nothing
	ft_putendl_fd("Hello world!", 1);
	return 0;
} */
