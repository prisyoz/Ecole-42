/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:10:04 by pang              #+#    #+#             */
/*   Updated: 2025/09/24 19:31:13 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status1;
	int		status2;

	if (argc != 5)
	{
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(EXIT_FAILURE);
	}
	init_pipes(&pipex, argv);
	fork_processes(&pipex, argv, envp);
	close_pipes(&pipex);
	if (pipex.infile != -1)
		close(pipex.infile);
	close(pipex.outfile);
	waitpid(pipex.pid1, &status1, 0);
	waitpid(pipex.pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else
		return (1);
}
