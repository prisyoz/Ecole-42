/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_split_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:35:10 by pang              #+#    #+#             */
/*   Updated: 2025/09/16 13:53:07 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	skip_quote(char *str, int count)
{
	char	quote;

	quote = str[count++];
	while (str[count] && str[count] != quote)
		count++;
	if (str[count])
		count++;
	return (count);
}

int	words_count(char *str)
{
	int		word;
	int		count;

	word = 0;
	count = 0;
	while (str[count])
	{
		count = skip_whitespace(str, count);
		if (!str[count])
			break ;
		if (str[count] == '\'' || str[count] == '"')
			count = skip_quote(str, count);
		else
		{
			while (str[count] && (!is_whitespace(str[count])
					&& str[count] != '\'' && str[count] != '"'))
				count++;
		}
		word++;
		count = skip_whitespace(str, count);
	}
	return (word);
}

char	*extract_quoted_word(char *str, int *count)
{
	int		start;
	int		len;
	char	quote;

	len = 0;
	quote = str[(*count)++];
	start = *count;
	while (str[*count] && str[*count] != quote)
	{
		(*count)++;
		len++;
	}
	if (!str[*count])
		return (NULL);
	(*count)++;
	return (malloc_word(&str[start], len));
}

char	*extract_unquoted_word(char *str, int *count)
{
	int		start;
	int		len;

	len = 0;
	start = *count;
	while (str[*count] && !is_whitespace(str[*count])
		&& str[*count] != '\'' && str[*count] != '"')
	{
		(*count)++;
		len++;
	}
	return (malloc_word(&str[start], len));
}

char	*extract_word(char *str, int *count)
{
	if (str[*count] == '\'' || str[*count] == '"')
		return (extract_quoted_word(str, count));
	else
		return (extract_unquoted_word(str, count));
}
