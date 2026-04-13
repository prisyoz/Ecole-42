#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif 

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup_extract(const char *src);
char	*ft_substr_remain(const char *s);
char	*read_store(int fd, char *storage);
char	*get_next_line(int fd);

#endif
