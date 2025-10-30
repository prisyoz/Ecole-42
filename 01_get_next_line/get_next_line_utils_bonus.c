/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:12:11 by pang              #+#    #+#             */
/*   Updated: 2025/06/15 14:48:20 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] != '\0')
	{
		if (str[count] == (char)c)
			return ((char *)str + count);
		count++;
	}
	if ((char)c == '\0')
		return ((char *)str + count);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		count;
	int		scount;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	count = 0;
	scount = 0;
	result = malloc(ft_strlen((char *)s1) + (ft_strlen((char *)s2)) + 1);
	if (!result)
		return (NULL);
	while (s1[count] != '\0')
	{
		result[count] = s1[count];
		count++;
	}
	while (s2[scount] != '\0')
		result[count++] = s2[scount++];
	result[count] = '\0';
	return (result);
}

char	*ft_strdup_extract(const char *src)
{
	char	*dest;
	int		count;
	int		dcount;

	if (!src || !*src)
		return (NULL);
	count = 0;
	dcount = 0;
	while (src[count] != '\0' && src[count] != '\n')
		count++;
	if (src[count] == '\n')
		count++;
	dest = malloc(count + 1);
	if (!dest)
		return (NULL);
	while (dcount < count)
	{
		dest[dcount] = src[dcount];
		dcount++;
	}
	dest[dcount] = '\0';
	return (dest);
}

char	*ft_substr_remain(const char *str)
{
	size_t	count;
	size_t	rcount;
	char	*result;

	if (!str)
		return (NULL);
	count = 0;
	rcount = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	if (str[count] == '\0')
		return (NULL);
	count++;
	result = malloc((ft_strlen((char *)str) + count) + 1);
	if (!result)
		return (NULL);
	while (str[count] != '\0')
	{
		result[rcount] = str[count];
		rcount++;
		count++;
	}
	result[rcount] = '\0';
	return (result);
}
