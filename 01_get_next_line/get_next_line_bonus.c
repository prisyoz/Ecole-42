#include "get_next_line_bonus.h"

char	*read_store(int fd, char *storage)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	if (BUFFER_SIZE == 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(storage, buffer);
		free(storage);
		storage = tmp;
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;
	char		*temp;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_store(fd, storage[fd]);
	if (!storage[fd] || !*storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = ft_strdup_extract(storage[fd]);
	temp = storage[fd];
	storage[fd] = ft_substr_remain(temp);
	free(temp);
	return (line);
}
