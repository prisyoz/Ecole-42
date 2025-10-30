/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:35:10 by pang              #+#    #+#             */
/*   Updated: 2025/08/30 17:52:02 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *str)
{
	int		count;
	int		word_count;
	char	**result;
	int		index;

	count = 0;
	index = 0;
	word_count = words_count(str);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	count = skip_whitespace(str, count);
	while (str[count] && index < word_count)
	{
		result[index] = extract_word(str, &count);
		if (!result[index])
		{
			free_all(result, index);
			return (NULL);
		}
		index++;
		count = skip_whitespace(str, count);
	}
	result[index] = NULL;
	return (result);
}

/* void test_parsing() 
{
    char **result = parse_command("awk '{print $2}'");
    printf("TEST PARSE RESULT:\n");
    if (result) {
        for (int i = 0; result[i]; i++) {
            printf("  [%d]: '%s'\n", i, result[i]);
        }
        free_arr(result);
    } else {
        printf("  PARSE FAILED\n");
    }
} */

/* void debug_parse_result(char **result)
{
    int i = 0;
    printf("PARSE RESULT:\n");
    while (result && result[i])
    {
        printf("  [%d]: '%s'\n", i, result[i]);
        i++;
    }
} */
