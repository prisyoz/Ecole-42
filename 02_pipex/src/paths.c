/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:32:14 by pang              #+#    #+#             */
/*   Updated: 2025/08/30 17:46:06 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**env_path(char **envp)
{
	char	**ev;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	ev = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path != NULL)
		ev = ft_split(path, ':');
	return (ev);
}

// single cmd
char	*single_path(char *cmd, char **envp)
{
	char	**env;
	char	*full_path;
	int		i;

	i = 0;
	env = env_path(envp);
	if (env != NULL)
	{
		while (env[i] != NULL)
		{
			full_path = ft_3join(env[i], "/", cmd);
			if (full_path && access(full_path, X_OK) == 0)
			{
				free_arr(env);
				return (full_path);
			}
			free(full_path);
			i++;
		}
		free_arr(env);
	}
	return (NULL);
}

char	*path_access(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (cmd);
	return (NULL);
}

char	**check_av_access(char **av, char **envp)
{
	char	*path;

	if (ft_strchr(av[0], '/') != NULL)
	{
		if (access(av[0], X_OK) == 0)
			return (av);
		else
		{
			free_arr(av);
			return (NULL);
		}
	}
	else
	{
		path = single_path(av[0], envp);
		if (!path)
		{
			free_arr(av);
			return (NULL);
		}
		free(av[0]);
		av[0] = path;
		return (av);
	}
}

char	**execute_check(char *cmd, char **envp)
{
	char	**av;

	while (*cmd == ' ' || (*cmd >= 9 && *cmd <= 13))
		cmd++;
	av = parse_command(cmd);
	if (!av || !av[0])
	{
		if (av)
			free_arr(av);
		return (NULL);
	}
	return (check_av_access(av, envp));
}
