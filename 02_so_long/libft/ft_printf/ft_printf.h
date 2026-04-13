#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "../libft01/libft.h"

int		print_add(va_list args);
int		print_char(va_list args);
int		print_str(va_list args);
int		hex_len(unsigned int n);
int		print_hex(va_list args);
int		print_upphex(va_list args);
int		print_nbr(va_list args);
int		print_unsign(va_list args);
int		ft_printf(const char *format, ...);
void	convert_hex(unsigned int nb);
void	convert_upphex(unsigned int nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
