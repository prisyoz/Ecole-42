#include "pipex.h"

void	exit_error(char *msg, t_pipex *pipex)
{
	perror(msg);
	close(pipex->infile);
	close(pipex->outfile);
	exit(EXIT_FAILURE);
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	skip_whitespace(char *str, int count)
{
	while (str[count] && (is_whitespace(str[count])))
		count++;
	return (count);
}

char	*ft_3join(char const *s1, char const *s2, char const *s3)
{
	char	*temp;
	char	*result;

	if (!s1 || !s2 || !s3)
		return (NULL);
	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, s3);
	free(temp);
	return (result);
}

void	free_arr(char **arr)
{
	int	index;

	index = 0;
	if (arr == NULL)
		return ;
	while (arr[index])
	{
		free(arr[index]);
		arr[index] = NULL;
		index++;
	}
	free(arr);
	arr = NULL;
}
