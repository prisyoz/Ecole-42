/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_argumentcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:10:11 by pang              #+#    #+#             */
/*   Updated: 2025/09/10 20:28:14 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_quoted_arg(const char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len >= 2)
	{
		if ((arg[0] == '"' && arg[len - 1] == '"')
			|| (arg[0] == '\'' && arg[len - 1] == '\''))
			return (1);
	}
	return (0);
}

static char	*process_argument(char *arg)
{
	if (is_quoted_arg(arg))
		return (ft_strtrim(arg, "\"'"));
	return (ft_strdup(arg));
}

static char	*append_arg(char *combined, char *arg)
{
	char	*trimmed;
	char	*temp;

	trimmed = process_argument(arg);
	if (!trimmed)
	{
		free(combined);
		return (NULL);
	}
	temp = ft_strjoin(combined, trimmed);
	free(trimmed);
	free(combined);
	if (!temp)
		return (NULL);
	combined = ft_strjoin(temp, " ");
	free(temp);
	if (!combined)
		return (NULL);
	return (combined);
}

char	*argument_to_array(int argc, char **argv)
{
	char	*combined_str;
	int		index;

	combined_str = ft_strdup("");
	if (!combined_str)
		return (NULL);
	index = 1;
	while (index < argc)
	{
		combined_str = append_arg(combined_str, argv[index]);
		if (!combined_str)
			return (NULL);
		index++;
	}
	return (combined_str);
}
